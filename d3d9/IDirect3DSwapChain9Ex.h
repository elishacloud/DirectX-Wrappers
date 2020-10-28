#pragma once

class m_IDirect3DSwapChain9Ex : public IDirect3DSwapChain9Ex, public AddressLookupTableObject
{
private:
	LPDIRECT3DSWAPCHAIN9EX ProxyInterface;
	m_IDirect3DDevice9Ex* m_pDeviceEx = nullptr;
	REFIID WrapperID;

public:
	m_IDirect3DSwapChain9Ex(LPDIRECT3DSWAPCHAIN9EX pSwapChain9, m_IDirect3DDevice9Ex* pDevice, REFIID DeviceID = IID_IDirect3DSwapChain9) : ProxyInterface(pSwapChain9), m_pDeviceEx(pDevice), WrapperID(DeviceID)
	{
		pDevice->ProxyAddressLookupTable->SaveAddress(this, ProxyInterface);
	}
	~m_IDirect3DSwapChain9Ex() {}

	LPDIRECT3DSWAPCHAIN9EX GetProxyInterface() { return ProxyInterface; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirect3DSwapChain9 methods ***/
	STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion, DWORD dwFlags);
	STDMETHOD(GetFrontBufferData)(THIS_ IDirect3DSurface9* pDestSurface);
	STDMETHOD(GetBackBuffer)(THIS_ UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer);
	STDMETHOD(GetRasterStatus)(THIS_ D3DRASTER_STATUS* pRasterStatus);
	STDMETHOD(GetDisplayMode)(THIS_ D3DDISPLAYMODE* pMode);
	STDMETHOD(GetDevice)(THIS_ IDirect3DDevice9** ppDevice);
	STDMETHOD(GetPresentParameters)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters);
	STDMETHOD(GetLastPresentCount)(THIS_ UINT* pLastPresentCount);
	STDMETHOD(GetPresentStats)(THIS_ D3DPRESENTSTATS* pPresentationStatistics);
	STDMETHOD(GetDisplayModeEx)(THIS_ D3DDISPLAYMODEEX* pMode, D3DDISPLAYROTATION* pRotation);
};
