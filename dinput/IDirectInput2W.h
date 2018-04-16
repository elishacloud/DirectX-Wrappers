#pragma once

class m_IDirectInput2W : public IDirectInput2W, public AddressLookupTableObject
{
private:
	IDirectInput2W *ProxyInterface;

public:
	m_IDirectInput2W(IDirectInput2W *aOriginal, void *temp) : ProxyInterface(aOriginal)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectInput2W()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	IDirectInput2W *GetProxyInterface() { return ProxyInterface; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirectInputW methods ***/
	STDMETHOD(CreateDevice)(THIS_ REFGUID, LPDIRECTINPUTDEVICEW *, LPUNKNOWN);
	STDMETHOD(EnumDevices)(THIS_ DWORD, LPDIENUMDEVICESCALLBACKW, LPVOID, DWORD);
	STDMETHOD(GetDeviceStatus)(THIS_ REFGUID);
	STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
	STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD);

	/*** IDirectInput2W methods ***/
	STDMETHOD(FindDevice)(THIS_ REFGUID, LPCWSTR, LPGUID);
};
