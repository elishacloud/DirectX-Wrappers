#pragma once

class m_IDirect3DVertexBuffer : public IDirect3DVertexBuffer
{
public:
	m_IDirect3DVertexBuffer(IDirect3DVertexBuffer * aOriginal);
	~m_IDirect3DVertexBuffer();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Lock(DWORD a, LPVOID * b, LPDWORD c);
	HRESULT __stdcall Unlock();
	HRESULT __stdcall ProcessVertices(DWORD a, DWORD b, DWORD c, LPDIRECT3DVERTEXBUFFER d, DWORD e, LPDIRECT3DDEVICE3 f, DWORD g);
	HRESULT __stdcall GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC a);
	HRESULT __stdcall Optimize(LPDIRECT3DDEVICE3 a, DWORD b);
	IDirect3DVertexBuffer * mOriginal;
};

