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

HRESULT m_IDirectInputDeviceX::QueryInterface(REFIID riid, LPVOID* ppvObj)
{
	return ProxyQueryInterface(ProxyInterface, riid, ppvObj, WrapperID, WrapperInterface);
}

ULONG m_IDirectInputDeviceX::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectInputDeviceX::Release()
{
	ULONG ref = ProxyInterface->Release();

	if (ref == 0)
	{
		WrapperInterface->DeleteMe();
	}

	return ref;
}

HRESULT m_IDirectInputDeviceX::GetCapabilities(LPDIDEVCAPS lpDIDevCaps)
{
	return ProxyInterface->GetCapabilities(lpDIDevCaps);
}

HRESULT m_IDirectInputDeviceX::EnumObjectsA(LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return GetProxyInterfaceA()->EnumObjects(lpCallback, pvRef, dwFlags);
}

HRESULT m_IDirectInputDeviceX::EnumObjectsW(LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return GetProxyInterfaceW()->EnumObjects(lpCallback, pvRef, dwFlags);
}

HRESULT m_IDirectInputDeviceX::GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
	return ProxyInterface->GetProperty(rguidProp, pdiph);
}

HRESULT m_IDirectInputDeviceX::SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
	return ProxyInterface->SetProperty(rguidProp, pdiph);
}

HRESULT m_IDirectInputDeviceX::Acquire()
{
	return ProxyInterface->Acquire();
}

HRESULT m_IDirectInputDeviceX::Unacquire()
{
	return ProxyInterface->Unacquire();
}

HRESULT m_IDirectInputDeviceX::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
	return ProxyInterface->GetDeviceState(cbData, lpvData);
}

HRESULT m_IDirectInputDeviceX::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	return ProxyInterface->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT m_IDirectInputDeviceX::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	return ProxyInterface->SetDataFormat(lpdf);
}

HRESULT m_IDirectInputDeviceX::SetEventNotification(HANDLE hEvent)
{
	return ProxyInterface->SetEventNotification(hEvent);
}

HRESULT m_IDirectInputDeviceX::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	return ProxyInterface->SetCooperativeLevel(hwnd, dwFlags);
}

HRESULT m_IDirectInputDeviceX::GetObjectInfoA(LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
	return GetProxyInterfaceA()->GetObjectInfo(pdidoi, dwObj, dwHow);
}

HRESULT m_IDirectInputDeviceX::GetObjectInfoW(LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow)
{
	return GetProxyInterfaceW()->GetObjectInfo(pdidoi, dwObj, dwHow);
}

HRESULT m_IDirectInputDeviceX::GetDeviceInfoA(LPDIDEVICEINSTANCEA pdidi)
{
	return GetProxyInterfaceA()->GetDeviceInfo(pdidi);
}

HRESULT m_IDirectInputDeviceX::GetDeviceInfoW(LPDIDEVICEINSTANCEW pdidi)
{
	return GetProxyInterfaceW()->GetDeviceInfo(pdidi);
}

HRESULT m_IDirectInputDeviceX::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return ProxyInterface->RunControlPanel(hwndOwner, dwFlags);
}

HRESULT m_IDirectInputDeviceX::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	return ProxyInterface->Initialize(hinst, dwVersion, rguid);
}

HRESULT m_IDirectInputDeviceX::CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT * ppdeff, LPUNKNOWN punkOuter)
{
	HRESULT hr = ProxyInterface->CreateEffect(rguid, lpeff, ppdeff, punkOuter);

	if (SUCCEEDED(hr) && ppdeff)
	{
		*ppdeff = new m_IDirectInputEffect(*ppdeff);
	}

	return hr;
}

HRESULT m_IDirectInputDeviceX::EnumEffectsA(LPDIENUMEFFECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwEffType)
{
	return GetProxyInterfaceA()->EnumEffects(lpCallback, pvRef, dwEffType);
}

HRESULT m_IDirectInputDeviceX::EnumEffectsW(LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType)
{
	return GetProxyInterfaceW()->EnumEffects(lpCallback, pvRef, dwEffType);
}

HRESULT m_IDirectInputDeviceX::GetEffectInfoA(LPDIEFFECTINFOA pdei, REFGUID rguid)
{
	return GetProxyInterfaceA()->GetEffectInfo(pdei, rguid);
}

HRESULT m_IDirectInputDeviceX::GetEffectInfoW(LPDIEFFECTINFOW pdei, REFGUID rguid)
{
	return GetProxyInterfaceW()->GetEffectInfo(pdei, rguid);
}

HRESULT m_IDirectInputDeviceX::GetForceFeedbackState(LPDWORD pdwOut)
{
	return ProxyInterface->GetForceFeedbackState(pdwOut);
}

HRESULT m_IDirectInputDeviceX::SendForceFeedbackCommand(DWORD dwFlags)
{
	return ProxyInterface->SendForceFeedbackCommand(dwFlags);
}

HRESULT m_IDirectInputDeviceX::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
	if (!lpCallback)
	{
		return E_INVALIDARG;
	}

	struct EnumEffect
	{
		LPVOID pvRef;
		LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback;

		static BOOL CALLBACK EnumEffectCallback(LPDIRECTINPUTEFFECT pdeff, LPVOID pvRef)
		{
			EnumEffect *self = (EnumEffect*)pvRef;

			if (pdeff)
			{
				pdeff = ProxyAddressLookupTable.FindAddress<m_IDirectInputEffect>(pdeff);
			}

			return self->lpCallback(pdeff, self->pvRef);
		}
	} CallbackContext;
	CallbackContext.pvRef = pvRef;
	CallbackContext.lpCallback = lpCallback;

	return ProxyInterface->EnumCreatedEffectObjects(EnumEffect::EnumEffectCallback, &CallbackContext, fl);
}

HRESULT m_IDirectInputDeviceX::Escape(LPDIEFFESCAPE pesc)
{
	return ProxyInterface->Escape(pesc);
}

HRESULT m_IDirectInputDeviceX::Poll()
{
	return ProxyInterface->Poll();
}

HRESULT m_IDirectInputDeviceX::SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
	return ProxyInterface->SendDeviceData(cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT m_IDirectInputDeviceX::EnumEffectsInFileA(LPCSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags)
{
	return GetProxyInterfaceA()->EnumEffectsInFile(lpszFileName, pec, pvRef, dwFlags);
}

HRESULT m_IDirectInputDeviceX::EnumEffectsInFileW(LPCWSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags)
{
	return GetProxyInterfaceW()->EnumEffectsInFile(lpszFileName, pec, pvRef, dwFlags);
}

HRESULT m_IDirectInputDeviceX::WriteEffectToFileA(LPCSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags)
{
	return GetProxyInterfaceA()->WriteEffectToFile(lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT m_IDirectInputDeviceX::WriteEffectToFileW(LPCWSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags)
{
	return GetProxyInterfaceW()->WriteEffectToFile(lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}
