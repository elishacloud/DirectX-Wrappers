#pragma once

class m_IDirect3DMaterial : public IDirect3DMaterial
{
public:
	m_IDirect3DMaterial(IDirect3DMaterial * aOriginal);
	~m_IDirect3DMaterial();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Initialize(LPDIRECT3D a);
	HRESULT __stdcall SetMaterial(LPD3DMATERIAL a);
	HRESULT __stdcall GetMaterial(LPD3DMATERIAL a);
	HRESULT __stdcall GetHandle(LPDIRECT3DDEVICE a, LPD3DMATERIALHANDLE b);
	HRESULT __stdcall Reserve();
	HRESULT __stdcall Unreserve();
	IDirect3DMaterial * mOriginal;
};

