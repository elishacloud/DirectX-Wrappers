#pragma once

class m_IDirectDrawGammaControl : public IDirectDrawGammaControl, public AddressLookupTableObject
{
private:
	IDirectDrawGammaControl *ProxyInterface;

public:
	m_IDirectDrawGammaControl(IDirectDrawGammaControl *aOriginal, void *temp) : ProxyInterface(aOriginal)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectDrawGammaControl()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	IDirectDrawGammaControl *GetProxyInterface() { return ProxyInterface; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj);
	STDMETHOD_(ULONG, AddRef) (THIS) ;
	STDMETHOD_(ULONG, Release) (THIS);
	/*** IDirectDrawGammaControl methods ***/
	STDMETHOD(GetGammaRamp)(THIS_ DWORD, LPDDGAMMARAMP);
	STDMETHOD(SetGammaRamp)(THIS_ DWORD, LPDDGAMMARAMP);
};
