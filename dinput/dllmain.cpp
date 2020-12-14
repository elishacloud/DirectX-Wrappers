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

#include "dinput.h"

std::ofstream Log::LOG("dinput.log");
AddressLookupTable<void> ProxyAddressLookupTable = AddressLookupTable<void>();

DirectInputCreateAProc m_pDirectInputCreateA;
DirectInputCreateExProc m_pDirectInputCreateEx;
DirectInputCreateWProc m_pDirectInputCreateW;
DllCanUnloadNowProc m_pDllCanUnloadNow;
DllGetClassObjectProc m_pDllGetClassObject;
DllRegisterServerProc m_pDllRegisterServer;
DllUnregisterServerProc m_pDllUnregisterServer;

bool WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	static HMODULE dinputdll = nullptr;

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Load dll
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\dinput.dll");
		Log() << "Loading " << path;
		dinputdll = LoadLibraryA(path);

		// Get function addresses
		m_pDirectInputCreateA = (DirectInputCreateAProc)GetProcAddress(dinputdll, "DirectInputCreateA");
		m_pDirectInputCreateEx = (DirectInputCreateExProc)GetProcAddress(dinputdll, "DirectInputCreateEx");
		m_pDirectInputCreateW = (DirectInputCreateWProc)GetProcAddress(dinputdll, "DirectInputCreateW");
		m_pDllCanUnloadNow = (DllCanUnloadNowProc)GetProcAddress(dinputdll, "DllCanUnloadNow");
		m_pDllGetClassObject = (DllGetClassObjectProc)GetProcAddress(dinputdll, "DllGetClassObject");
		m_pDllRegisterServer = (DllRegisterServerProc)GetProcAddress(dinputdll, "DllRegisterServer");
		m_pDllUnregisterServer = (DllUnregisterServerProc)GetProcAddress(dinputdll, "DllUnregisterServer");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(dinputdll);
		break;
	}

	return true;
}

HRESULT WINAPI DirectInputCreateA(HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA* lplpDirectInput, LPUNKNOWN punkOuter)
{
	if (!m_pDirectInputCreateA)
	{
		return E_FAIL;
	}

	HRESULT hr = m_pDirectInputCreateA(hinst, dwVersion, lplpDirectInput, punkOuter);

	if (SUCCEEDED(hr) && lplpDirectInput)
	{
		*lplpDirectInput = new m_IDirectInputA(*lplpDirectInput);
	}

	return hr;
}

HRESULT WINAPI DirectInputCreateEx(HINSTANCE hinst, DWORD dwVersion, REFIID riid, LPVOID * lplpDD, LPUNKNOWN punkOuter)
{
	if (!m_pDirectInputCreateEx)
	{
		return E_FAIL;
	}

	HRESULT hr = m_pDirectInputCreateEx(hinst, dwVersion, riid, lplpDD, punkOuter);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, lplpDD);
	}

	return hr;
}

HRESULT WINAPI DirectInputCreateW(HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTW* lplpDirectInput, LPUNKNOWN punkOuter)
{
	if (!m_pDirectInputCreateW)
	{
		return E_FAIL;
	}

	HRESULT hr = m_pDirectInputCreateW(hinst, dwVersion, lplpDirectInput, punkOuter);

	if (SUCCEEDED(hr) && lplpDirectInput)
	{
		*lplpDirectInput = new m_IDirectInputW(*lplpDirectInput);
	}

	return hr;
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

HRESULT WINAPI DllRegisterServer()
{
	if (!m_pDllRegisterServer)
	{
		return E_FAIL;
	}

	return m_pDllRegisterServer();
}

HRESULT WINAPI DllUnregisterServer()
{
	if (!m_pDllUnregisterServer)
	{
		return E_FAIL;
	}

	return m_pDllUnregisterServer();
}
