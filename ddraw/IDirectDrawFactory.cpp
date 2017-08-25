/*
* Copyright 2013 Jari Komppa http://iki.fi/sol/
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
*
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any source
* distribution.
*
* Taken from code found here: https://github.com/jarikomppa/dxwrapper
*
* Updated 2017 by Elisha Riedlinger
*/

#include "ddraw.h"
#include "IDirectDrawFactory.h"

m_IDirectDrawFactory::m_IDirectDrawFactory(IDirectDrawFactory * aOriginal)
{
	logf("IDirectDrawFactory ctor\n");
	mOriginal = aOriginal;
}

m_IDirectDrawFactory::~m_IDirectDrawFactory()
{
	logf("IDirectDrawFactory dtor\n");
}

HRESULT __stdcall m_IDirectDrawFactory::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDrawFactory::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirectDrawFactory::AddRef()
{
	logf("IDirectDrawFactory::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirectDrawFactory::Release()
{
	logf("IDirectDrawFactory::Release();");
	ULONG x = mOriginal->Release();
	logf(" -> return %d\n", x);
	if (x == 0)
	{
		wrapstore(mOriginal, 0);
		mOriginal = NULL;
		delete this;
	}
	return x;
}

HRESULT __stdcall m_IDirectDrawFactory::CreateDirectDraw(GUID * pGUID, HWND hWnd, DWORD dwCoopLevelFlags, DWORD dwReserved, IUnknown * pUnkOuter, IDirectDraw * * ppDirectDraw)
{
	logf("IDirectDrawFactory::CreateDirectDraw(GUID *, HWND 0x%x, DWORD %d, DWORD %d, IUnknown *, IDirectDraw * *);", hWnd, dwCoopLevelFlags, dwReserved);
	HRESULT x = mOriginal->CreateDirectDraw(pGUID, hWnd, dwCoopLevelFlags, dwReserved, pUnkOuter, ppDirectDraw);
	logf(" -> return %d\n", x);
	m_IDirectDraw * n = (m_IDirectDraw *)wrapfetch(*ppDirectDraw);
	if (n == NULL && *ppDirectDraw != NULL)
	{
		n = (m_IDirectDraw *)new m_IDirectDraw(*ppDirectDraw);
		wrapstore(n, *ppDirectDraw);
		logf("Wrapped.\n");
	}
	*ppDirectDraw = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawFactory::DirectDrawEnumerate(LPDDENUMCALLBACK lpCallback, LPVOID lpContext)
{
	logf("IDirectDrawFactory::DirectDrawEnumerate(LPDDENUMCALLBACK 0x%x, LPVOID 0x%x);", lpCallback, lpContext);
	HRESULT x = mOriginal->DirectDrawEnumerate(lpCallback, lpContext);
	logf(" -> return %d\n", x);
	return x;
}
