/*
* Copyright 2013 Jari Komppa http://iki.fi/sol/
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
*
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any source
* distribution.
*
* Taken from code found here: https://github.com/jarikomppa/dxwrapper
*
* Updated 2017 by Elisha Riedlinger
*/

#include "ddraw.h"

std::ofstream Log::LOG("ddraw.log");

FARPROC m_pAcquireDDThreadLock;
FARPROC m_pCompleteCreateSysmemSurface;
FARPROC m_pD3DParseUnknownCommand;
FARPROC m_pDDGetAttachedSurfaceLcl;
FARPROC m_pDDInternalLock;
FARPROC m_pDDInternalUnlock;
FARPROC m_pDSoundHelp;
DDrawCreateProc m_pDDrawCreate;
FARPROC m_pDirectDrawCreateClipper;
DDrawCreateExProc m_pDDrawCreateEx;
DDrawEnumerateAProc m_pDDrawEnumerateA;
DDrawEnumerateExAProc m_pDDrawEnumerateExA;
DDrawEnumerateExWProc m_pDDrawEnumerateExW;
DDrawEnumerateWProc m_pDDrawEnumerateW;
DllCanUnloadNowProc m_pDllCanUnloadNow;
FARPROC m_pDllGetClassObject;
FARPROC m_pGetDDSurfaceLocal;
FARPROC m_pGetOLEThunkData;
FARPROC m_pGetSurfaceFromDC;
FARPROC m_pRegisterSpecialCase;
FARPROC m_pReleaseDDThreadLock;
SetAppCompatDataProc m_pSetAppCompatData;

bool _stdcall DllMain(HANDLE, DWORD dwReason, LPVOID)
{
	static HMODULE ddrawdll = nullptr;
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Load dll
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\ddraw.dll");
		Log() << "Loading " << path;
		ddrawdll = LoadLibraryA(path);

		// Get function addresses
		m_pAcquireDDThreadLock = GetProcAddress(ddrawdll, "AcquireDDThreadLock");
		m_pCompleteCreateSysmemSurface = GetProcAddress(ddrawdll, "CompleteCreateSysmemSurface");
		m_pD3DParseUnknownCommand = GetProcAddress(ddrawdll, "D3DParseUnknownCommand");
		m_pDDGetAttachedSurfaceLcl = GetProcAddress(ddrawdll, "DDGetAttachedSurfaceLcl");
		m_pDDInternalLock = GetProcAddress(ddrawdll, "DDInternalLock");
		m_pDDInternalUnlock = GetProcAddress(ddrawdll, "DDInternalUnlock");
		m_pDSoundHelp = GetProcAddress(ddrawdll, "DSoundHelp");
		m_pDDrawCreate = (DDrawCreateProc)GetProcAddress(ddrawdll, "DirectDrawCreate");
		m_pDirectDrawCreateClipper = GetProcAddress(ddrawdll, "DirectDrawCreateClipper");
		m_pDDrawCreateEx = (DDrawCreateExProc)GetProcAddress(ddrawdll, "DirectDrawCreateEx");
		m_pDDrawEnumerateA = (DDrawEnumerateAProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateA");
		m_pDDrawEnumerateExA = (DDrawEnumerateExAProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateExA");
		m_pDDrawEnumerateExW = (DDrawEnumerateExWProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateExW");
		m_pDDrawEnumerateW = (DDrawEnumerateWProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateW");
		m_pDllCanUnloadNow = (DllCanUnloadNowProc)GetProcAddress(ddrawdll, "DllCanUnloadNow");
		m_pDllGetClassObject = GetProcAddress(ddrawdll, "DllGetClassObject");
		m_pGetDDSurfaceLocal = GetProcAddress(ddrawdll, "GetDDSurfaceLocal");
		m_pGetOLEThunkData = GetProcAddress(ddrawdll, "GetOLEThunkData");
		m_pGetSurfaceFromDC = GetProcAddress(ddrawdll, "GetSurfaceFromDC");
		m_pRegisterSpecialCase = GetProcAddress(ddrawdll, "RegisterSpecialCase");
		m_pReleaseDDThreadLock = GetProcAddress(ddrawdll, "ReleaseDDThreadLock");
		m_pSetAppCompatData = (SetAppCompatDataProc)GetProcAddress(ddrawdll, "SetAppCompatData");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(ddrawdll);
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

struct WrapPair
{
	void * mOriginal;
	void * mWrapper;
};

#define MAX_PAIRS 65536
WrapPair gWrapPair[MAX_PAIRS];
int gWrapPairs = 0;

void * do_wrapfetch(void * aOriginal)
{
	int i;
	for (i = 0; i < gWrapPairs; i++)
	{
		if (gWrapPair[i].mOriginal == aOriginal)
		{
			return gWrapPair[i].mWrapper;
		}
	}
	return nullptr;
}

void wrapstore(void * aOriginal, void * aWrapper)
{
	if (do_wrapfetch(aOriginal) == NULL)
	{
		gWrapPair[gWrapPairs].mOriginal = aOriginal;
		gWrapPair[gWrapPairs].mWrapper = aWrapper;
		gWrapPairs++;
	}
	else
	{
		int i;
		for (i = 0; i < gWrapPairs; i++)
		{
			if (gWrapPair[i].mOriginal == aOriginal)
			{
				gWrapPair[i].mWrapper = aWrapper;
				return;
			}
		}
	}

	if (gWrapPairs >= MAX_PAIRS)
	{
		logf("**** Max number of wrappers exceeded - adjust and recompile");
	}
}

void * wrapfetch(void * aOriginal)
{
	void * ret = do_wrapfetch(aOriginal);
	if (!ret)
	{
		logf("Pre-wrapped object not found - returning null");
	}
	return ret;
}

void __declspec(naked) AcquireDDThreadLock()
{
	logf(__FUNCTION__);
	_asm jmp m_pAcquireDDThreadLock;
}

void __declspec(naked) CompleteCreateSysmemSurface()
{
	logf(__FUNCTION__);
	_asm jmp m_pCompleteCreateSysmemSurface;
}

void __declspec(naked) D3DParseUnknownCommand()
{
	logf(__FUNCTION__);
	_asm jmp m_pD3DParseUnknownCommand;
}

void __declspec(naked) DDGetAttachedSurfaceLcl()
{
	logf(__FUNCTION__);
	_asm jmp m_pDDGetAttachedSurfaceLcl;
}

void __declspec(naked) DDInternalLock()
{
	logf(__FUNCTION__);
	_asm jmp m_pDDInternalLock;
}

void __declspec(naked) DDInternalUnlock()
{
	logf(__FUNCTION__);
	_asm jmp m_pDDInternalUnlock;
}

void __declspec(naked) DSoundHelp()
{
	logf(__FUNCTION__);
	_asm jmp m_pDSoundHelp;
}

HRESULT WINAPI DirectDrawCreate(GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter)
{
	logf(__FUNCTION__);
	HRESULT hr = m_pDDrawCreate(lpGUID, lplpDD, pUnkOuter);
	if (FAILED(hr)) return hr;
	*lplpDD = (IDirectDraw*)new m_IDirectDraw(*lplpDD);
	return 0;
}

void __declspec(naked) DirectDrawCreateClipper()
{
	logf(__FUNCTION__);
	_asm jmp m_pDirectDrawCreateClipper;
}

HRESULT WINAPI DirectDrawCreateEx(GUID FAR *lpGUID, LPVOID *lplpDD, REFIID iid, IUnknown FAR *pUnkOuter)
{
	logf(__FUNCTION__);
	HRESULT hr = m_pDDrawCreateEx(lpGUID, lplpDD, iid, pUnkOuter);
	genericQueryInterface(iid, lplpDD);
	return hr;
}

HRESULT WINAPI DirectDrawEnumerateA(LPDDENUMCALLBACKA lpCallback, LPVOID lpContext)
{
	logf(__FUNCTION__);
	return m_pDDrawEnumerateA(lpCallback, lpContext);
}

HRESULT WINAPI DirectDrawEnumerateExA(LPDDENUMCALLBACKEXA lpCallback, LPVOID lpContext, DWORD dwFlags)
{
	logf(__FUNCTION__);
	return m_pDDrawEnumerateExA(lpCallback, lpContext, dwFlags);
}

HRESULT WINAPI DirectDrawEnumerateExW(LPDDENUMCALLBACKEXW lpCallback, LPVOID lpContext, DWORD dwFlags)
{
	logf(__FUNCTION__);
	return m_pDDrawEnumerateExW(lpCallback, lpContext, dwFlags);
}

HRESULT WINAPI DirectDrawEnumerateW(LPDDENUMCALLBACKW lpCallback, LPVOID lpContext)
{
	logf(__FUNCTION__);
	return m_pDDrawEnumerateW(lpCallback, lpContext);
}

HRESULT WINAPI DllCanUnloadNow()
{
	logf(__FUNCTION__);
	return m_pDllCanUnloadNow();
}

void __declspec(naked) DllGetClassObject()
{
	logf(__FUNCTION__);
	_asm jmp m_pDllGetClassObject;
}

void __declspec(naked) GetDDSurfaceLocal()
{
	logf(__FUNCTION__);
	_asm jmp m_pGetDDSurfaceLocal;
}

void __declspec(naked) GetOLEThunkData()
{
	logf(__FUNCTION__);
	_asm jmp m_pGetOLEThunkData;
}

extern "C" void __declspec(naked) GetSurfaceFromDC()
{
	logf(__FUNCTION__);
	_asm jmp m_pGetSurfaceFromDC;
}

void __declspec(naked) RegisterSpecialCase()
{
	logf(__FUNCTION__);
	_asm jmp m_pRegisterSpecialCase;
}

void __declspec(naked) ReleaseDDThreadLock()
{
	logf(__FUNCTION__);
	_asm jmp m_pReleaseDDThreadLock;
}

HRESULT WINAPI SetAppCompatData(DWORD Type, DWORD Value)
{
	logf(__FUNCTION__);
	return m_pSetAppCompatData(Type, Value);
}
