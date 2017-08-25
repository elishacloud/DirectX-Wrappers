#pragma once

class m_IDirect3DMaterial2 : public IDirect3DMaterial2
{
public:
	m_IDirect3DMaterial2(IDirect3DMaterial2 * aOriginal);
	~m_IDirect3DMaterial2();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall SetMaterial(LPD3DMATERIAL a);
	HRESULT __stdcall GetMaterial(LPD3DMATERIAL a);
	HRESULT __stdcall GetHandle(LPDIRECT3DDEVICE2 a, LPD3DMATERIALHANDLE b);
	IDirect3DMaterial2 * mOriginal;
};

