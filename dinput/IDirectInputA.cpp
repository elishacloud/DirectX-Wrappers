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

HRESULT m_DirectInputA::CreateDevice(REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
	char *str = "Unknown";
	if (rguid == GUID_SysKeyboard)
	{
		str = "SysKeyboard";
	}
	else if (rguid == GUID_SysMouse)
	{
		str = "SysMouse";
	}
	HRESULT hr = m_pDInput->CreateDevice(rguid, lplpDirectInputDevice, pUnkOuter);
	if (SUCCEEDED(hr))
	{
		LPDIRECTINPUTDEVICEA* pDIDX = lplpDirectInputDevice;
		*lplpDirectInputDevice = new m_DirectInputDeviceA(*pDIDX);
		delete pDIDX;
	}
	Log() << this << " " << __FUNCTION__ << " " << str << "\t" << hr;
	return hr;
}

ULONG m_DirectInputA::AddRef()
{
	ULONG count = m_pDInput->AddRef();
	Log() << this << " " << __FUNCTION__ << " " << count;
	return count;
}

ULONG m_DirectInputA::Release()
{
	ULONG count = m_pDInput->Release();
	if (count == 0)
	{
		delete this;
	}
	Log() << this << " " << __FUNCTION__ << " " << count;
	return count;
}

HRESULT m_DirectInputA::QueryInterface(REFIID riid, LPVOID* obp)
{
	*obp = nullptr;
	HRESULT hr = m_pDInput->QueryInterface(riid, obp);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputA::EnumDevices(DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	HRESULT hr = m_pDInput->EnumDevices(dwDevType, lpCallback, pvRef, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputA::GetDeviceStatus(REFGUID rguidInstance)
{
	HRESULT hr = m_pDInput->GetDeviceStatus(rguidInstance);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputA::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	HRESULT hr = m_pDInput->RunControlPanel(hwndOwner, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputA::Initialize(HINSTANCE hinst, DWORD dwVersion)
{
	HRESULT hr = m_pDInput->Initialize(hinst, dwVersion);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}
