#pragma once

class m_IDirect3DVertexBuffer7 : public IDirect3DVertexBuffer7
{
public:
	m_IDirect3DVertexBuffer7(IDirect3DVertexBuffer7 * aOriginal);
	~m_IDirect3DVertexBuffer7();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Lock(DWORD a, LPVOID * b, LPDWORD c);
	HRESULT __stdcall Unlock();
	HRESULT __stdcall ProcessVertices(DWORD a, DWORD b, DWORD c, LPDIRECT3DVERTEXBUFFER7 d, DWORD e, LPDIRECT3DDEVICE7 f, DWORD g);
	HRESULT __stdcall GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC a);
	HRESULT __stdcall Optimize(LPDIRECT3DDEVICE7 a, DWORD b);
	HRESULT __stdcall ProcessVerticesStrided(DWORD a, DWORD b, DWORD c, LPD3DDRAWPRIMITIVESTRIDEDDATA d, DWORD e, LPDIRECT3DDEVICE7 f, DWORD g);
	IDirect3DVertexBuffer7 * mOriginal;
};

