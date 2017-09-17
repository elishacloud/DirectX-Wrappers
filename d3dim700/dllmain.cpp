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

#include "d3dim700.h"

std::ofstream Log::LOG("d3dim700.log");

FARPROC m_pD3DFree;
FARPROC m_pD3DMalloc;
FARPROC m_pD3DRealloc;
FARPROC m_pDirect3DCreateDevice;
FARPROC m_pCreateTexture;
FARPROC m_pD3DBreakVBLock;
FARPROC m_pD3DTextureUpdate;
FARPROC m_pDestroyTexture;
FARPROC m_pDirect3DCreate;
FARPROC m_pDirect3D_HALCleanUp;
FARPROC m_pFlushD3DDevices;
FARPROC m_pGetLOD;
FARPROC m_pGetPriority;
FARPROC m_pPaletteAssociateNotify;
FARPROC m_pPaletteUpdateNotify;
FARPROC m_pSetLOD;
FARPROC m_pSetPriority;
FARPROC m_pSurfaceFlipNotify;

bool _stdcall DllMain(HANDLE, DWORD dwReason, LPVOID)
{
	static HMODULE d3dim700dll = nullptr;
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\d3dim700.dll");
		Log() << "Loading " << path << "\n";
		d3dim700dll = LoadLibraryA(path);
		m_pD3DFree = GetProcAddress(d3dim700dll, "D3DFree");
		m_pD3DMalloc = GetProcAddress(d3dim700dll, "D3DMalloc");
		m_pD3DRealloc = GetProcAddress(d3dim700dll, "D3DRealloc");
		m_pDirect3DCreateDevice = GetProcAddress(d3dim700dll, "Direct3DCreateDevice");
		m_pCreateTexture = GetProcAddress(d3dim700dll, "CreateTexture");
		m_pD3DBreakVBLock = GetProcAddress(d3dim700dll, "D3DBreakVBLock");
		m_pD3DTextureUpdate = GetProcAddress(d3dim700dll, "D3DTextureUpdate");
		m_pDestroyTexture = GetProcAddress(d3dim700dll, "DestroyTexture");
		m_pDirect3DCreate = GetProcAddress(d3dim700dll, "Direct3DCreate");
		m_pDirect3D_HALCleanUp = GetProcAddress(d3dim700dll, "Direct3D_HALCleanUp");
		m_pFlushD3DDevices = GetProcAddress(d3dim700dll, "FlushD3DDevices");
		m_pGetLOD = GetProcAddress(d3dim700dll, "GetLOD");
		m_pGetPriority = GetProcAddress(d3dim700dll, "GetPriority");
		m_pPaletteAssociateNotify = GetProcAddress(d3dim700dll, "PaletteAssociateNotify");
		m_pPaletteUpdateNotify = GetProcAddress(d3dim700dll, "PaletteUpdateNotify");
		m_pSetLOD = GetProcAddress(d3dim700dll, "SetLOD");
		m_pSetPriority = GetProcAddress(d3dim700dll, "SetPriority");
		m_pSurfaceFlipNotify = GetProcAddress(d3dim700dll, "SurfaceFlipNotify");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(d3dim700dll);
		break;
	}
	return true;
}

void __declspec(naked) D3DFree()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pD3DFree;
}
void __declspec(naked) D3DMalloc()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pD3DMalloc;
}
void __declspec(naked) D3DRealloc()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pD3DRealloc;
}
void __declspec(naked) Direct3DCreateDevice()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pDirect3DCreateDevice;
}
void __declspec(naked) CreateTexture()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pCreateTexture;
}
void __declspec(naked) D3DBreakVBLock()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pD3DBreakVBLock;
}
void __declspec(naked) D3DTextureUpdate()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pD3DTextureUpdate;
}
void __declspec(naked) DestroyTexture()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pDestroyTexture;
}
void __declspec(naked) Direct3DCreate()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pDirect3DCreate;
}
void __declspec(naked) Direct3D_HALCleanUp()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pDirect3D_HALCleanUp;
}
void __declspec(naked) FlushD3DDevices()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pFlushD3DDevices;
}
extern "C" void __declspec(naked) GetLOD()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pGetLOD;
}
extern "C" void __declspec(naked) GetPriority()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pGetPriority;
}
void __declspec(naked) PaletteAssociateNotify()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pPaletteAssociateNotify;
}
void __declspec(naked) PaletteUpdateNotify()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pPaletteUpdateNotify;
}
extern "C" void __declspec(naked) SetLOD()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pSetLOD;
}
extern "C" void __declspec(naked) SetPriority()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pSetPriority;
}
void __declspec(naked) SurfaceFlipNotify()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pSurfaceFlipNotify;
}
