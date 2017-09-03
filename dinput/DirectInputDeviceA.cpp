#include "dinput.h"

HRESULT m_DirectInputDeviceA::QueryInterface(REFIID riid, LPVOID* obp)
{
	*obp = nullptr;
	HRESULT hr = m_pDInputDevice->QueryInterface(riid, obp);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

ULONG m_DirectInputDeviceA::AddRef()
{
	ULONG count = m_pDInputDevice->AddRef();
	Log() << this << " " << __FUNCTION__ << " " << count;
	return count;
}

ULONG m_DirectInputDeviceA::Release()
{
	ULONG count = m_pDInputDevice->Release();
	if (count == 0)
	{
		delete this;
	}
	Log() << this << " " << __FUNCTION__ << " " << count;
	return count;
}

HRESULT m_DirectInputDeviceA::GetCapabilities(LPDIDEVCAPS lpDIDevCaps)
{
	HRESULT hr = m_pDInputDevice->GetCapabilities(lpDIDevCaps);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->EnumObjects(lpCallback, pvRef, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
	HRESULT hr = m_pDInputDevice->GetProperty(rguidProp, pdiph);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
	HRESULT hr = m_pDInputDevice->SetProperty(rguidProp, pdiph);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::Acquire()
{
	HRESULT hr = m_pDInputDevice->Acquire();
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::Unacquire()
{
	HRESULT hr = m_pDInputDevice->Unacquire();
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
	HRESULT hr = m_pDInputDevice->GetDeviceState(cbData, lpvData);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	HRESULT hr = m_pDInputDevice->SetDataFormat(lpdf);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::SetEventNotification(HANDLE hEvent)
{
	HRESULT hr = m_pDInputDevice->SetEventNotification(hEvent);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->SetCooperativeLevel(hwnd, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::GetObjectInfo(LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow)
{
	HRESULT hr = m_pDInputDevice->GetObjectInfo(pdidoi, dwObj, dwHow);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::GetDeviceInfo(LPDIDEVICEINSTANCEA pdidi)
{
	HRESULT hr = m_pDInputDevice->GetDeviceInfo(pdidi);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	HRESULT hr = m_pDInputDevice->RunControlPanel(hwndOwner, dwFlags);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}

HRESULT m_DirectInputDeviceA::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	HRESULT hr = m_pDInputDevice->Initialize(hinst, dwVersion, rguid);
	Log() << this << " " << __FUNCTION__ << "\t" << hr;
	return hr;
}
