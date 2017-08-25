#pragma once

class m_IDirect3DMaterial3 : public IDirect3DMaterial3
{
public:
	m_IDirect3DMaterial3(IDirect3DMaterial3 * aOriginal);
	~m_IDirect3DMaterial3();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall SetMaterial(LPD3DMATERIAL a);
	HRESULT __stdcall GetMaterial(LPD3DMATERIAL a);
	HRESULT __stdcall GetHandle(LPDIRECT3DDEVICE3 a, LPD3DMATERIALHANDLE b);
	IDirect3DMaterial3 * mOriginal;
};

