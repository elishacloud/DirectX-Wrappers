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
* Code taken from code found here: https://github.com/JeremyAnsel/xwa_hooks/tree/master/DInputLogger
*/

#include "dinput.h"

HRESULT m_DirectInputDeviceW::QueryInterface(REFIID riid, LPVOID* obp)
{
	*obp = nullptr;
	HRESULT hr = m_pDInputDevice->QueryInterface(riid, obp);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

ULONG m_DirectInputDeviceW::AddRef()
{
	ULONG count = m_pDInputDevice->AddRef();
	Log() << this << " " << __FUNCTION__ << " " << count;
	return count;
}

ULONG m_DirectInputDeviceW::Release()
{
	ULONG count = m_pDInputDevice->Release();
	if (count == 0)
	{
		delete this;
	}
	Log() << this << " " << __FUNCTION__ << " " << count;
	return count;
}

HRESULT m_DirectInputDeviceW::GetCapabilities(LPDIDEVCAPS lpDIDevCaps)
{
	HRESULT hr = m_pDInputDevice->GetCapabilities(lpDIDevCaps);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->EnumObjects(lpCallback, pvRef, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
	HRESULT hr = m_pDInputDevice->GetProperty(rguidProp, pdiph);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
	HRESULT hr = m_pDInputDevice->SetProperty(rguidProp, pdiph);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::Acquire()
{
	HRESULT hr = m_pDInputDevice->Acquire();
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::Unacquire()
{
	HRESULT hr = m_pDInputDevice->Unacquire();
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
	HRESULT hr = m_pDInputDevice->GetDeviceState(cbData, lpvData);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	HRESULT hr = m_pDInputDevice->SetDataFormat(lpdf);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::SetEventNotification(HANDLE hEvent)
{
	HRESULT hr = m_pDInputDevice->SetEventNotification(hEvent);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->SetCooperativeLevel(hwnd, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::GetObjectInfo(LPDIDEVICEOBJECTINSTANCEW pdidoi, DWORD dwObj, DWORD dwHow)
{
	HRESULT hr = m_pDInputDevice->GetObjectInfo(pdidoi, dwObj, dwHow);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::GetDeviceInfo(LPDIDEVICEINSTANCEW pdidi)
{
	HRESULT hr = m_pDInputDevice->GetDeviceInfo(pdidi);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->RunControlPanel(hwndOwner, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	HRESULT hr = m_pDInputDevice->Initialize(hinst, dwVersion, rguid);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

/*HRESULT m_DirectInputDeviceW::CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
	HRESULT hr = m_pDInputDevice->CreateEffect(rguid, lpeff, ppdeff, punkOuter);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::EnumEffects(LPDIENUMEFFECTSCALLBACKW lpCallback, LPVOID pvRef, DWORD dwEffType)
{
	HRESULT hr = m_pDInputDevice->EnumEffects(lpCallback, pvRef, dwEffType);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::GetEffectInfo(LPDIEFFECTINFOW pdei, REFGUID rguid)
{
	HRESULT hr = m_pDInputDevice->GetEffectInfo(pdei, rguid);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::GetForceFeedbackState(LPDWORD pdwOut)
{
	HRESULT hr = m_pDInputDevice->GetForceFeedbackState(pdwOut);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::SendForceFeedbackCommand(DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->SendForceFeedbackCommand(dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
	HRESULT hr = m_pDInputDevice->EnumCreatedEffectObjects(lpCallback, pvRef, fl);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::Escape(LPDIEFFESCAPE pesc)
{
	HRESULT hr = m_pDInputDevice->Escape(pesc);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::Poll()
{
	HRESULT hr = m_pDInputDevice->Poll();
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
	HRESULT hr = m_pDInputDevice->SendDeviceData(cbObjectData, rgdod, pdwInOut, fl);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::EnumEffectsInFile(LPCWSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->EnumEffectsInFile(lpszFileName, pec, pvRef, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::WriteEffectToFile(LPCWSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->WriteEffectToFile(lpszFileName, dwEntries, rgDiFileEft, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::BuildActionMap(LPDIACTIONFORMATW lpdiaf, LPCWSTR lpszUserName, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->BuildActionMap(lpdiaf, lpszUserName, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::SetActionMap(LPDIACTIONFORMATW lpdiActionFormat, LPCWSTR lptszUserName, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->SetActionMap(lpdiActionFormat, lptszUserName, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceW::GetImageInfo(LPDIDEVICEIMAGEINFOHEADERW lpdiDevImageInfoHeader)
{
	HRESULT hr = m_pDInputDevice->GetImageInfo(lpdiDevImageInfoHeader);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}*/
