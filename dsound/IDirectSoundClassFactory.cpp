/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*
* Code taken from code found here: https://github.com/elishacloud/DirectSoundControl
*/

#include "dsound.h"

HRESULT m_IDirectSoundClassFactory::QueryInterface(REFIID refIID, LPVOID * pVoid)
{
	*pVoid = nullptr;

	if (refIID == IID_IClassFactory)
	{
		LPVOID pTemp;
		HRESULT hRes = m_lpClassFactory->QueryInterface(refIID, &pTemp);

		if (hRes != S_OK)
		{
			return hRes;
		}

		m_lpClassFactory = (LPCLASSFACTORY)pTemp;

		*pVoid = (LPVOID) this;

		return S_OK;
	}

	return m_lpClassFactory->QueryInterface(refIID, pVoid);
}

ULONG m_IDirectSoundClassFactory::AddRef()
{
	ULONG nRefCnt = m_lpClassFactory->AddRef();

	return nRefCnt;
}

ULONG m_IDirectSoundClassFactory::Release()
{
	ULONG nRefCnt = m_lpClassFactory->Release();

	if (nRefCnt == 0)
	{
		delete this;
		return S_OK;
	}

	return nRefCnt;
}

HRESULT m_IDirectSoundClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppvObject)
{
	*ppvObject = nullptr;

	if ((riid == IID_IDirectSound) || (riid == IID_IDirectSound8))
	{
		m_IDirectSound8* pDSX = new m_IDirectSound8;

		HRESULT hRes = m_lpClassFactory->CreateInstance(pUnkOuter, riid, (LPVOID*)&(pDSX->m_lpDirectSound8));

		if (hRes != S_OK)
		{
			delete pDSX;
			return S_FALSE;
		}

		*ppvObject = (LPDIRECTSOUND)pDSX;

		return S_OK;
	}

	return m_lpClassFactory->CreateInstance(pUnkOuter, riid, ppvObject);
}

HRESULT m_IDirectSoundClassFactory::LockServer(BOOL fLock)
{
	return m_lpClassFactory->LockServer(fLock);
}
