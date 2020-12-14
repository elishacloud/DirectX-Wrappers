/**
* Copyright (C) 2020 Elisha Riedlinger
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

#include "dsound.h"

#pragma comment (lib, "dxguid.lib")

std::ofstream Log::LOG("dsound.log");
AddressLookupTable<void> ProxyAddressLookupTable = AddressLookupTable<void>();

DirectSoundCreateProc m_pDirectSoundCreate;
DirectSoundEnumerateAProc m_pDirectSoundEnumerateA;
DirectSoundEnumerateWProc m_pDirectSoundEnumerateW;
DllCanUnloadNowProc m_pDllCanUnloadNow;
DllGetClassObjectProc m_pDllGetClassObject;
DirectSoundCaptureCreateProc m_pDirectSoundCaptureCreate;
DirectSoundCaptureEnumerateAProc m_pDirectSoundCaptureEnumerateA;
DirectSoundCaptureEnumerateWProc m_pDirectSoundCaptureEnumerateW;
GetDeviceIDProc m_pGetDeviceID;
DirectSoundFullDuplexCreateProc m_pDirectSoundFullDuplexCreate;
DirectSoundCreate8Proc m_pDirectSoundCreate8;
DirectSoundCaptureCreate8Proc m_pDirectSoundCaptureCreate8;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(lpReserved);

	static HMODULE dsounddll;

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Load dll
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\dsound.dll");
		Log() << "Loading " << path;
		dsounddll = LoadLibraryA(path);

		// Get function addresses
		m_pDirectSoundCreate = (DirectSoundCreateProc)GetProcAddress(dsounddll, "DirectSoundCreate");
		m_pDirectSoundEnumerateA = (DirectSoundEnumerateAProc)GetProcAddress(dsounddll, "DirectSoundEnumerateA");
		m_pDirectSoundEnumerateW = (DirectSoundEnumerateWProc)GetProcAddress(dsounddll, "DirectSoundEnumerateW");
		m_pDllCanUnloadNow = (DllCanUnloadNowProc)GetProcAddress(dsounddll, "DllCanUnloadNow");
		m_pDllGetClassObject = (DllGetClassObjectProc)GetProcAddress(dsounddll, "DllGetClassObject");
		m_pDirectSoundCaptureCreate = (DirectSoundCaptureCreateProc)GetProcAddress(dsounddll, "DirectSoundCaptureCreate");
		m_pDirectSoundCaptureEnumerateA = (DirectSoundCaptureEnumerateAProc)GetProcAddress(dsounddll, "DirectSoundCaptureEnumerateA");
		m_pDirectSoundCaptureEnumerateW = (DirectSoundCaptureEnumerateWProc)GetProcAddress(dsounddll, "DirectSoundCaptureEnumerateW");
		m_pGetDeviceID = (GetDeviceIDProc)GetProcAddress(dsounddll, "GetDeviceID");
		m_pDirectSoundFullDuplexCreate = (DirectSoundFullDuplexCreateProc)GetProcAddress(dsounddll, "DirectSoundFullDuplexCreate");
		m_pDirectSoundCreate8 = (DirectSoundCreate8Proc)GetProcAddress(dsounddll, "DirectSoundCreate8");
		m_pDirectSoundCaptureCreate8 = (DirectSoundCaptureCreate8Proc)GetProcAddress(dsounddll, "DirectSoundCaptureCreate8");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(dsounddll);
		break;
	}

	return TRUE;
}

HRESULT WINAPI DirectSoundCreate(LPCGUID pcGuidDevice, LPDIRECTSOUND *ppDS, LPUNKNOWN pUnkOuter)
{
	if (!m_pDirectSoundCreate)
	{
		return E_FAIL;
	}

	HRESULT hr = m_pDirectSoundCreate(pcGuidDevice, ppDS, pUnkOuter);

	if (SUCCEEDED(hr) && ppDS)
	{
		*ppDS = new m_IDirectSound8((IDirectSound8*)*ppDS);
	}

	return hr;
}

HRESULT WINAPI DirectSoundEnumerateA(LPDSENUMCALLBACKA pDSEnumCallback, LPVOID pContext)
{
	if (!m_pDirectSoundEnumerateA)
	{
		return E_FAIL;
	}

	return m_pDirectSoundEnumerateA(pDSEnumCallback, pContext);
}

HRESULT WINAPI DirectSoundEnumerateW(LPDSENUMCALLBACKW pDSEnumCallback, LPVOID pContext)
{
	if (!m_pDirectSoundEnumerateW)
	{
		return E_FAIL;
	}

	return m_pDirectSoundEnumerateW(pDSEnumCallback, pContext);
}

HRESULT WINAPI DllCanUnloadNow()
{
	if (!m_pDllCanUnloadNow)
	{
		return E_FAIL;
	}

	return m_pDllCanUnloadNow();
}

HRESULT WINAPI DllGetClassObject(IN REFCLSID rclsid, IN REFIID riid, OUT LPVOID FAR* ppv)
{
	if (!m_pDllGetClassObject)
	{
		return E_FAIL;
	}

	HRESULT hr = m_pDllGetClassObject(rclsid, riid, ppv);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppv);
	}

	return hr;
}

HRESULT WINAPI DirectSoundCaptureCreate(LPCGUID pcGuidDevice, LPDIRECTSOUNDCAPTURE *ppDSC, LPUNKNOWN pUnkOuter)
{
	if (!m_pDirectSoundCaptureCreate)
	{
		return E_FAIL;
	}

	HRESULT hr = m_pDirectSoundCaptureCreate(pcGuidDevice, ppDSC, pUnkOuter);

	if (SUCCEEDED(hr) && ppDSC)
	{
		*ppDSC = new m_IDirectSoundCapture8(*ppDSC);
	}

	return hr;
}

HRESULT WINAPI DirectSoundCaptureEnumerateA(LPDSENUMCALLBACKA pDSEnumCallback, LPVOID pContext)
{
	if (!m_pDirectSoundCaptureEnumerateA)
	{
		return E_FAIL;
	}

	return m_pDirectSoundCaptureEnumerateA(pDSEnumCallback, pContext);
}

HRESULT WINAPI DirectSoundCaptureEnumerateW(LPDSENUMCALLBACKW pDSEnumCallback, LPVOID pContext)
{
	if (!m_pDirectSoundCaptureEnumerateW)
	{
		return E_FAIL;
	}

	return m_pDirectSoundCaptureEnumerateW(pDSEnumCallback, pContext);
}

HRESULT WINAPI GetDeviceID(LPCGUID pGuidSrc, LPGUID pGuidDest)
{
	return m_pGetDeviceID(pGuidSrc, pGuidDest);
}

HRESULT WINAPI DirectSoundFullDuplexCreate(LPCGUID pcGuidCaptureDevice, LPCGUID pcGuidRenderDevice, LPCDSCBUFFERDESC pcDSCBufferDesc, LPCDSBUFFERDESC pcDSBufferDesc, HWND hWnd,
	DWORD dwLevel, LPDIRECTSOUNDFULLDUPLEX* ppDSFD, LPDIRECTSOUNDCAPTUREBUFFER8 *ppDSCBuffer8, LPDIRECTSOUNDBUFFER8 *ppDSBuffer8, LPUNKNOWN pUnkOuter)
{
	if (!m_pDirectSoundFullDuplexCreate)
	{
		return E_FAIL;
	}

	HRESULT hr = m_pDirectSoundFullDuplexCreate(pcGuidCaptureDevice, pcGuidRenderDevice, pcDSCBufferDesc, pcDSBufferDesc, hWnd, dwLevel, ppDSFD, ppDSCBuffer8, ppDSBuffer8, pUnkOuter);

	if (SUCCEEDED(hr))
	{
		if (ppDSFD)
		{
			*ppDSFD = new m_IDirectSoundFullDuplex8(*ppDSFD);
		}
		if (ppDSCBuffer8)
		{
			*ppDSCBuffer8 = new m_IDirectSoundCaptureBuffer8(*ppDSCBuffer8);
		}
		if (ppDSBuffer8)
		{
			*ppDSBuffer8 = new m_IDirectSoundBuffer8(*ppDSBuffer8);
		}
	}

	return hr;
}

HRESULT WINAPI DirectSoundCreate8(LPCGUID pcGuidDevice, LPDIRECTSOUND8 *ppDS8, LPUNKNOWN pUnkOuter)
{
	if (!m_pDirectSoundCreate8)
	{
		return E_FAIL;
	}

	HRESULT hr = m_pDirectSoundCreate8(pcGuidDevice, ppDS8, pUnkOuter);

	if (SUCCEEDED(hr) && ppDS8)
	{
		*ppDS8 = new m_IDirectSound8(*ppDS8);
	}

	return hr;
}

HRESULT WINAPI DirectSoundCaptureCreate8(LPCGUID pcGuidDevice, LPDIRECTSOUNDCAPTURE8 *ppDSC8, LPUNKNOWN pUnkOuter)
{
	if (!m_pDirectSoundCaptureCreate8)
	{
		return E_FAIL;
	}

	HRESULT hr = m_pDirectSoundCaptureCreate8(pcGuidDevice, ppDSC8, pUnkOuter);

	if (SUCCEEDED(hr) && ppDSC8)
	{
		*ppDSC8 = new m_IDirectSoundCapture8(*ppDSC8);
	}

	return hr;
}
