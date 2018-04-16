#pragma once

class m_IDirectInputDevice2A : public IDirectInputDevice2A, public AddressLookupTableObject
{
private:
	IDirectInputDevice2A *ProxyInterface;

public:
	m_IDirectInputDevice2A(IDirectInputDevice2A *aOriginal, void *temp) : ProxyInterface(aOriginal)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectInputDevice2A()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	IDirectInputDevice2A *GetProxyInterface() { return ProxyInterface; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirectInputDeviceA methods ***/
	STDMETHOD(GetCapabilities)(THIS_ LPDIDEVCAPS);
	STDMETHOD(EnumObjects)(THIS_ LPDIENUMDEVICEOBJECTSCALLBACKA, LPVOID, DWORD);
	STDMETHOD(GetProperty)(THIS_ REFGUID, LPDIPROPHEADER);
	STDMETHOD(SetProperty)(THIS_ REFGUID, LPCDIPROPHEADER);
	STDMETHOD(Acquire)(THIS);
	STDMETHOD(Unacquire)(THIS);
	STDMETHOD(GetDeviceState)(THIS_ DWORD, LPVOID);
	STDMETHOD(GetDeviceData)(THIS_ DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
	STDMETHOD(SetDataFormat)(THIS_ LPCDIDATAFORMAT);
	STDMETHOD(SetEventNotification)(THIS_ HANDLE);
	STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD);
	STDMETHOD(GetObjectInfo)(THIS_ LPDIDEVICEOBJECTINSTANCEA, DWORD, DWORD);
	STDMETHOD(GetDeviceInfo)(THIS_ LPDIDEVICEINSTANCEA);
	STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
	STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD, REFGUID);

	/*** IDirectInputDevice2A methods ***/
	STDMETHOD(CreateEffect)(THIS_ REFGUID, LPCDIEFFECT, LPDIRECTINPUTEFFECT *, LPUNKNOWN);
	STDMETHOD(EnumEffects)(THIS_ LPDIENUMEFFECTSCALLBACKA, LPVOID, DWORD);
	STDMETHOD(GetEffectInfo)(THIS_ LPDIEFFECTINFOA, REFGUID);
	STDMETHOD(GetForceFeedbackState)(THIS_ LPDWORD);
	STDMETHOD(SendForceFeedbackCommand)(THIS_ DWORD);
	STDMETHOD(EnumCreatedEffectObjects)(THIS_ LPDIENUMCREATEDEFFECTOBJECTSCALLBACK, LPVOID, DWORD);
	STDMETHOD(Escape)(THIS_ LPDIEFFESCAPE);
	STDMETHOD(Poll)(THIS);
	STDMETHOD(SendDeviceData)(THIS_ DWORD, LPCDIDEVICEOBJECTDATA, LPDWORD, DWORD);
};
