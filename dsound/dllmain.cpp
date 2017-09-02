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
* Code taken from code found here: https://github.com/elishacloud/DirectSoundControl
*/

#include "dsound.h"

std::ofstream Log::LOG("dsound.log");

DirectSoundCreate8Proc m_pDirectSoundCreate8 = nullptr;
DirectSoundCreateProc m_pDirectSoundCreate = nullptr;
GetDeviceIDProc m_pGetDeviceID = nullptr;
DirectSoundEnumerateAProc m_pDirectSoundEnumerateA = nullptr;
DirectSoundEnumerateWProc m_pDirectSoundEnumerateW = nullptr;
DirectSoundCaptureCreateProc m_pDirectSoundCaptureCreate = nullptr;
DirectSoundCaptureEnumerateAProc m_pDirectSoundCaptureEnumerateA = nullptr;
DirectSoundCaptureEnumerateWProc m_pDirectSoundCaptureEnumerateW = nullptr;
DirectSoundCaptureCreate8Proc m_pDirectSoundCaptureCreate8 = nullptr;
DirectSoundFullDuplexCreateProc m_pDirectSoundFullDuplexCreate = nullptr;
DllGetClassObjectProc m_pDllGetClassObject = nullptr;
DllCanUnloadNowProc m_pDllCanUnloadNow = nullptr;

LPDSENUMCALLBACKA m_pAppDSEnumCallbackA;
LPDSENUMCALLBACKW m_pAppDSEnumCallbackW;

HRESULT STDMETHODCALLTYPE m_DirectSoundCreate(LPCGUID pcGuidDevice, LPDIRECTSOUND *ppDS, LPUNKNOWN pUnkOuter)
{
	m_IDirectSound8* pDSX = new m_IDirectSound8;

	HRESULT hRes = m_pDirectSoundCreate(pcGuidDevice, (LPDIRECTSOUND*)&(pDSX->m_lpDirectSound8) /* ppDS8 */, pUnkOuter);

	if (hRes != S_OK)
	{
		delete pDSX;
		return hRes;
	}

	*ppDS = (LPDIRECTSOUND)pDSX;

	return hRes;
}

BOOL STDMETHODCALLTYPE DSDLLEnumCallbackA(LPGUID lpGuid, LPCSTR lpcstrDescription, LPCSTR lpcstrModule, LPVOID lpContext)
{
	return m_pAppDSEnumCallbackA(lpGuid, lpcstrDescription, lpcstrModule, lpContext);
}

BOOL STDMETHODCALLTYPE DSDLLEnumCallbackW(LPGUID lpGuid, LPCWSTR lpcstrDescription, LPCWSTR lpcstrModule, LPVOID lpContext)
{
	return m_pAppDSEnumCallbackW(lpGuid, lpcstrDescription, lpcstrModule, lpContext);
}

HRESULT STDMETHODCALLTYPE m_DirectSoundEnumerateA(LPDSENUMCALLBACKA pDSEnumCallback, LPVOID pContext)
{
	return m_pDirectSoundEnumerateA(pDSEnumCallback, pContext);
}

HRESULT STDMETHODCALLTYPE m_DirectSoundEnumerateW(LPDSENUMCALLBACKW pDSEnumCallback, LPVOID pContext)
{
	return m_pDirectSoundEnumerateW(pDSEnumCallback, pContext);
}

HRESULT STDMETHODCALLTYPE m_DirectSoundCaptureCreate(LPCGUID pcGuidDevice, LPDIRECTSOUNDCAPTURE *ppDSC, LPUNKNOWN pUnkOuter)
{
	return m_pDirectSoundCaptureCreate(pcGuidDevice, ppDSC, pUnkOuter);
}

HRESULT STDMETHODCALLTYPE m_DirectSoundCaptureEnumerateA(LPDSENUMCALLBACKA pDSEnumCallback, LPVOID pContext)
{
	return m_pDirectSoundCaptureEnumerateA(pDSEnumCallback, pContext);
}

HRESULT STDMETHODCALLTYPE m_DirectSoundCaptureEnumerateW(LPDSENUMCALLBACKW pDSEnumCallback, LPVOID pContext)
{
	return m_pDirectSoundCaptureEnumerateW(pDSEnumCallback, pContext);
}

HRESULT STDMETHODCALLTYPE m_DirectSoundCreate8(LPCGUID pcGuidDevice, LPDIRECTSOUND8 *ppDS8, LPUNKNOWN pUnkOuter)
{
	m_IDirectSound8* pDSX = new m_IDirectSound8;

	HRESULT hRes = m_pDirectSoundCreate8(pcGuidDevice, &(pDSX->m_lpDirectSound8) /* ppDS8 */, pUnkOuter);

	if (hRes != S_OK)
	{
		delete pDSX;
		return hRes;
	}

	*ppDS8 = (LPDIRECTSOUND8)pDSX;

	return hRes;
}

HRESULT STDMETHODCALLTYPE m_DirectSoundCaptureCreate8(LPCGUID pcGuidDevice, LPDIRECTSOUNDCAPTURE8 *ppDSC8, LPUNKNOWN pUnkOuter)
{
	return m_pDirectSoundCaptureCreate8(pcGuidDevice, ppDSC8, pUnkOuter);
}

HRESULT STDMETHODCALLTYPE m_DirectSoundFullDuplexCreate(LPCGUID pcGuidCaptureDevice, LPCGUID pcGuidRenderDevice,
	LPCDSCBUFFERDESC pcDSCBufferDesc, LPCDSBUFFERDESC pcDSBufferDesc, HWND hWnd,
	DWORD dwLevel, LPDIRECTSOUNDFULLDUPLEX* ppDSFD, LPDIRECTSOUNDCAPTUREBUFFER8 *ppDSCBuffer8,
	LPDIRECTSOUNDBUFFER8 *ppDSBuffer8, LPUNKNOWN pUnkOuter)
{
	return m_pDirectSoundFullDuplexCreate(pcGuidCaptureDevice, pcGuidRenderDevice,
		pcDSCBufferDesc, pcDSBufferDesc, hWnd,
		dwLevel, ppDSFD, ppDSCBuffer8,
		ppDSBuffer8, pUnkOuter);
}

HRESULT STDMETHODCALLTYPE m_GetDeviceID(LPCGUID pGuidSrc, LPGUID pGuidDest)
{
	return m_pGetDeviceID(pGuidSrc, pGuidDest);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(lpReserved);

	static HMODULE dsounddll;

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\dsound.dll");
		Log() << "Loading " << path << "\n";
		dsounddll = LoadLibraryA(path);
		m_pDirectSoundCreate = (DirectSoundCreateProc)GetProcAddress(dsounddll, "DirectSoundCreate");
		m_pDirectSoundCreate8 = (DirectSoundCreate8Proc)GetProcAddress(dsounddll, "DirectSoundCreate8");
		m_pGetDeviceID = (GetDeviceIDProc)GetProcAddress(dsounddll, "GetDeviceID");
		m_pDirectSoundEnumerateA = (DirectSoundEnumerateAProc)GetProcAddress(dsounddll, "DirectSoundEnumerateA");
		m_pDirectSoundEnumerateW = (DirectSoundEnumerateWProc)GetProcAddress(dsounddll, "DirectSoundEnumerateW");
		m_pDirectSoundCaptureCreate = (DirectSoundCaptureCreateProc)GetProcAddress(dsounddll, "DirectSoundCaptureCreate");
		m_pDirectSoundCaptureEnumerateA = (DirectSoundCaptureEnumerateAProc)GetProcAddress(dsounddll, "DirectSoundCaptureEnumerateA");
		m_pDirectSoundCaptureEnumerateW = (DirectSoundCaptureEnumerateWProc)GetProcAddress(dsounddll, "DirectSoundCaptureEnumerateW");
		m_pDirectSoundCaptureCreate8 = (DirectSoundCaptureCreate8Proc)GetProcAddress(dsounddll, "DirectSoundCaptureCreate8");
		m_pDirectSoundFullDuplexCreate = (DirectSoundFullDuplexCreateProc)GetProcAddress(dsounddll, "DirectSoundFullDuplexCreate");
		m_pDllGetClassObject = (DllGetClassObjectProc)GetProcAddress(dsounddll, "DllGetClassObject");
		m_pDllCanUnloadNow = (DllCanUnloadNowProc)GetProcAddress(dsounddll, "DllCanUnloadNow");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(dsounddll);
		break;
	}

	return TRUE;
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
