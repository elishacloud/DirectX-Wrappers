#pragma once

class m_IDirect3DSwapChain8 : public IDirect3DSwapChain8
{
private:
	LPDIRECT3DSWAPCHAIN8 m_pD3DSwapChain8;

public:
	m_IDirect3DSwapChain8(LPDIRECT3DSWAPCHAIN8 pSwapChain8) { m_pD3DSwapChain8 = pSwapChain8; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirect3DSwapChain8 methods ***/
	STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);
	STDMETHOD(GetBackBuffer)(THIS_ UINT BackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface8** ppBackBuffer);
};
