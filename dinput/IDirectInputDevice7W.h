#pragma once

class m_IDirectInputDevice7W : public IDirectInputDevice7W, public AddressLookupTableObject
{
private:
	IDirectInputDevice7W *ProxyInterface;

public:
	m_IDirectInputDevice7W(IDirectInputDevice7W *aOriginal, void *temp) : ProxyInterface(aOriginal)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectInputDevice7W()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	IDirectInputDevice7W *GetProxyInterface() { return ProxyInterface; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirectInputDevice2W methods ***/
	STDMETHOD(GetCapabilities)(THIS_ LPDIDEVCAPS);
	STDMETHOD(EnumObjects)(THIS_ LPDIENUMDEVICEOBJECTSCALLBACKW, LPVOID, DWORD);
	STDMETHOD(GetProperty)(THIS_ REFGUID, LPDIPROPHEADER);
	STDMETHOD(SetProperty)(THIS_ REFGUID, LPCDIPROPHEADER);
	STDMETHOD(Acquire)(THIS);
	STDMETHOD(Unacquire)(THIS);
	STDMETHOD(GetDeviceState)(THIS_ DWORD, LPVOID);
	STDMETHOD(GetDeviceData)(THIS_ DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
	STDMETHOD(SetDataFormat)(THIS_ LPCDIDATAFORMAT);
	STDMETHOD(SetEventNotification)(THIS_ HANDLE);
	STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD);
	STDMETHOD(GetObjectInfo)(THIS_ LPDIDEVICEOBJECTINSTANCEW, DWORD, DWORD);
	STDMETHOD(GetDeviceInfo)(THIS_ LPDIDEVICEINSTANCEW);
	STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
	STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD, REFGUID);
	STDMETHOD(CreateEffect)(THIS_ REFGUID, LPCDIEFFECT, LPDIRECTINPUTEFFECT *, LPUNKNOWN);
	STDMETHOD(EnumEffects)(THIS_ LPDIENUMEFFECTSCALLBACKW, LPVOID, DWORD);
	STDMETHOD(GetEffectInfo)(THIS_ LPDIEFFECTINFOW, REFGUID);
	STDMETHOD(GetForceFeedbackState)(THIS_ LPDWORD);
	STDMETHOD(SendForceFeedbackCommand)(THIS_ DWORD);
	STDMETHOD(EnumCreatedEffectObjects)(THIS_ LPDIENUMCREATEDEFFECTOBJECTSCALLBACK, LPVOID, DWORD);
	STDMETHOD(Escape)(THIS_ LPDIEFFESCAPE);
	STDMETHOD(Poll)(THIS);
	STDMETHOD(SendDeviceData)(THIS_ DWORD, LPCDIDEVICEOBJECTDATA, LPDWORD, DWORD);

	/*** IDirectInputDevice7W methods ***/
	STDMETHOD(EnumEffectsInFile)(THIS_ LPCWSTR, LPDIENUMEFFECTSINFILECALLBACK, LPVOID, DWORD);
	STDMETHOD(WriteEffectToFile)(THIS_ LPCWSTR, DWORD, LPDIFILEEFFECT, DWORD);
};
