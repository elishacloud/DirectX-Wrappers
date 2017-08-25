#pragma once

class m_IDirect3D7 : public IDirect3D7
{
public:
	m_IDirect3D7(IDirect3D7 * aOriginal);
	~m_IDirect3D7();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall EnumDevices(LPD3DENUMDEVICESCALLBACK7 a, LPVOID b);
	HRESULT __stdcall CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE7 b, LPDIRECT3DDEVICE7 * c);
	HRESULT __stdcall CreateVertexBuffer(LPD3DVERTEXBUFFERDESC a, LPDIRECT3DVERTEXBUFFER7 * b, DWORD c);
	HRESULT __stdcall EnumZBufferFormats(REFCLSID a, LPD3DENUMPIXELFORMATSCALLBACK b, LPVOID c);
	HRESULT __stdcall EvictManagedTextures();
	IDirect3D7 * mOriginal;
};

