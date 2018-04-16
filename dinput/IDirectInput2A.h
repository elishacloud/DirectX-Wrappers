#pragma once

class m_IDirectInput2A : public IDirectInput2A, public AddressLookupTableObject
{
private:
	IDirectInput2A *ProxyInterface;

public:
	m_IDirectInput2A(IDirectInput2A *aOriginal, void *temp) : ProxyInterface(aOriginal)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectInput2A()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	IDirectInput2A *GetProxyInterface() { return ProxyInterface; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirectInputA methods ***/
	STDMETHOD(CreateDevice)(THIS_ REFGUID, LPDIRECTINPUTDEVICEA *, LPUNKNOWN);
	STDMETHOD(EnumDevices)(THIS_ DWORD, LPDIENUMDEVICESCALLBACKA, LPVOID, DWORD);
	STDMETHOD(GetDeviceStatus)(THIS_ REFGUID);
	STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
	STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD);

	/*** IDirectInput2A methods ***/
	STDMETHOD(FindDevice)(THIS_ REFGUID, LPCSTR, LPGUID);
};
