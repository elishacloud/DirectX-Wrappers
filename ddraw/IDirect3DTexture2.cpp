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
#include "IDirect3DTexture2.h"

m_IDirect3DTexture2::m_IDirect3DTexture2(IDirect3DTexture2 * aOriginal)
{
	logf("IDirect3DTexture2 ctor\n");
	mOriginal = aOriginal;
}

m_IDirect3DTexture2::~m_IDirect3DTexture2()
{
	logf("IDirect3DTexture2 dtor\n");
}

HRESULT __stdcall m_IDirect3DTexture2::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DTexture2::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirect3DTexture2::AddRef()
{
	logf("IDirect3DTexture2::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirect3DTexture2::Release()
{
	logf("IDirect3DTexture2::Release();");
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

HRESULT __stdcall m_IDirect3DTexture2::GetHandle(LPDIRECT3DDEVICE2 a, LPD3DTEXTUREHANDLE b)
{
	logf("IDirect3DTexture2::GetHandle(LPDIRECT3DDEVICE2 0x%x, LPD3DTEXTUREHANDLE 0x%x);", a, b);
	HRESULT x = mOriginal->GetHandle((a) ? ((m_IDirect3DDevice2 *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DTexture2::PaletteChanged(DWORD a, DWORD b)
{
	logf("IDirect3DTexture2::PaletteChanged(DWORD %d, DWORD %d);", a, b);
	HRESULT x = mOriginal->PaletteChanged(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DTexture2::Load(LPDIRECT3DTEXTURE2 a)
{
	logf("IDirect3DTexture2::Load(LPDIRECT3DTEXTURE2 0x%x);", a);
	HRESULT x = mOriginal->Load((a) ? ((m_IDirect3DTexture2 *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}
