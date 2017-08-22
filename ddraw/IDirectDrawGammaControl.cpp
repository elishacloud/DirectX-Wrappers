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
#include "IDirectDrawGammaControl.h"

myIDirectDrawGammaControl::myIDirectDrawGammaControl(IDirectDrawGammaControl * aOriginal)
{
	logf("IDirectDrawGammaControl ctor\n");
	mOriginal = aOriginal;
}

myIDirectDrawGammaControl::~myIDirectDrawGammaControl()
{
	logf("IDirectDrawGammaControl dtor\n");
}

HRESULT __stdcall myIDirectDrawGammaControl::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDrawGammaControl::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirectDrawGammaControl::AddRef()
{
	logf("IDirectDrawGammaControl::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirectDrawGammaControl::Release()
{
	logf("IDirectDrawGammaControl::Release();");
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

HRESULT __stdcall myIDirectDrawGammaControl::GetGammaRamp(DWORD a, LPDDGAMMARAMP b)
{
	logf("IDirectDrawGammaControl::GetGammaRamp(DWORD %d, LPDDGAMMARAMP 0x%x);", a, b);
	HRESULT x = mOriginal->GetGammaRamp(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDrawGammaControl::SetGammaRamp(DWORD a, LPDDGAMMARAMP b)
{
	logf("IDirectDrawGammaControl::SetGammaRamp(DWORD %d, LPDDGAMMARAMP 0x%x);", a, b);
	HRESULT x = mOriginal->SetGammaRamp(a, b);
	logf(" -> return %d\n", x);
	return x;
}
