#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Unknwnbase.h>

typedef void(WINAPI *IQueryInterfaceProc)(REFIID, LPVOID *);

class m_IClassFactory : public IClassFactory
{
private:
	IClassFactory *ProxyInterface;
	REFIID WrapperID = IID_IClassFactory;

public:
	m_IClassFactory(IClassFactory *aOriginal) : ProxyInterface(aOriginal) {}
	~m_IClassFactory() {}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj);
	STDMETHOD_(ULONG, AddRef) (THIS);
	STDMETHOD_(ULONG, Release) (THIS);

	/*** IClassFactory methods ***/
	STDMETHOD(CreateInstance)(IUnknown *pUnkOuter, REFIID riid, void **ppvObject);
	STDMETHOD(LockServer)(BOOL fLock);
};
