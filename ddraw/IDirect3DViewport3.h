#pragma once

class m_IDirect3DViewport3 : public IDirect3DViewport3
{
public:
	m_IDirect3DViewport3(IDirect3DViewport3 * aOriginal);
	~m_IDirect3DViewport3();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Initialize(LPDIRECT3D a);
	HRESULT __stdcall GetViewport(LPD3DVIEWPORT a);
	HRESULT __stdcall SetViewport(LPD3DVIEWPORT a);
	HRESULT __stdcall TransformVertices(DWORD a, LPD3DTRANSFORMDATA b, DWORD c, LPDWORD d);
	HRESULT __stdcall LightElements(DWORD a, LPD3DLIGHTDATA b);
	HRESULT __stdcall SetBackground(D3DMATERIALHANDLE a);
	HRESULT __stdcall GetBackground(LPD3DMATERIALHANDLE a, LPBOOL b);
	HRESULT __stdcall SetBackgroundDepth(LPDIRECTDRAWSURFACE a);
	HRESULT __stdcall GetBackgroundDepth(LPDIRECTDRAWSURFACE * a, LPBOOL b);
	HRESULT __stdcall Clear(DWORD a, LPD3DRECT b, DWORD c);
	HRESULT __stdcall AddLight(LPDIRECT3DLIGHT a);
	HRESULT __stdcall DeleteLight(LPDIRECT3DLIGHT a);
	HRESULT __stdcall NextLight(LPDIRECT3DLIGHT a, LPDIRECT3DLIGHT * b, DWORD c);
	HRESULT __stdcall GetViewport2(LPD3DVIEWPORT2 a);
	HRESULT __stdcall SetViewport2(LPD3DVIEWPORT2 a);
	HRESULT __stdcall SetBackgroundDepth2(LPDIRECTDRAWSURFACE4 a);
	HRESULT __stdcall GetBackgroundDepth2(LPDIRECTDRAWSURFACE4 * a, LPBOOL b);
	HRESULT __stdcall Clear2(DWORD a, LPD3DRECT b, DWORD c, D3DCOLOR d, D3DVALUE e, DWORD f);
	IDirect3DViewport3 * mOriginal;
};

