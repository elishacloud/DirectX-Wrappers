/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "d3d8.h"

std::ofstream LOG;

Direct3DCreate8Proc m_pDirect3DCreate8;

bool WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	static HMODULE d3d8dll = nullptr;

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		LOG.open("d3d8.log", std::ios::trunc);
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\d3d8.dll");
		LOG << "Loading " << path << "\n";
		d3d8dll = LoadLibraryA(path);
		m_pDirect3DCreate8 = (Direct3DCreate8Proc)GetProcAddress(d3d8dll, "Direct3DCreate8");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(d3d8dll);
		LOG.flush();
		break;
	}

	return true;
}

void logf(char * fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	static constexpr DWORD BuffSize = 250;
	static char buffer[BuffSize];
	sprintf_s(buffer, fmt, ap);
	LOG << buffer;
}

IDirect3D8 *WINAPI m_Direct3DCreate8(UINT SDKVersion)
{
	return new m_IDirect3D8(m_pDirect3DCreate8(SDKVersion));
}
