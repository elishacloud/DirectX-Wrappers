#pragma once

class m_IClassFactory : public IClassFactory, public AddressLookupTableObject
{
private:
	LPCLASSFACTORY ProxyInterface;

public:
	m_IClassFactory(LPCLASSFACTORY pSound8) : ProxyInterface(pSound8)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IClassFactory()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	LPCLASSFACTORY GetProxyInterface() { return ProxyInterface; }

	// IUnknown methods
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID, LPVOID *);
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();

	// IClassFactory methods
	virtual HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppvObject);
	virtual HRESULT STDMETHODCALLTYPE LockServer(BOOL fLock);
};
