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
#include "IDirect3DDevice7.h"

myIDirect3DDevice7::myIDirect3DDevice7(IDirect3DDevice7 * aOriginal)
{
	logf("IDirect3DDevice7 ctor\n");
	mOriginal = aOriginal;
}

myIDirect3DDevice7::~myIDirect3DDevice7()
{
	logf("IDirect3DDevice7 dtor\n");
}

HRESULT __stdcall myIDirect3DDevice7::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DDevice7::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirect3DDevice7::AddRef()
{
	logf("IDirect3DDevice7::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirect3DDevice7::Release()
{
	logf("IDirect3DDevice7::Release();");
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

HRESULT __stdcall myIDirect3DDevice7::GetCaps(LPD3DDEVICEDESC7 a)
{
	logf("IDirect3DDevice7::GetCaps(LPD3DDEVICEDESC7 0x%x);", a);
	HRESULT x = mOriginal->GetCaps(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::EnumTextureFormats(LPD3DENUMPIXELFORMATSCALLBACK a, LPVOID b)
{
	logf("IDirect3DDevice7::EnumTextureFormats(LPD3DENUMPIXELFORMATSCALLBACK 0x%x, LPVOID 0x%x);", a, b);
	HRESULT x = mOriginal->EnumTextureFormats(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::BeginScene()
{
	logf("IDirect3DDevice7::BeginScene();");
	HRESULT x = mOriginal->BeginScene();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::EndScene()
{
	logf("IDirect3DDevice7::EndScene();");
	HRESULT x = mOriginal->EndScene();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetDirect3D(LPDIRECT3D7 * a)
{
	logf("IDirect3DDevice7::GetDirect3D(LPDIRECT3D7 * 0x%x);", a);
	HRESULT x = mOriginal->GetDirect3D(a);
	logf(" -> return %d\n", x);
	LPDIRECT3D7 n = (LPDIRECT3D7)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (LPDIRECT3D7)new myIDirect3D7(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetRenderTarget(LPDIRECTDRAWSURFACE7 a, DWORD b)
{
	logf("IDirect3DDevice7::SetRenderTarget(LPDIRECTDRAWSURFACE7 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetRenderTarget((a) ? ((myIDirectDrawSurface7 *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetRenderTarget(LPDIRECTDRAWSURFACE7 * a)
{
	logf("IDirect3DDevice7::GetRenderTarget(LPDIRECTDRAWSURFACE7 * 0x%x);", a);
	HRESULT x = mOriginal->GetRenderTarget(a);
	logf(" -> return %d\n", x);
	LPDIRECTDRAWSURFACE7 n = (LPDIRECTDRAWSURFACE7)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (LPDIRECTDRAWSURFACE7)new myIDirectDrawSurface7(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::Clear(DWORD a, LPD3DRECT b, DWORD c, D3DCOLOR d, D3DVALUE e, DWORD f)
{
	logf("IDirect3DDevice7::Clear(DWORD %d, LPD3DRECT 0x%x, DWORD %d, D3DCOLOR, D3DVALUE, DWORD %d);", a, b, c, f);
	HRESULT x = mOriginal->Clear(a, b, c, d, e, f);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b)
{
	logf("IDirect3DDevice7::SetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX 0x%x);", b);
	HRESULT x = mOriginal->SetTransform(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b)
{
	logf("IDirect3DDevice7::GetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX 0x%x);", b);
	HRESULT x = mOriginal->GetTransform(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetViewport(LPD3DVIEWPORT7 a)
{
	logf("IDirect3DDevice7::SetViewport(LPD3DVIEWPORT7 0x%x);", a);
	HRESULT x = mOriginal->SetViewport(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::MultiplyTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b)
{
	logf("IDirect3DDevice7::MultiplyTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX 0x%x);", b);
	HRESULT x = mOriginal->MultiplyTransform(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetViewport(LPD3DVIEWPORT7 a)
{
	logf("IDirect3DDevice7::GetViewport(LPD3DVIEWPORT7 0x%x);", a);
	HRESULT x = mOriginal->GetViewport(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetMaterial(LPD3DMATERIAL7 a)
{
	logf("IDirect3DDevice7::SetMaterial(LPD3DMATERIAL7 0x%x);", a);
	HRESULT x = mOriginal->SetMaterial(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetMaterial(LPD3DMATERIAL7 a)
{
	logf("IDirect3DDevice7::GetMaterial(LPD3DMATERIAL7 0x%x);", a);
	HRESULT x = mOriginal->GetMaterial(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetLight(DWORD a, LPD3DLIGHT7 b)
{
	logf("IDirect3DDevice7::SetLight(DWORD %d, LPD3DLIGHT7 0x%x);", a, b);
	HRESULT x = mOriginal->SetLight(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetLight(DWORD a, LPD3DLIGHT7 b)
{
	logf("IDirect3DDevice7::GetLight(DWORD %d, LPD3DLIGHT7 0x%x);", a, b);
	HRESULT x = mOriginal->GetLight(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetRenderState(D3DRENDERSTATETYPE a, DWORD b)
{
	logf("IDirect3DDevice7::SetRenderState(D3DRENDERSTATETYPE, DWORD %d);", b);
	HRESULT x = mOriginal->SetRenderState(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetRenderState(D3DRENDERSTATETYPE a, LPDWORD b)
{
	logf("IDirect3DDevice7::GetRenderState(D3DRENDERSTATETYPE, LPDWORD 0x%x);", b);
	HRESULT x = mOriginal->GetRenderState(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::BeginStateBlock()
{
	logf("IDirect3DDevice7::BeginStateBlock();");
	HRESULT x = mOriginal->BeginStateBlock();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::EndStateBlock(LPDWORD a)
{
	logf("IDirect3DDevice7::EndStateBlock(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->EndStateBlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::PreLoad(LPDIRECTDRAWSURFACE7 a)
{
	logf("IDirect3DDevice7::PreLoad(LPDIRECTDRAWSURFACE7 0x%x);", a);
	HRESULT x = mOriginal->PreLoad((a) ? ((myIDirectDrawSurface7 *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::DrawPrimitive(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, DWORD e)
{
	logf("IDirect3DDevice7::DrawPrimitive(D3DPRIMITIVETYPE, DWORD %d, LPVOID 0x%x, DWORD %d, DWORD %d);", b, c, d, e);
	HRESULT x = mOriginal->DrawPrimitive(a, b, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::DrawIndexedPrimitive(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, LPWORD e, DWORD f, DWORD g)
{
	logf("IDirect3DDevice7::DrawIndexedPrimitive(D3DPRIMITIVETYPE, DWORD %d, LPVOID 0x%x, DWORD %d, LPWORD 0x%x, DWORD %d, DWORD %d);", b, c, d, e, f, g);
	HRESULT x = mOriginal->DrawIndexedPrimitive(a, b, c, d, e, f, g);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetClipStatus(LPD3DCLIPSTATUS a)
{
	logf("IDirect3DDevice7::SetClipStatus(LPD3DCLIPSTATUS 0x%x);", a);
	HRESULT x = mOriginal->SetClipStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetClipStatus(LPD3DCLIPSTATUS a)
{
	logf("IDirect3DDevice7::GetClipStatus(LPD3DCLIPSTATUS 0x%x);", a);
	HRESULT x = mOriginal->GetClipStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::DrawPrimitiveStrided(D3DPRIMITIVETYPE a, DWORD b, LPD3DDRAWPRIMITIVESTRIDEDDATA c, DWORD d, DWORD e)
{
	logf("IDirect3DDevice7::DrawPrimitiveStrided(D3DPRIMITIVETYPE, DWORD %d, LPD3DDRAWPRIMITIVESTRIDEDDATA 0x%x, DWORD %d, DWORD %d);", b, c, d, e);
	HRESULT x = mOriginal->DrawPrimitiveStrided(a, b, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::DrawIndexedPrimitiveStrided(D3DPRIMITIVETYPE a, DWORD b, LPD3DDRAWPRIMITIVESTRIDEDDATA c, DWORD d, LPWORD e, DWORD f, DWORD g)
{
	logf("IDirect3DDevice7::DrawIndexedPrimitiveStrided(D3DPRIMITIVETYPE, DWORD %d, LPD3DDRAWPRIMITIVESTRIDEDDATA 0x%x, DWORD %d, LPWORD 0x%x, DWORD %d, DWORD %d);", b, c, d, e, f, g);
	HRESULT x = mOriginal->DrawIndexedPrimitiveStrided(a, b, c, d, e, f, g);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::DrawPrimitiveVB(D3DPRIMITIVETYPE a, LPDIRECT3DVERTEXBUFFER7 b, DWORD c, DWORD d, DWORD e)
{
	logf("IDirect3DDevice7::DrawPrimitiveVB(D3DPRIMITIVETYPE, LPDIRECT3DVERTEXBUFFER7 0x%x, DWORD %d, DWORD %d, DWORD %d);", b, c, d, e);
	HRESULT x = mOriginal->DrawPrimitiveVB(a, (b) ? ((myIDirect3DVertexBuffer7 *)b)->mOriginal : 0, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::DrawIndexedPrimitiveVB(D3DPRIMITIVETYPE a, LPDIRECT3DVERTEXBUFFER7 b, DWORD c, DWORD d, LPWORD e, DWORD f, DWORD g)
{
	logf("IDirect3DDevice7::DrawIndexedPrimitiveVB(D3DPRIMITIVETYPE, LPDIRECT3DVERTEXBUFFER7 0x%x, DWORD %d, DWORD %d, LPWORD 0x%x, DWORD %d, DWORD %d);", b, c, d, e, f, g);
	HRESULT x = mOriginal->DrawIndexedPrimitiveVB(a, (b) ? ((myIDirect3DVertexBuffer7 *)b)->mOriginal : 0, c, d, e, f, g);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::ComputeSphereVisibility(LPD3DVECTOR a, LPD3DVALUE b, DWORD c, DWORD d, LPDWORD e)
{
	logf("IDirect3DDevice7::ComputeSphereVisibility(LPD3DVECTOR 0x%x, LPD3DVALUE 0x%x, DWORD %d, DWORD %d, LPDWORD 0x%x);", a, b, c, d, e);
	HRESULT x = mOriginal->ComputeSphereVisibility(a, b, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetTexture(DWORD a, LPDIRECTDRAWSURFACE7 * b)
{
	logf("IDirect3DDevice7::GetTexture(DWORD %d, LPDIRECTDRAWSURFACE7 * 0x%x);", a, b);
	HRESULT x = mOriginal->GetTexture(a, b);
	logf(" -> return %d\n", x);
	LPDIRECTDRAWSURFACE7 n = (LPDIRECTDRAWSURFACE7)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (LPDIRECTDRAWSURFACE7)new myIDirectDrawSurface7(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetTexture(DWORD a, LPDIRECTDRAWSURFACE7 b)
{
	logf("IDirect3DDevice7::SetTexture(DWORD %d, LPDIRECTDRAWSURFACE7 0x%x);", a, b);
	HRESULT x = mOriginal->SetTexture(a, (b) ? ((myIDirectDrawSurface7 *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetTextureStageState(DWORD a, D3DTEXTURESTAGESTATETYPE b, LPDWORD c)
{
	logf("IDirect3DDevice7::GetTextureStageState(DWORD %d, D3DTEXTURESTAGESTATETYPE, LPDWORD 0x%x);", a, c);
	HRESULT x = mOriginal->GetTextureStageState(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetTextureStageState(DWORD a, D3DTEXTURESTAGESTATETYPE b, DWORD c)
{
	logf("IDirect3DDevice7::SetTextureStageState(DWORD %d, D3DTEXTURESTAGESTATETYPE, DWORD %d);", a, c);
	HRESULT x = mOriginal->SetTextureStageState(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::ValidateDevice(LPDWORD a)
{
	logf("IDirect3DDevice7::ValidateDevice(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->ValidateDevice(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::ApplyStateBlock(DWORD a)
{
	logf("IDirect3DDevice7::ApplyStateBlock(DWORD %d);", a);
	HRESULT x = mOriginal->ApplyStateBlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::CaptureStateBlock(DWORD a)
{
	logf("IDirect3DDevice7::CaptureStateBlock(DWORD %d);", a);
	HRESULT x = mOriginal->CaptureStateBlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::DeleteStateBlock(DWORD a)
{
	logf("IDirect3DDevice7::DeleteStateBlock(DWORD %d);", a);
	HRESULT x = mOriginal->DeleteStateBlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::CreateStateBlock(D3DSTATEBLOCKTYPE a, LPDWORD b)
{
	logf("IDirect3DDevice7::CreateStateBlock(D3DSTATEBLOCKTYPE, LPDWORD 0x%x);", b);
	HRESULT x = mOriginal->CreateStateBlock(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::Load(LPDIRECTDRAWSURFACE7 a, LPPOINT b, LPDIRECTDRAWSURFACE7 c, LPRECT d, DWORD e)
{
	logf("IDirect3DDevice7::Load(LPDIRECTDRAWSURFACE7 0x%x, LPPOINT 0x%x, LPDIRECTDRAWSURFACE7 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
	HRESULT x = mOriginal->Load((a) ? ((myIDirectDrawSurface7 *)a)->mOriginal : 0, b, (c) ? ((myIDirectDrawSurface7 *)c)->mOriginal : 0, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::LightEnable(DWORD a, BOOL b)
{
	logf("IDirect3DDevice7::LightEnable(DWORD %d, BOOL);", a);
	HRESULT x = mOriginal->LightEnable(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetLightEnable(DWORD a, BOOL * b)
{
	logf("IDirect3DDevice7::GetLightEnable(DWORD %d, BOOL *);", a);
	HRESULT x = mOriginal->GetLightEnable(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::SetClipPlane(DWORD a, D3DVALUE * b)
{
	logf("IDirect3DDevice7::SetClipPlane(DWORD %d, D3DVALUE *);", a);
	HRESULT x = mOriginal->SetClipPlane(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetClipPlane(DWORD a, D3DVALUE * b)
{
	logf("IDirect3DDevice7::GetClipPlane(DWORD %d, D3DVALUE *);", a);
	HRESULT x = mOriginal->GetClipPlane(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DDevice7::GetInfo(DWORD a, LPVOID b, DWORD c)
{
	logf("IDirect3DDevice7::GetInfo(DWORD %d, LPVOID 0x%x, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->GetInfo(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}
