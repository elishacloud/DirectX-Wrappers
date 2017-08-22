#pragma once

class myIDirect3DDevice2 : public IDirect3DDevice2
{
public:
	myIDirect3DDevice2(IDirect3DDevice2 * aOriginal);
	~myIDirect3DDevice2();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetCaps(LPD3DDEVICEDESC a, LPD3DDEVICEDESC b);
	HRESULT __stdcall SwapTextureHandles(LPDIRECT3DTEXTURE2 a, LPDIRECT3DTEXTURE2 b);
	HRESULT __stdcall GetStats(LPD3DSTATS a);
	HRESULT __stdcall AddViewport(LPDIRECT3DVIEWPORT2 a);
	HRESULT __stdcall DeleteViewport(LPDIRECT3DVIEWPORT2 a);
	HRESULT __stdcall NextViewport(LPDIRECT3DVIEWPORT2 a, LPDIRECT3DVIEWPORT2 * b, DWORD c);
	HRESULT __stdcall EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK a, LPVOID b);
	HRESULT __stdcall BeginScene();
	HRESULT __stdcall EndScene();
	HRESULT __stdcall GetDirect3D(LPDIRECT3D2 * a);
	HRESULT __stdcall SetCurrentViewport(LPDIRECT3DVIEWPORT2 a);
	HRESULT __stdcall GetCurrentViewport(LPDIRECT3DVIEWPORT2 * a);
	HRESULT __stdcall SetRenderTarget(LPDIRECTDRAWSURFACE a, DWORD b);
	HRESULT __stdcall GetRenderTarget(LPDIRECTDRAWSURFACE * a);
	HRESULT __stdcall Begin(D3DPRIMITIVETYPE a, D3DVERTEXTYPE b, DWORD c);
	HRESULT __stdcall BeginIndexed(D3DPRIMITIVETYPE a, D3DVERTEXTYPE b, LPVOID c, DWORD d, DWORD e);
	HRESULT __stdcall Vertex(LPVOID a);
	HRESULT __stdcall Index(WORD a);
	HRESULT __stdcall End(DWORD a);
	HRESULT __stdcall GetRenderState(D3DRENDERSTATETYPE a, LPDWORD b);
	HRESULT __stdcall SetRenderState(D3DRENDERSTATETYPE a, DWORD b);
	HRESULT __stdcall GetLightState(D3DLIGHTSTATETYPE a, LPDWORD b);
	HRESULT __stdcall SetLightState(D3DLIGHTSTATETYPE a, DWORD b);
	HRESULT __stdcall SetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b);
	HRESULT __stdcall GetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b);
	HRESULT __stdcall MultiplyTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b);
	HRESULT __stdcall DrawPrimitive(D3DPRIMITIVETYPE a, D3DVERTEXTYPE b, LPVOID c, DWORD d, DWORD e);
	HRESULT __stdcall DrawIndexedPrimitive(D3DPRIMITIVETYPE a, D3DVERTEXTYPE b, LPVOID c, DWORD d, LPWORD e, DWORD f, DWORD g);
	HRESULT __stdcall SetClipStatus(LPD3DCLIPSTATUS a);
	HRESULT __stdcall GetClipStatus(LPD3DCLIPSTATUS a);
	IDirect3DDevice2 * mOriginal;
};

