#pragma once

class myIDirect3D3 : public IDirect3D3
{
public:
	myIDirect3D3(IDirect3D3 * aOriginal);
	~myIDirect3D3();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b);
	HRESULT __stdcall CreateLight(LPDIRECT3DLIGHT * a, LPUNKNOWN b);
	HRESULT __stdcall CreateMaterial(LPDIRECT3DMATERIAL3 * a, LPUNKNOWN b);
	HRESULT __stdcall CreateViewport(LPDIRECT3DVIEWPORT3 * a, LPUNKNOWN b);
	HRESULT __stdcall FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b);
	HRESULT __stdcall CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE4 b, LPDIRECT3DDEVICE3 * c, LPUNKNOWN d);
	HRESULT __stdcall CreateVertexBuffer(LPD3DVERTEXBUFFERDESC a, LPDIRECT3DVERTEXBUFFER * b, DWORD c, LPUNKNOWN d);
	HRESULT __stdcall EnumZBufferFormats(REFCLSID a, LPD3DENUMPIXELFORMATSCALLBACK b, LPVOID c);
	HRESULT __stdcall EvictManagedTextures();
	IDirect3D3 * mOriginal;
};

