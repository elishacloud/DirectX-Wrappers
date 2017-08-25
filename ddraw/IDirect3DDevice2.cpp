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
#include "IDirect3DDevice2.h"

m_IDirect3DDevice2::m_IDirect3DDevice2(IDirect3DDevice2 * aOriginal)
{
	logf("IDirect3DDevice2 ctor\n");
	mOriginal = aOriginal;
}

m_IDirect3DDevice2::~m_IDirect3DDevice2()
{
	logf("IDirect3DDevice2 dtor\n");
}

HRESULT __stdcall m_IDirect3DDevice2::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DDevice2::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirect3DDevice2::AddRef()
{
	logf("IDirect3DDevice2::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirect3DDevice2::Release()
{
	logf("IDirect3DDevice2::Release();");
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

HRESULT __stdcall m_IDirect3DDevice2::GetCaps(LPD3DDEVICEDESC a, LPD3DDEVICEDESC b)
{
	logf("IDirect3DDevice2::GetCaps(LPD3DDEVICEDESC 0x%x, LPD3DDEVICEDESC 0x%x);", a, b);
	HRESULT x = mOriginal->GetCaps(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::SwapTextureHandles(LPDIRECT3DTEXTURE2 a, LPDIRECT3DTEXTURE2 b)
{
	logf("IDirect3DDevice2::SwapTextureHandles(LPDIRECT3DTEXTURE2 0x%x, LPDIRECT3DTEXTURE2 0x%x);", a, b);
	HRESULT x = mOriginal->SwapTextureHandles((a) ? ((m_IDirect3DTexture2 *)a)->mOriginal : 0, (b) ? ((m_IDirect3DTexture2 *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::GetStats(LPD3DSTATS a)
{
	logf("IDirect3DDevice2::GetStats(LPD3DSTATS 0x%x);", a);
	HRESULT x = mOriginal->GetStats(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::AddViewport(LPDIRECT3DVIEWPORT2 a)
{
	logf("IDirect3DDevice2::AddViewport(LPDIRECT3DVIEWPORT2 0x%x);", a);
	HRESULT x = mOriginal->AddViewport((a) ? ((m_IDirect3DViewport2 *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::DeleteViewport(LPDIRECT3DVIEWPORT2 a)
{
	logf("IDirect3DDevice2::DeleteViewport(LPDIRECT3DVIEWPORT2 0x%x);", a);
	HRESULT x = mOriginal->DeleteViewport((a) ? ((m_IDirect3DViewport2 *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::NextViewport(LPDIRECT3DVIEWPORT2 a, LPDIRECT3DVIEWPORT2 * b, DWORD c)
{
	logf("IDirect3DDevice2::NextViewport(LPDIRECT3DVIEWPORT2 0x%x, LPDIRECT3DVIEWPORT2 * 0x%x, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->NextViewport((a) ? ((m_IDirect3DViewport2 *)a)->mOriginal : 0, b, c);
	logf(" -> return %d\n", x);
	m_IDirect3DViewport2 * n = (m_IDirect3DViewport2 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (m_IDirect3DViewport2 *)new m_IDirect3DViewport2(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK a, LPVOID b)
{
	logf("IDirect3DDevice2::EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK 0x%x, LPVOID 0x%x);", a, b);
	HRESULT x = mOriginal->EnumTextureFormats(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::BeginScene()
{
	logf("IDirect3DDevice2::BeginScene();");
	HRESULT x = mOriginal->BeginScene();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::EndScene()
{
	logf("IDirect3DDevice2::EndScene();");
	HRESULT x = mOriginal->EndScene();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::GetDirect3D(LPDIRECT3D2 * a)
{
	logf("IDirect3DDevice2::GetDirect3D(LPDIRECT3D2 * 0x%x);", a);
	HRESULT x = mOriginal->GetDirect3D(a);
	logf(" -> return %d\n", x);
	LPDIRECT3D2 n = (LPDIRECT3D2)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (LPDIRECT3D2)new m_IDirect3D2(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::SetCurrentViewport(LPDIRECT3DVIEWPORT2 a)
{
	logf("IDirect3DDevice2::SetCurrentViewport(LPDIRECT3DVIEWPORT2 0x%x);", a);
	HRESULT x = mOriginal->SetCurrentViewport((a) ? ((m_IDirect3DViewport2 *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::GetCurrentViewport(LPDIRECT3DVIEWPORT2 * a)
{
	logf("IDirect3DDevice2::GetCurrentViewport(LPDIRECT3DVIEWPORT2 * 0x%x);", a);
	HRESULT x = mOriginal->GetCurrentViewport(a);
	logf(" -> return %d\n", x);
	m_IDirect3DViewport2 * n = (m_IDirect3DViewport2 *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (m_IDirect3DViewport2 *)new m_IDirect3DViewport2(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::SetRenderTarget(LPDIRECTDRAWSURFACE a, DWORD b)
{
	logf("IDirect3DDevice2::SetRenderTarget(LPDIRECTDRAWSURFACE 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetRenderTarget((a) ? ((m_IDirectDrawSurface *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::GetRenderTarget(LPDIRECTDRAWSURFACE * a)
{
	logf("IDirect3DDevice2::GetRenderTarget(LPDIRECTDRAWSURFACE * 0x%x);", a);
	HRESULT x = mOriginal->GetRenderTarget(a);
	logf(" -> return %d\n", x);
	LPDIRECTDRAWSURFACE n = (LPDIRECTDRAWSURFACE)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (LPDIRECTDRAWSURFACE)new m_IDirectDrawSurface(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::Begin(D3DPRIMITIVETYPE a, D3DVERTEXTYPE b, DWORD c)
{
	logf("IDirect3DDevice2::Begin(D3DPRIMITIVETYPE, D3DVERTEXTYPE, DWORD %d);", c);
	HRESULT x = mOriginal->Begin(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::BeginIndexed(D3DPRIMITIVETYPE a, D3DVERTEXTYPE b, LPVOID c, DWORD d, DWORD e)
{
	logf("IDirect3DDevice2::BeginIndexed(D3DPRIMITIVETYPE, D3DVERTEXTYPE, LPVOID 0x%x, DWORD %d, DWORD %d);", c, d, e);
	HRESULT x = mOriginal->BeginIndexed(a, b, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::Vertex(LPVOID a)
{
	logf("IDirect3DDevice2::Vertex(LPVOID 0x%x);", a);
	HRESULT x = mOriginal->Vertex(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::Index(WORD a)
{
	logf("IDirect3DDevice2::Index(WORD);");
	HRESULT x = mOriginal->Index(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::End(DWORD a)
{
	logf("IDirect3DDevice2::End(DWORD %d);", a);
	HRESULT x = mOriginal->End(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::GetRenderState(D3DRENDERSTATETYPE a, LPDWORD b)
{
	logf("IDirect3DDevice2::GetRenderState(D3DRENDERSTATETYPE, LPDWORD 0x%x);", b);
	HRESULT x = mOriginal->GetRenderState(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::SetRenderState(D3DRENDERSTATETYPE a, DWORD b)
{
	logf("IDirect3DDevice2::SetRenderState(D3DRENDERSTATETYPE, DWORD %d);", b);
	HRESULT x = mOriginal->SetRenderState(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::GetLightState(D3DLIGHTSTATETYPE a, LPDWORD b)
{
	logf("IDirect3DDevice2::GetLightState(D3DLIGHTSTATETYPE, LPDWORD 0x%x);", b);
	HRESULT x = mOriginal->GetLightState(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::SetLightState(D3DLIGHTSTATETYPE a, DWORD b)
{
	logf("IDirect3DDevice2::SetLightState(D3DLIGHTSTATETYPE, DWORD %d);", b);
	HRESULT x = mOriginal->SetLightState(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::SetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b)
{
	logf("IDirect3DDevice2::SetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX 0x%x);", b);
	HRESULT x = mOriginal->SetTransform(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::GetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b)
{
	logf("IDirect3DDevice2::GetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX 0x%x);", b);
	HRESULT x = mOriginal->GetTransform(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::MultiplyTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b)
{
	logf("IDirect3DDevice2::MultiplyTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX 0x%x);", b);
	HRESULT x = mOriginal->MultiplyTransform(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::DrawPrimitive(D3DPRIMITIVETYPE a, D3DVERTEXTYPE b, LPVOID c, DWORD d, DWORD e)
{
	logf("IDirect3DDevice2::DrawPrimitive(D3DPRIMITIVETYPE, D3DVERTEXTYPE, LPVOID 0x%x, DWORD %d, DWORD %d);", c, d, e);
	HRESULT x = mOriginal->DrawPrimitive(a, b, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::DrawIndexedPrimitive(D3DPRIMITIVETYPE a, D3DVERTEXTYPE b, LPVOID c, DWORD d, LPWORD e, DWORD f, DWORD g)
{
	logf("IDirect3DDevice2::DrawIndexedPrimitive(D3DPRIMITIVETYPE, D3DVERTEXTYPE, LPVOID 0x%x, DWORD %d, LPWORD 0x%x, DWORD %d, DWORD %d);", c, d, e, f, g);
	HRESULT x = mOriginal->DrawIndexedPrimitive(a, b, c, d, e, f, g);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::SetClipStatus(LPD3DCLIPSTATUS a)
{
	logf("IDirect3DDevice2::SetClipStatus(LPD3DCLIPSTATUS 0x%x);", a);
	HRESULT x = mOriginal->SetClipStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DDevice2::GetClipStatus(LPD3DCLIPSTATUS a)
{
	logf("IDirect3DDevice2::GetClipStatus(LPD3DCLIPSTATUS 0x%x);", a);
	HRESULT x = mOriginal->GetClipStatus(a);
	logf(" -> return %d\n", x);
	return x;
}
