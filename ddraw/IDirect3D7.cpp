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
#include "IDirect3D7.h"

m_IDirect3D7::m_IDirect3D7(IDirect3D7 * aOriginal)
{
	logf("IDirect3D7 ctor\n");
	mOriginal = aOriginal;
}

m_IDirect3D7::~m_IDirect3D7()
{
	logf("IDirect3D7 dtor\n");
}

HRESULT __stdcall m_IDirect3D7::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3D7::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirect3D7::AddRef()
{
	logf("IDirect3D7::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirect3D7::Release()
{
	logf("IDirect3D7::Release();");
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

HRESULT __stdcall m_IDirect3D7::EnumDevices(LPD3DENUMDEVICESCALLBACK7 a, LPVOID b)
{
	logf("IDirect3D7::EnumDevices(LPD3DENUMDEVICESCALLBACK7 0x%x, LPVOID 0x%x);", a, b);
	HRESULT x = mOriginal->EnumDevices(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3D7::CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE7 b, LPDIRECT3DDEVICE7 * c)
{
	logf("IDirect3D7::CreateDevice(REFCLSID, LPDIRECTDRAWSURFACE7 0x%x, LPDIRECT3DDEVICE7 * 0x%x);", b, c);
	HRESULT x = mOriginal->CreateDevice(a, (b) ? ((m_IDirectDrawSurface7 *)b)->mOriginal : 0, c);
	logf(" -> return %d\n", x);
	m_IDirect3DDevice7 * n = (m_IDirect3DDevice7 *)wrapfetch(*c);
	if (n == NULL && *c != NULL)
	{
		n = (m_IDirect3DDevice7 *)new m_IDirect3DDevice7(*c);
		wrapstore(n, *c);
		logf("Wrapped.\n");
	}
	*c = n;
	return x;
}

HRESULT __stdcall m_IDirect3D7::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC a, LPDIRECT3DVERTEXBUFFER7 * b, DWORD c)
{
	logf("IDirect3D7::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC 0x%x, LPDIRECT3DVERTEXBUFFER7 * 0x%x, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->CreateVertexBuffer(a, b, c);
	logf(" -> return %d\n", x);
	m_IDirect3DVertexBuffer7 * n = (m_IDirect3DVertexBuffer7 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (m_IDirect3DVertexBuffer7 *)new m_IDirect3DVertexBuffer7(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirect3D7::EnumZBufferFormats(REFCLSID a, LPD3DENUMPIXELFORMATSCALLBACK b, LPVOID c)
{
	logf("IDirect3D7::EnumZBufferFormats(REFCLSID, LPD3DENUMPIXELFORMATSCALLBACK 0x%x, LPVOID 0x%x);", b, c);
	HRESULT x = mOriginal->EnumZBufferFormats(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3D7::EvictManagedTextures()
{
	logf("IDirect3D7::EvictManagedTextures();");
	HRESULT x = mOriginal->EvictManagedTextures();
	logf(" -> return %d\n", x);
	return x;
}
