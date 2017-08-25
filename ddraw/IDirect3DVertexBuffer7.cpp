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
#include "IDirect3DVertexBuffer7.h"

m_IDirect3DVertexBuffer7::m_IDirect3DVertexBuffer7(IDirect3DVertexBuffer7 * aOriginal)
{
	logf("IDirect3DVertexBuffer7 ctor\n");
	mOriginal = aOriginal;
}

m_IDirect3DVertexBuffer7::~m_IDirect3DVertexBuffer7()
{
	logf("IDirect3DVertexBuffer7 dtor\n");
}

HRESULT __stdcall m_IDirect3DVertexBuffer7::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DVertexBuffer7::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirect3DVertexBuffer7::AddRef()
{
	logf("IDirect3DVertexBuffer7::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirect3DVertexBuffer7::Release()
{
	logf("IDirect3DVertexBuffer7::Release();");
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

HRESULT __stdcall m_IDirect3DVertexBuffer7::Lock(DWORD a, LPVOID * b, LPDWORD c)
{
	logf("IDirect3DVertexBuffer7::Lock(DWORD %d, LPVOID * 0x%x, LPDWORD 0x%x);", a, b, c);
	HRESULT x = mOriginal->Lock(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DVertexBuffer7::Unlock()
{
	logf("IDirect3DVertexBuffer7::Unlock();");
	HRESULT x = mOriginal->Unlock();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DVertexBuffer7::ProcessVertices(DWORD a, DWORD b, DWORD c, LPDIRECT3DVERTEXBUFFER7 d, DWORD e, LPDIRECT3DDEVICE7 f, DWORD g)
{
	logf("IDirect3DVertexBuffer7::ProcessVertices(DWORD %d, DWORD %d, DWORD %d, LPDIRECT3DVERTEXBUFFER7 0x%x, DWORD %d, LPDIRECT3DDEVICE7 0x%x, DWORD %d);", a, b, c, d, e, f, g);
	HRESULT x = mOriginal->ProcessVertices(a, b, c, (d) ? ((m_IDirect3DVertexBuffer7 *)d)->mOriginal : 0, e, (f) ? ((m_IDirect3DDevice7 *)f)->mOriginal : 0, g);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DVertexBuffer7::GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC a)
{
	logf("IDirect3DVertexBuffer7::GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC 0x%x);", a);
	HRESULT x = mOriginal->GetVertexBufferDesc(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DVertexBuffer7::Optimize(LPDIRECT3DDEVICE7 a, DWORD b)
{
	logf("IDirect3DVertexBuffer7::Optimize(LPDIRECT3DDEVICE7 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->Optimize((a) ? ((m_IDirect3DDevice7 *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DVertexBuffer7::ProcessVerticesStrided(DWORD a, DWORD b, DWORD c, LPD3DDRAWPRIMITIVESTRIDEDDATA d, DWORD e, LPDIRECT3DDEVICE7 f, DWORD g)
{
	logf("IDirect3DVertexBuffer7::ProcessVerticesStrided(DWORD %d, DWORD %d, DWORD %d, LPD3DDRAWPRIMITIVESTRIDEDDATA 0x%x, DWORD %d, LPDIRECT3DDEVICE7 0x%x, DWORD %d);", a, b, c, d, e, f, g);
	HRESULT x = mOriginal->ProcessVerticesStrided(a, b, c, d, e, (f) ? ((m_IDirect3DDevice7 *)f)->mOriginal : 0, g);
	logf(" -> return %d\n", x);
	return x;
}
