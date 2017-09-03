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
*
* Code taken from code found here: https://github.com/JeremyAnsel/xwa_hooks/tree/master/DInputLogger
*/

#include "dinput.h"

std::ofstream Log::LOG("dinput.log");

DirectInputCreateAProc m_pDirectInputCreateA;
DirectInputCreateExProc m_pDirectInputCreateEx;
DirectInputCreateWProc m_pDirectInputCreateW;

bool WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	static HMODULE dinputdll = nullptr;

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\dinput.dll");
		Log() << "Loading " << path;
		dinputdll = LoadLibraryA(path);
		m_pDirectInputCreateA = (DirectInputCreateAProc)GetProcAddress(dinputdll, "DirectInputCreateA");
		m_pDirectInputCreateEx = (DirectInputCreateExProc)GetProcAddress(dinputdll, "DirectInputCreateEx");
		m_pDirectInputCreateW = (DirectInputCreateWProc)GetProcAddress(dinputdll, "DirectInputCreateW");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(dinputdll);
		break;
	}

	return true;
}

void logf(char * fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	auto size = vsnprintf(nullptr, 0, fmt, ap);
	std::string output(size + 1, '\0');
	vsprintf_s(&output[0], size + 1, fmt, ap);
	Log() << output.c_str();
	va_end(ap);
}

extern "C" HRESULT WINAPI DirectInputCreateA(HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA* lplpDirectInput, LPUNKNOWN punkOuter)
{
	HRESULT hr = m_pDirectInputCreateA(hinst, dwVersion, lplpDirectInput, punkOuter);
	if (SUCCEEDED(hr))
	{
		LPDIRECTINPUTA* temp = lplpDirectInput;
		*lplpDirectInput = new m_DirectInputA(*temp);
		delete temp;
	}
	Log() << __FUNCTION__ << " " << (void*)dwVersion << "\t" << hr;
	return hr;
}

extern "C" HRESULT WINAPI DirectInputCreateEx(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter)
{
	HRESULT hr = m_pDirectInputCreateEx(hinst, dwVersion, riidltf, ppvOut, punkOuter);
	Log() << __FUNCTION__ << " " << (void*)dwVersion << " " << "\t" << hr;
	if (SUCCEEDED(hr))
	{
		//TODO: Add wrappers
	}
	return hr;
}

extern "C" HRESULT WINAPI DirectInputCreateW(HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTW* lplpDirectInput, LPUNKNOWN punkOuter)
{
	HRESULT hr = m_pDirectInputCreateW(hinst, dwVersion, lplpDirectInput, punkOuter);
	if (SUCCEEDED(hr))
	{
		//TODO: Add wrappers
		//LPDIRECTINPUTW* temp = lplpDirectInput;
		//*lplpDirectInput = new m_DirectInputW(*temp);
		//delete temp;
	}
	Log() << __FUNCTION__ << " " << (void*)dwVersion << "\t" << hr;
	return hr;
}
