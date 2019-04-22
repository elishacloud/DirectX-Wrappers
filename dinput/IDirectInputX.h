#pragma once

class m_IDirectInputX
{
private:
	IDirectInput7W *ProxyInterface;
	m_IDirectInput7W *WrapperInterface;
	DWORD DirectXVersion;
	REFIID WrapperID;

public:
	m_IDirectInputX(IDirectInput7W *aOriginal, DWORD Version, REFIID riid, m_IDirectInput7W *Interface) : ProxyInterface(aOriginal), DirectXVersion(Version), WrapperID(riid), WrapperInterface(Interface) {}
	~m_IDirectInputX() {}

	DWORD GetDirectXVersion() { return DDWRAPPER_TYPEX; }
	REFIID GetWrapperType() { return WrapperID; }
	IDirectInput7W *GetProxyInterface() { return ProxyInterface; }
	m_IDirectInput7W *GetWrapperInterface() { return WrapperInterface; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirectInput methods ***/
	STDMETHOD(CreateDeviceA)(THIS_ REFGUID, LPDIRECTINPUTDEVICEA *, LPUNKNOWN);
	STDMETHOD(CreateDeviceW)(THIS_ REFGUID, LPDIRECTINPUTDEVICEW *, LPUNKNOWN);
	STDMETHOD(EnumDevicesA)(THIS_ DWORD, LPDIENUMDEVICESCALLBACKA, LPVOID, DWORD);
	STDMETHOD(EnumDevicesW)(THIS_ DWORD, LPDIENUMDEVICESCALLBACKW, LPVOID, DWORD);
	STDMETHOD(GetDeviceStatus)(THIS_ REFGUID);
	STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
	STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD);

	/*** IDirectInput2 methods ***/
	STDMETHOD(FindDeviceA)(THIS_ REFGUID, LPCSTR, LPGUID);
	STDMETHOD(FindDeviceW)(THIS_ REFGUID, LPCWSTR, LPGUID);

	/*** IDirectInput7 methods ***/
	STDMETHOD(CreateDeviceEx)(THIS_ REFGUID rguid, REFIID riid, LPVOID *ppvObj, LPUNKNOWN pUnkOuter);

	// Helper functions
	IDirectInput7A *GetProxyInterfaceA() { return (IDirectInput7A*)ProxyInterface; }
	IDirectInput7W *GetProxyInterfaceW() { return ProxyInterface; }
};
