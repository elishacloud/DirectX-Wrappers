#pragma once

class myIDirect3D : public IDirect3D
{
public:
	myIDirect3D(IDirect3D * aOriginal);
	~myIDirect3D();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Initialize(REFCLSID a);
	HRESULT __stdcall EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b);
	HRESULT __stdcall CreateLight(LPDIRECT3DLIGHT * a, IUnknown * b);
	HRESULT __stdcall CreateMaterial(LPDIRECT3DMATERIAL * a, IUnknown * b);
	HRESULT __stdcall CreateViewport(LPDIRECT3DVIEWPORT * a, IUnknown * b);
	HRESULT __stdcall FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b);
	IDirect3D * mOriginal;
};
