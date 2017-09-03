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
		LPDIRECTINPUTDEVICEA* temp = lplpDirectInputDevice;
		*lplpDirectInputDevice = new m_DirectInputDeviceA(*temp);
		delete temp;
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
