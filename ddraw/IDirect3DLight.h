#pragma once

class myIDirect3DLight : public IDirect3DLight
{
public:
	myIDirect3DLight(IDirect3DLight * aOriginal);
	~myIDirect3DLight();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Initialize(LPDIRECT3D a);
	HRESULT __stdcall SetLight(LPD3DLIGHT a);
	HRESULT __stdcall GetLight(LPD3DLIGHT a);
	IDirect3DLight * mOriginal;
};

