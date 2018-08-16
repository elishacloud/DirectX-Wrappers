/**
* Copyright (C) 2018 Elisha Riedlinger
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

#include "ddraw.h"

std::ofstream Log::LOG("ddraw.log");
AddressLookupTableDdraw<void> ProxyAddressLookupTable = AddressLookupTableDdraw<void>();
IDirectDraw7 *CurrentDDInterface = nullptr;

AcquireDDThreadLockProc m_pAcquireDDThreadLock;
CompleteCreateSystemSurfaceProc m_pCompleteCreateSystemSurface;
D3DParseUnknownCommandProc m_pD3DParseUnknownCommand;
DDGetAttachedSurfaceLclProc m_pDDGetAttachedSurfaceLcl;
DDInternalLockProc m_pDDInternalLock;
DDInternalUnlockProc m_pDDInternalUnlock;
DSoundHelpProc m_pDSoundHelp;
DirectDrawCreateProc m_pDirectDrawCreate;
DirectDrawCreateClipperProc m_pDirectDrawCreateClipper;
DDrawCreateExProc m_pDDrawCreateEx;
DDrawEnumerateAProc m_pDDrawEnumerateA;
DDrawEnumerateExAProc m_pDDrawEnumerateExA;
DDrawEnumerateExWProc m_pDDrawEnumerateExW;
DDrawEnumerateWProc m_pDDrawEnumerateW;
DllCanUnloadNowProc m_pDllCanUnloadNow;
DllGetClassObjectProc m_pDllGetClassObject;
GetDDSurfaceLocalProc m_pGetDDSurfaceLocal;
GetOLEThunkDataProc m_pGetOLEThunkData;
GetSurfaceFromDCProc m_pGetSurfaceFromDC;
RegisterSpecialCaseProc m_pRegisterSpecialCase;
ReleaseDDThreadLockProc m_pReleaseDDThreadLock;
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
		m_pAcquireDDThreadLock = (AcquireDDThreadLockProc)GetProcAddress(ddrawdll, "AcquireDDThreadLock");
		m_pCompleteCreateSystemSurface = (CompleteCreateSystemSurfaceProc)GetProcAddress(ddrawdll, "CompleteCreateSystemSurface");
		m_pD3DParseUnknownCommand = (D3DParseUnknownCommandProc)GetProcAddress(ddrawdll, "D3DParseUnknownCommand");
		m_pDDGetAttachedSurfaceLcl = (DDGetAttachedSurfaceLclProc)GetProcAddress(ddrawdll, "DDGetAttachedSurfaceLcl");
		m_pDDInternalLock = (DDInternalLockProc)GetProcAddress(ddrawdll, "DDInternalLock");
		m_pDDInternalUnlock = (DDInternalUnlockProc)GetProcAddress(ddrawdll, "DDInternalUnlock");
		m_pDSoundHelp = (DSoundHelpProc)GetProcAddress(ddrawdll, "DSoundHelp");
		m_pDirectDrawCreate = (DirectDrawCreateProc)GetProcAddress(ddrawdll, "DirectDrawCreate");
		m_pDirectDrawCreateClipper = (DirectDrawCreateClipperProc)GetProcAddress(ddrawdll, "DirectDrawCreateClipper");
		m_pDDrawCreateEx = (DDrawCreateExProc)GetProcAddress(ddrawdll, "DirectDrawCreateEx");
		m_pDDrawEnumerateA = (DDrawEnumerateAProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateA");
		m_pDDrawEnumerateExA = (DDrawEnumerateExAProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateExA");
		m_pDDrawEnumerateExW = (DDrawEnumerateExWProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateExW");
		m_pDDrawEnumerateW = (DDrawEnumerateWProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateW");
		m_pDllCanUnloadNow = (DllCanUnloadNowProc)GetProcAddress(ddrawdll, "DllCanUnloadNow");
		m_pDllGetClassObject = (DllGetClassObjectProc)GetProcAddress(ddrawdll, "DllGetClassObject");
		m_pGetDDSurfaceLocal = (GetDDSurfaceLocalProc)GetProcAddress(ddrawdll, "GetDDSurfaceLocal");
		m_pGetOLEThunkData = (GetOLEThunkDataProc)GetProcAddress(ddrawdll, "GetOLEThunkData");
		m_pGetSurfaceFromDC = (GetSurfaceFromDCProc)GetProcAddress(ddrawdll, "GetSurfaceFromDC");
		m_pRegisterSpecialCase = (RegisterSpecialCaseProc)GetProcAddress(ddrawdll, "RegisterSpecialCase");
		m_pReleaseDDThreadLock = (ReleaseDDThreadLockProc)GetProcAddress(ddrawdll, "ReleaseDDThreadLock");
		m_pSetAppCompatData = (SetAppCompatDataProc)GetProcAddress(ddrawdll, "SetAppCompatData");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(ddrawdll);
		break;
	}
	return true;
}

void WINAPI AcquireDDThreadLock()
{
	return m_pAcquireDDThreadLock();
}

void WINAPI CompleteCreateSystemSurface()
{
	return m_pCompleteCreateSystemSurface();
}

HRESULT WINAPI D3DParseUnknownCommand(LPVOID lpCmd, LPVOID *lpRetCmd)
{
	return m_pD3DParseUnknownCommand(lpCmd, lpRetCmd);
}

void WINAPI DDGetAttachedSurfaceLcl()
{
	return m_pDDGetAttachedSurfaceLcl();
}

void WINAPI DDInternalLock()
{
	return m_pDDInternalLock();
}

void WINAPI DDInternalUnlock()
{
	return m_pDDInternalUnlock();
}

void WINAPI DSoundHelp()
{
	return m_pDSoundHelp();
}

HRESULT WINAPI DirectDrawCreate(GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter)
{
	HRESULT hr = m_pDirectDrawCreate(lpGUID, lplpDD, pUnkOuter);

	if (SUCCEEDED(hr))
	{
		*lplpDD = ProxyAddressLookupTable.FindAddress<m_IDirectDraw>(*lplpDD);
	}

	return hr;
}

HRESULT WINAPI DirectDrawCreateClipper(DWORD dwFlags, LPDIRECTDRAWCLIPPER *lplpDDClipper, LPUNKNOWN pUnkOuter)
{
	HRESULT hr = m_pDirectDrawCreateClipper(dwFlags, lplpDDClipper, pUnkOuter);

	if (SUCCEEDED(hr) && lplpDDClipper)
	{
		*lplpDDClipper = ProxyAddressLookupTable.FindAddress<m_IDirectDrawClipper>(*lplpDDClipper);
	}

	return hr;
}

HRESULT WINAPI DirectDrawCreateEx(GUID FAR *lpGUID, LPVOID *lplpDD, REFIID riid, IUnknown FAR *pUnkOuter)
{
	HRESULT hr = m_pDDrawCreateEx(lpGUID, lplpDD, riid, pUnkOuter);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, lplpDD);
	}

	return hr;
}

HRESULT WINAPI DirectDrawEnumerateA(LPDDENUMCALLBACKA lpCallback, LPVOID lpContext)
{
	return m_pDDrawEnumerateA(lpCallback, lpContext);
}

HRESULT WINAPI DirectDrawEnumerateExA(LPDDENUMCALLBACKEXA lpCallback, LPVOID lpContext, DWORD dwFlags)
{
	return m_pDDrawEnumerateExA(lpCallback, lpContext, dwFlags);
}

HRESULT WINAPI DirectDrawEnumerateExW(LPDDENUMCALLBACKEXW lpCallback, LPVOID lpContext, DWORD dwFlags)
{
	return m_pDDrawEnumerateExW(lpCallback, lpContext, dwFlags);
}

HRESULT WINAPI DirectDrawEnumerateW(LPDDENUMCALLBACKW lpCallback, LPVOID lpContext)
{
	return m_pDDrawEnumerateW(lpCallback, lpContext);
}

HRESULT WINAPI DllCanUnloadNow()
{
	return m_pDllCanUnloadNow();
}

HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
	HRESULT hr = m_pDllGetClassObject(rclsid, riid, ppv);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppv);
	}

	return hr;
}

void WINAPI GetDDSurfaceLocal()
{
	return m_pGetDDSurfaceLocal();
}

HANDLE WINAPI GetOLEThunkData(int i1)
{
	return m_pGetOLEThunkData(i1);
}

extern "C" HRESULT WINAPI GetSurfaceFromDC(HDC hdc, LPDIRECTDRAWSURFACE7 *lpDDS)
{
	HRESULT hr = m_pGetSurfaceFromDC(hdc, lpDDS);

	if (SUCCEEDED(hr))
	{
		*lpDDS = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(*lpDDS);
	}

	return hr;
}

void WINAPI RegisterSpecialCase()
{
	return m_pRegisterSpecialCase();
}

void WINAPI ReleaseDDThreadLock()
{
	return m_pReleaseDDThreadLock();
}

HRESULT WINAPI SetAppCompatData(DWORD Type, DWORD Value)
{
	return m_pSetAppCompatData(Type, Value);
}
