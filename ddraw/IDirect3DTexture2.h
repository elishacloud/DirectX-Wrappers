#pragma once

class myIDirect3DTexture2 : public IDirect3DTexture2
{
public:
	myIDirect3DTexture2(IDirect3DTexture2 * aOriginal);
	~myIDirect3DTexture2();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetHandle(LPDIRECT3DDEVICE2 a, LPD3DTEXTUREHANDLE b);
	HRESULT __stdcall PaletteChanged(DWORD a, DWORD b);
	HRESULT __stdcall Load(LPDIRECT3DTEXTURE2 a);
	IDirect3DTexture2 * mOriginal;
};

