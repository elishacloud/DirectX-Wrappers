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
#include "IDirect3DTexture.h"

myIDirect3DTexture::myIDirect3DTexture(IDirect3DTexture * aOriginal)
{
	logf("IDirect3DTexture ctor\n");
	mOriginal = aOriginal;
}

myIDirect3DTexture::~myIDirect3DTexture()
{
	logf("IDirect3DTexture dtor\n");
}

HRESULT __stdcall myIDirect3DTexture::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DTexture::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirect3DTexture::AddRef()
{
	logf("IDirect3DTexture::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirect3DTexture::Release()
{
	logf("IDirect3DTexture::Release();");
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

HRESULT __stdcall myIDirect3DTexture::Initialize(LPDIRECT3DDEVICE a, LPDIRECTDRAWSURFACE b)
{
	logf("IDirect3DTexture::Initialize(LPDIRECT3DDEVICE 0x%x, LPDIRECTDRAWSURFACE 0x%x);", a, b);
	HRESULT x = mOriginal->Initialize((a) ? ((myIDirect3DDevice *)a)->mOriginal : 0, (b) ? ((myIDirectDrawSurface *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DTexture::GetHandle(LPDIRECT3DDEVICE a, LPD3DTEXTUREHANDLE b)
{
	logf("IDirect3DTexture::GetHandle(LPDIRECT3DDEVICE 0x%x, LPD3DTEXTUREHANDLE 0x%x);", a, b);
	HRESULT x = mOriginal->GetHandle((a) ? ((myIDirect3DDevice *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DTexture::PaletteChanged(DWORD a, DWORD b)
{
	logf("IDirect3DTexture::PaletteChanged(DWORD %d, DWORD %d);", a, b);
	HRESULT x = mOriginal->PaletteChanged(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DTexture::Load(LPDIRECT3DTEXTURE a)
{
	logf("IDirect3DTexture::Load(LPDIRECT3DTEXTURE 0x%x);", a);
	HRESULT x = mOriginal->Load((a) ? ((myIDirect3DTexture *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DTexture::Unload()
{
	logf("IDirect3DTexture::Unload();");
	HRESULT x = mOriginal->Unload();
	logf(" -> return %d\n", x);
	return x;
}
