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
#include "IDirect3DViewport.h"

m_IDirect3DViewport::m_IDirect3DViewport(IDirect3DViewport * aOriginal)
{
	logf("IDirect3DViewport ctor\n");
	mOriginal = aOriginal;
}

m_IDirect3DViewport::~m_IDirect3DViewport()
{
	logf("IDirect3DViewport dtor\n");
}

HRESULT __stdcall m_IDirect3DViewport::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DViewport::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirect3DViewport::AddRef()
{
	logf("IDirect3DViewport::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirect3DViewport::Release()
{
	logf("IDirect3DViewport::Release();");
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

HRESULT __stdcall m_IDirect3DViewport::Initialize(LPDIRECT3D a)
{
	logf("IDirect3DViewport::Initialize(LPDIRECT3D 0x%x);", a);
	HRESULT x = mOriginal->Initialize((a) ? ((m_IDirect3D *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::GetViewport(LPD3DVIEWPORT a)
{
	logf("IDirect3DViewport::GetViewport(LPD3DVIEWPORT 0x%x);", a);
	HRESULT x = mOriginal->GetViewport(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::SetViewport(LPD3DVIEWPORT a)
{
	logf("IDirect3DViewport::SetViewport(LPD3DVIEWPORT 0x%x);", a);
	HRESULT x = mOriginal->SetViewport(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::TransformVertices(DWORD a, LPD3DTRANSFORMDATA b, DWORD c, LPDWORD d)
{
	logf("IDirect3DViewport::TransformVertices(DWORD %d, LPD3DTRANSFORMDATA 0x%x, DWORD %d, LPDWORD 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->TransformVertices(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::LightElements(DWORD a, LPD3DLIGHTDATA b)
{
	logf("IDirect3DViewport::LightElements(DWORD %d, LPD3DLIGHTDATA 0x%x);", a, b);
	HRESULT x = mOriginal->LightElements(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::SetBackground(D3DMATERIALHANDLE a)
{
	logf("IDirect3DViewport::SetBackground(D3DMATERIALHANDLE);");
	HRESULT x = mOriginal->SetBackground(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::GetBackground(LPD3DMATERIALHANDLE a, LPBOOL b)
{
	logf("IDirect3DViewport::GetBackground(LPD3DMATERIALHANDLE 0x%x, LPBOOL 0x%x);", a, b);
	HRESULT x = mOriginal->GetBackground(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::SetBackgroundDepth(LPDIRECTDRAWSURFACE a)
{
	logf("IDirect3DViewport::SetBackgroundDepth(LPDIRECTDRAWSURFACE 0x%x);", a);
	HRESULT x = mOriginal->SetBackgroundDepth((a) ? ((m_IDirectDrawSurface *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::GetBackgroundDepth(LPDIRECTDRAWSURFACE * a, LPBOOL b)
{
	logf("IDirect3DViewport::GetBackgroundDepth(LPDIRECTDRAWSURFACE * 0x%x, LPBOOL 0x%x);", a, b);
	HRESULT x = mOriginal->GetBackgroundDepth(a, b);
	logf(" -> return %d\n", x);
	m_IDirectDrawSurface * n = (m_IDirectDrawSurface *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (m_IDirectDrawSurface *)new m_IDirectDrawSurface(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::Clear(DWORD a, LPD3DRECT b, DWORD c)
{
	logf("IDirect3DViewport::Clear(DWORD %d, LPD3DRECT 0x%x, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->Clear(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::AddLight(LPDIRECT3DLIGHT a)
{
	logf("IDirect3DViewport::AddLight(LPDIRECT3DLIGHT 0x%x);", a);
	HRESULT x = mOriginal->AddLight((a) ? ((m_IDirect3DLight *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::DeleteLight(LPDIRECT3DLIGHT a)
{
	logf("IDirect3DViewport::DeleteLight(LPDIRECT3DLIGHT 0x%x);", a);
	HRESULT x = mOriginal->DeleteLight((a) ? ((m_IDirect3DLight *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DViewport::NextLight(LPDIRECT3DLIGHT a, LPDIRECT3DLIGHT * b, DWORD c)
{
	logf("IDirect3DViewport::NextLight(LPDIRECT3DLIGHT 0x%x, LPDIRECT3DLIGHT * 0x%x, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->NextLight((a) ? ((m_IDirect3DLight *)a)->mOriginal : 0, b, c);
	logf(" -> return %d\n", x);
	m_IDirect3DLight * n = (m_IDirect3DLight *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (m_IDirect3DLight *)new m_IDirect3DLight(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}
