#pragma once

class myIDirect3D2 : public IDirect3D2
{
public:
	myIDirect3D2(IDirect3D2 * aOriginal);
	~myIDirect3D2();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b);
	HRESULT __stdcall CreateLight(LPDIRECT3DLIGHT * a, IUnknown * b);
	HRESULT __stdcall CreateMaterial(LPDIRECT3DMATERIAL2 * a, IUnknown * b);
	HRESULT __stdcall CreateViewport(LPDIRECT3DVIEWPORT2 * a, IUnknown * b);
	HRESULT __stdcall FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b);
	HRESULT __stdcall CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE b, LPDIRECT3DDEVICE2 * c);
	IDirect3D2 * mOriginal;
};
