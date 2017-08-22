#pragma once

class myIDirect3DTexture : public IDirect3DTexture
{
public:
	myIDirect3DTexture(IDirect3DTexture * aOriginal);
	~myIDirect3DTexture();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Initialize(LPDIRECT3DDEVICE a, LPDIRECTDRAWSURFACE b);
	HRESULT __stdcall GetHandle(LPDIRECT3DDEVICE a, LPD3DTEXTUREHANDLE b);
	HRESULT __stdcall PaletteChanged(DWORD a, DWORD b);
	HRESULT __stdcall Load(LPDIRECT3DTEXTURE a);
	HRESULT __stdcall Unload();
	IDirect3DTexture * mOriginal;
};

