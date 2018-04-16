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

HRESULT m_IDirectInputDevice2A::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	if ((riid == IID_IDirectInputDevice2A || riid == IID_IUnknown) && ppvObj)
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

ULONG m_IDirectInputDevice2A::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectInputDevice2A::Release()
{
	ULONG x = ProxyInterface->Release();

	if (x == 0)
	{
		delete this;
	}

	return x;
}

HRESULT m_IDirectInputDevice2A::GetCapabilities(LPDIDEVCAPS lpDIDevCaps)
{
	return ProxyInterface->GetCapabilities(lpDIDevCaps);
}

HRESULT m_IDirectInputDevice2A::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return ProxyInterface->EnumObjects(lpCallback, pvRef, dwFlags);
}

HRESULT m_IDirectInputDevice2A::GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
	return ProxyInterface->GetProperty(rguidProp, pdiph);
}

HRESULT m_IDirectInputDevice2A::SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
	return ProxyInterface->SetProperty(rguidProp, pdiph);
}

HRESULT m_IDirectInputDevice2A::Acquire()
{
	return ProxyInterface->Acquire();
}

HRESULT m_IDirectInputDevice2A::Unacquire()
{
	return ProxyInterface->Unacquire();
}

HRESULT m_IDirectInputDevice2A::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
	return ProxyInterface->GetDeviceState(cbData, lpvData);
}

HRESULT m_IDirectInputDevice2A::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	return ProxyInterface->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT m_IDirectInputDevice2A::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	return ProxyInterface->SetDataFormat(lpdf);
}

HRESULT m_IDirectInputDevice2A::SetEventNotification(HANDLE hEvent)
{
	return ProxyInterface->SetEventNotification(hEvent);
}

HRESULT m_IDirectInputDevice2A::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	return ProxyInterface->SetCooperativeLevel(hwnd, dwFlags);
}

HRESULT m_IDirectInputDevice2A::GetObjectInfo(LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
	return ProxyInterface->GetObjectInfo(pdidoi, dwObj, dwHow);
}

HRESULT m_IDirectInputDevice2A::GetDeviceInfo(LPDIDEVICEINSTANCEA pdidi)
{
	return ProxyInterface->GetDeviceInfo(pdidi);
}

HRESULT m_IDirectInputDevice2A::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return ProxyInterface->RunControlPanel(hwndOwner, dwFlags);
}

HRESULT m_IDirectInputDevice2A::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	return ProxyInterface->Initialize(hinst, dwVersion, rguid);
}

HRESULT m_IDirectInputDevice2A::CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT * ppdeff, LPUNKNOWN punkOuter)
{
	HRESULT hr = ProxyInterface->CreateEffect(rguid, lpeff, ppdeff, punkOuter);

	if (SUCCEEDED(hr))
	{
		*ppdeff = ProxyAddressLookupTable.FindAddress<m_IDirectInputEffect>(*ppdeff);
	}

	return hr;
}

HRESULT m_IDirectInputDevice2A::EnumEffects(LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
	return ProxyInterface->EnumEffects(lpCallback, pvRef, dwEffType);
}

HRESULT m_IDirectInputDevice2A::GetEffectInfo(LPDIEFFECTINFOA pdei, REFGUID rguid)
{
	return ProxyInterface->GetEffectInfo(pdei, rguid);
}

HRESULT m_IDirectInputDevice2A::GetForceFeedbackState(LPDWORD pdwOut)
{
	return ProxyInterface->GetForceFeedbackState(pdwOut);
}

HRESULT m_IDirectInputDevice2A::SendForceFeedbackCommand(DWORD dwFlags)
{
	return ProxyInterface->SendForceFeedbackCommand(dwFlags);
}

HRESULT m_IDirectInputDevice2A::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
	ENUMEFFECT CallbackContext;
	CallbackContext.pvRef = pvRef;
	CallbackContext.lpCallback = lpCallback;

	return ProxyInterface->EnumCreatedEffectObjects(m_IDirectInputEnumEffect::EnumEffectCallback, &CallbackContext, fl);
}

HRESULT m_IDirectInputDevice2A::Escape(LPDIEFFESCAPE pesc)
{
	return ProxyInterface->Escape(pesc);
}

HRESULT m_IDirectInputDevice2A::Poll()
{
	return ProxyInterface->Poll();
}

HRESULT m_IDirectInputDevice2A::SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
	return ProxyInterface->SendDeviceData(cbObjectData, rgdod, pdwInOut, fl);
}
