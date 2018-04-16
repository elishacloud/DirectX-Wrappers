#pragma once

class m_IDirectInput7W : public IDirectInput7W, public AddressLookupTableObject
{
private:
	IDirectInput7W *ProxyInterface;

public:
	m_IDirectInput7W(IDirectInput7W *aOriginal, void *temp) : ProxyInterface(aOriginal)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectInput7W()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	IDirectInput7W *GetProxyInterface() { return ProxyInterface; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirectInput2W methods ***/
	STDMETHOD(CreateDevice)(THIS_ REFGUID, LPDIRECTINPUTDEVICEW *, LPUNKNOWN);
	STDMETHOD(EnumDevices)(THIS_ DWORD, LPDIENUMDEVICESCALLBACKW, LPVOID, DWORD);
	STDMETHOD(GetDeviceStatus)(THIS_ REFGUID);
	STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
	STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD);
	STDMETHOD(FindDevice)(THIS_ REFGUID, LPCWSTR, LPGUID);

	/*** IDirectInput7W methods ***/
	STDMETHOD(CreateDeviceEx)(THIS_ REFGUID, REFIID, LPVOID *, LPUNKNOWN);
};
