#pragma once

class m_IDirect3DDevice7 : public IDirect3DDevice7
{
public:
	m_IDirect3DDevice7(IDirect3DDevice7 * aOriginal);
	~m_IDirect3DDevice7();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetCaps(LPD3DDEVICEDESC7 a);
	HRESULT __stdcall EnumTextureFormats(LPD3DENUMPIXELFORMATSCALLBACK a, LPVOID b);
	HRESULT __stdcall BeginScene();
	HRESULT __stdcall EndScene();
	HRESULT __stdcall GetDirect3D(LPDIRECT3D7 * a);
	HRESULT __stdcall SetRenderTarget(LPDIRECTDRAWSURFACE7 a, DWORD b);
	HRESULT __stdcall GetRenderTarget(LPDIRECTDRAWSURFACE7 * a);
	HRESULT __stdcall Clear(DWORD a, LPD3DRECT b, DWORD c, D3DCOLOR d, D3DVALUE e, DWORD f);
	HRESULT __stdcall SetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b);
	HRESULT __stdcall GetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b);
	HRESULT __stdcall SetViewport(LPD3DVIEWPORT7 a);
	HRESULT __stdcall MultiplyTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b);
	HRESULT __stdcall GetViewport(LPD3DVIEWPORT7 a);
	HRESULT __stdcall SetMaterial(LPD3DMATERIAL7 a);
	HRESULT __stdcall GetMaterial(LPD3DMATERIAL7 a);
	HRESULT __stdcall SetLight(DWORD a, LPD3DLIGHT7 b);
	HRESULT __stdcall GetLight(DWORD a, LPD3DLIGHT7 b);
	HRESULT __stdcall SetRenderState(D3DRENDERSTATETYPE a, DWORD b);
	HRESULT __stdcall GetRenderState(D3DRENDERSTATETYPE a, LPDWORD b);
	HRESULT __stdcall BeginStateBlock();
	HRESULT __stdcall EndStateBlock(LPDWORD a);
	HRESULT __stdcall PreLoad(LPDIRECTDRAWSURFACE7 a);
	HRESULT __stdcall DrawPrimitive(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, DWORD e);
	HRESULT __stdcall DrawIndexedPrimitive(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, LPWORD e, DWORD f, DWORD g);
	HRESULT __stdcall SetClipStatus(LPD3DCLIPSTATUS a);
	HRESULT __stdcall GetClipStatus(LPD3DCLIPSTATUS a);
	HRESULT __stdcall DrawPrimitiveStrided(D3DPRIMITIVETYPE a, DWORD b, LPD3DDRAWPRIMITIVESTRIDEDDATA c, DWORD d, DWORD e);
	HRESULT __stdcall DrawIndexedPrimitiveStrided(D3DPRIMITIVETYPE a, DWORD b, LPD3DDRAWPRIMITIVESTRIDEDDATA c, DWORD d, LPWORD e, DWORD f, DWORD g);
	HRESULT __stdcall DrawPrimitiveVB(D3DPRIMITIVETYPE a, LPDIRECT3DVERTEXBUFFER7 b, DWORD c, DWORD d, DWORD e);
	HRESULT __stdcall DrawIndexedPrimitiveVB(D3DPRIMITIVETYPE a, LPDIRECT3DVERTEXBUFFER7 b, DWORD c, DWORD d, LPWORD e, DWORD f, DWORD g);
	HRESULT __stdcall ComputeSphereVisibility(LPD3DVECTOR a, LPD3DVALUE b, DWORD c, DWORD d, LPDWORD e);
	HRESULT __stdcall GetTexture(DWORD a, LPDIRECTDRAWSURFACE7 * b);
	HRESULT __stdcall SetTexture(DWORD a, LPDIRECTDRAWSURFACE7 b);
	HRESULT __stdcall GetTextureStageState(DWORD a, D3DTEXTURESTAGESTATETYPE b, LPDWORD c);
	HRESULT __stdcall SetTextureStageState(DWORD a, D3DTEXTURESTAGESTATETYPE b, DWORD c);
	HRESULT __stdcall ValidateDevice(LPDWORD a);
	HRESULT __stdcall ApplyStateBlock(DWORD a);
	HRESULT __stdcall CaptureStateBlock(DWORD a);
	HRESULT __stdcall DeleteStateBlock(DWORD a);
	HRESULT __stdcall CreateStateBlock(D3DSTATEBLOCKTYPE a, LPDWORD b);
	HRESULT __stdcall Load(LPDIRECTDRAWSURFACE7 a, LPPOINT b, LPDIRECTDRAWSURFACE7 c, LPRECT d, DWORD e);
	HRESULT __stdcall LightEnable(DWORD a, BOOL b);
	HRESULT __stdcall GetLightEnable(DWORD a, BOOL * b);
	HRESULT __stdcall SetClipPlane(DWORD a, D3DVALUE * b);
	HRESULT __stdcall GetClipPlane(DWORD a, D3DVALUE * b);
	HRESULT __stdcall GetInfo(DWORD a, LPVOID b, DWORD c);
	IDirect3DDevice7 * mOriginal;
};

