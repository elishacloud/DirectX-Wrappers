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

HRESULT m_IDirectInputX::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	return ProxyQueryInterface(ProxyInterface, riid, ppvObj, WrapperID, WrapperInterface);
}

ULONG m_IDirectInputX::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectInputX::Release()
{
	ULONG ref = ProxyInterface->Release();

	if (ref == 0)
	{
		WrapperInterface->DeleteMe();
	}

	return ref;
}

HRESULT m_IDirectInputX::CreateDeviceA(REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
	HRESULT hr = GetProxyInterfaceA()->CreateDevice(rguid, lplpDirectInputDevice, pUnkOuter);

	if (SUCCEEDED(hr) && lplpDirectInputDevice)
	{
		*lplpDirectInputDevice = ProxyAddressLookupTable.FindAddressA<m_IDirectInputDeviceA>(*lplpDirectInputDevice, DirectXVersion);
	}

	return hr;
}

HRESULT m_IDirectInputX::CreateDeviceW(REFGUID rguid, LPDIRECTINPUTDEVICEW *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
	HRESULT hr = GetProxyInterfaceW()->CreateDevice(rguid, lplpDirectInputDevice, pUnkOuter);

	if (SUCCEEDED(hr) && lplpDirectInputDevice)
	{
		*lplpDirectInputDevice = ProxyAddressLookupTable.FindAddressW<m_IDirectInputDeviceW>(*lplpDirectInputDevice, DirectXVersion);
	}

	return hr;
}

HRESULT m_IDirectInputX::EnumDevicesA(DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return GetProxyInterfaceA()->EnumDevices(dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT m_IDirectInputX::EnumDevicesW(DWORD dwDevType, LPDIENUMDEVICESCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return GetProxyInterfaceW()->EnumDevices(dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT m_IDirectInputX::GetDeviceStatus(REFGUID rguidInstance)
{
	return ProxyInterface->GetDeviceStatus(rguidInstance);
}

HRESULT m_IDirectInputX::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return ProxyInterface->RunControlPanel(hwndOwner, dwFlags);
}

HRESULT m_IDirectInputX::Initialize(HINSTANCE hinst, DWORD dwVersion)
{
	return ProxyInterface->Initialize(hinst, dwVersion);
}

HRESULT m_IDirectInputX::FindDeviceA(REFGUID rguidClass, LPCSTR ptszName, LPGUID pguidInstance)
{
	return GetProxyInterfaceA()->FindDevice(rguidClass, ptszName, pguidInstance);
}

HRESULT m_IDirectInputX::FindDeviceW(REFGUID rguidClass, LPCWSTR ptszName, LPGUID pguidInstance)
{
	return GetProxyInterfaceW()->FindDevice(rguidClass, ptszName, pguidInstance);
}

HRESULT m_IDirectInputX::CreateDeviceEx(REFGUID rguid, REFIID riid, LPVOID *ppvObj, LPUNKNOWN pUnkOuter)
{
	HRESULT hr = ProxyInterface->CreateDeviceEx(rguid, riid, ppvObj, pUnkOuter);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, (LPVOID *)ppvObj);
	}

	return hr;
}
