#pragma once

class myIDirect3DDevice : public IDirect3DDevice
{
public:
	myIDirect3DDevice(IDirect3DDevice * aOriginal);
	~myIDirect3DDevice();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Initialize(LPDIRECT3D a, LPGUID b, LPD3DDEVICEDESC c);
	HRESULT __stdcall GetCaps(LPD3DDEVICEDESC a, LPD3DDEVICEDESC b);
	HRESULT __stdcall SwapTextureHandles(LPDIRECT3DTEXTURE a, LPDIRECT3DTEXTURE b);
	HRESULT __stdcall CreateExecuteBuffer(LPD3DEXECUTEBUFFERDESC a, LPDIRECT3DEXECUTEBUFFER * b, IUnknown * c);
	HRESULT __stdcall GetStats(LPD3DSTATS a);
	HRESULT __stdcall Execute(LPDIRECT3DEXECUTEBUFFER a, LPDIRECT3DVIEWPORT b, DWORD c);
	HRESULT __stdcall AddViewport(LPDIRECT3DVIEWPORT a);
	HRESULT __stdcall DeleteViewport(LPDIRECT3DVIEWPORT a);
	HRESULT __stdcall NextViewport(LPDIRECT3DVIEWPORT a, LPDIRECT3DVIEWPORT * b, DWORD c);
	HRESULT __stdcall Pick(LPDIRECT3DEXECUTEBUFFER a, LPDIRECT3DVIEWPORT b, DWORD c, LPD3DRECT d);
	HRESULT __stdcall GetPickRecords(LPDWORD a, LPD3DPICKRECORD b);
	HRESULT __stdcall EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK a, LPVOID b);
	HRESULT __stdcall CreateMatrix(LPD3DMATRIXHANDLE a);
	HRESULT __stdcall SetMatrix(D3DMATRIXHANDLE a, const LPD3DMATRIX b);
	HRESULT __stdcall GetMatrix(D3DMATRIXHANDLE a, LPD3DMATRIX b);
	HRESULT __stdcall DeleteMatrix(D3DMATRIXHANDLE a);
	HRESULT __stdcall BeginScene();
	HRESULT __stdcall EndScene();
	HRESULT __stdcall GetDirect3D(LPDIRECT3D * a);
	IDirect3DDevice * mOriginal;
};

