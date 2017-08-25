#pragma once

class m_IDirectSoundClassFactory : public IClassFactory
{
public:
	virtual HRESULT __stdcall QueryInterface(REFIID, LPVOID *);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	virtual HRESULT __stdcall CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppvObject);
	virtual HRESULT __stdcall LockServer(BOOL fLock);

	LPCLASSFACTORY m_lpClassFactory = nullptr;
};
