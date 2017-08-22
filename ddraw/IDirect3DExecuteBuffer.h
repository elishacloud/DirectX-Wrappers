#pragma once

class myIDirect3DExecuteBuffer : public IDirect3DExecuteBuffer
{
public:
	myIDirect3DExecuteBuffer(IDirect3DExecuteBuffer * aOriginal);
	~myIDirect3DExecuteBuffer();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Initialize(LPDIRECT3DDEVICE a, LPD3DEXECUTEBUFFERDESC b);
	HRESULT __stdcall Lock(LPD3DEXECUTEBUFFERDESC a);
	HRESULT __stdcall Unlock();
	HRESULT __stdcall SetExecuteData(LPD3DEXECUTEDATA a);
	HRESULT __stdcall GetExecuteData(LPD3DEXECUTEDATA a);
	HRESULT __stdcall Validate(LPDWORD a, LPD3DVALIDATECALLBACK b, LPVOID c, DWORD d);
	HRESULT __stdcall Optimize(DWORD a);
	IDirect3DExecuteBuffer * mOriginal;
};

