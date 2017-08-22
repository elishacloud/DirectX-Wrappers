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
#include "IDirectDrawPalette.h"

myIDirectDrawPalette::myIDirectDrawPalette(IDirectDrawPalette * aOriginal)
{
	logf("IDirectDrawPalette ctor\n");
	mOriginal = aOriginal;
}

myIDirectDrawPalette::~myIDirectDrawPalette()
{
	logf("IDirectDrawPalette dtor\n");
}

HRESULT __stdcall myIDirectDrawPalette::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDrawPalette::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirectDrawPalette::AddRef()
{
	logf("IDirectDrawPalette::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirectDrawPalette::Release()
{
	logf("IDirectDrawPalette::Release();");
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

HRESULT __stdcall myIDirectDrawPalette::GetCaps(LPDWORD a)
{
	logf("IDirectDrawPalette::GetCaps(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetCaps(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDrawPalette::GetEntries(DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d)
{
	logf("IDirectDrawPalette::GetEntries(DWORD %d, DWORD %d, DWORD %d, LPPALETTEENTRY 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->GetEntries(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDrawPalette::Initialize(LPDIRECTDRAW a, DWORD b, LPPALETTEENTRY c)
{
	logf("IDirectDrawPalette::Initialize(LPDIRECTDRAW 0x%x, DWORD %d, LPPALETTEENTRY 0x%x);", a, b, c);
	HRESULT x = mOriginal->Initialize((a) ? ((myIDirectDraw *)a)->mOriginal : 0, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDrawPalette::SetEntries(DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d)
{
	logf("IDirectDrawPalette::SetEntries(DWORD %d, DWORD %d, DWORD %d, LPPALETTEENTRY 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->SetEntries(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}
