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

#include "dinput.h"

HRESULT m_IDirectInputDeviceW::QueryInterface(REFIID riid, LPVOID* ppvObj)
{
	if ((riid == IID_IDirectInputDeviceW || riid == CLSID_DirectInputDevice || riid == IID_IUnknown) && ppvObj)
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	HRESULT hr = ProxyInterface->QueryInterface(riid, ppvObj);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppvObj);
	}

	return hr;
}

ULONG m_IDirectInputDeviceW::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectInputDeviceW::Release()
{
	ULONG x = ProxyInterface->Release();

	if (x == 0)
	{
		delete this;
	}

	return x;
}

HRESULT m_IDirectInputDeviceW::GetCapabilities(LPDIDEVCAPS lpDIDevCaps)
{
	return ProxyInterface->GetCapabilities(lpDIDevCaps);
}

HRESULT m_IDirectInputDeviceW::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return ProxyInterface->EnumObjects(lpCallback, pvRef, dwFlags);
}

HRESULT m_IDirectInputDeviceW::GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
	return ProxyInterface->GetProperty(rguidProp, pdiph);
}

HRESULT m_IDirectInputDeviceW::SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
	return ProxyInterface->SetProperty(rguidProp, pdiph);
}

HRESULT m_IDirectInputDeviceW::Acquire()
{
	return ProxyInterface->Acquire();
}

HRESULT m_IDirectInputDeviceW::Unacquire()
{
	return ProxyInterface->Unacquire();
}

HRESULT m_IDirectInputDeviceW::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
	return ProxyInterface->GetDeviceState(cbData, lpvData);
}

HRESULT m_IDirectInputDeviceW::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	return ProxyInterface->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT m_IDirectInputDeviceW::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	return ProxyInterface->SetDataFormat(lpdf);
}

HRESULT m_IDirectInputDeviceW::SetEventNotification(HANDLE hEvent)
{
	return ProxyInterface->SetEventNotification(hEvent);
}

HRESULT m_IDirectInputDeviceW::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	return ProxyInterface->SetCooperativeLevel(hwnd, dwFlags);
}

HRESULT m_IDirectInputDeviceW::GetObjectInfo(LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow)
{
	return ProxyInterface->GetObjectInfo(pdidoi, dwObj, dwHow);
}

HRESULT m_IDirectInputDeviceW::GetDeviceInfo(LPDIDEVICEINSTANCEW pdidi)
{
	return ProxyInterface->GetDeviceInfo(pdidi);
}

HRESULT m_IDirectInputDeviceW::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return ProxyInterface->RunControlPanel(hwndOwner, dwFlags);
}

HRESULT m_IDirectInputDeviceW::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	return ProxyInterface->Initialize(hinst, dwVersion, rguid);
}
