/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*
* Code taken from code found here: https://gist.github.com/shaunlebron/3854bf4eec5bec297907
*/

#include "d3d9.h"
#include "d3dx9.h"

m_IDirect3DDevice9::m_IDirect3DDevice9(LPDIRECT3DDEVICE9 pDevice, LPDIRECT3DDEVICE9 **ppDevice)
{
	m_pD3DDevice = pDevice;
	*ppDevice = &m_pD3DDevice;
}

ULONG m_IDirect3DDevice9::AddRef()
{
	return m_pD3DDevice->AddRef();
}

HRESULT m_IDirect3DDevice9::QueryInterface(REFIID riid, LPVOID *ppvObj)
{
	return m_pD3DDevice->QueryInterface(riid, ppvObj);
}

ULONG m_IDirect3DDevice9::Release()
{
	return m_pD3DDevice->Release();
}

HRESULT m_IDirect3DDevice9::Reset(D3DPRESENT_PARAMETERS *pPresentationParameters)
{
	HRESULT hr = m_pD3DDevice->Reset(pPresentationParameters);
	return hr;
}

HRESULT m_IDirect3DDevice9::EndScene()
{
	return m_pD3DDevice->EndScene();
}

void m_IDirect3DDevice9::SetCursorPosition(int X, int Y, DWORD Flags)
{
	m_pD3DDevice->SetCursorPosition(X, Y, Flags);
}

HRESULT m_IDirect3DDevice9::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9 *pCursorBitmap)
{
	return m_pD3DDevice->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

BOOL m_IDirect3DDevice9::ShowCursor(BOOL bShow)
{
	return m_pD3DDevice->ShowCursor(bShow);
}

HRESULT m_IDirect3DDevice9::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain9 **ppSwapChain)
{
	return m_pD3DDevice->CreateAdditionalSwapChain(pPresentationParameters, ppSwapChain);
}

HRESULT m_IDirect3DDevice9::CreateCubeTexture(THIS_ UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
	return m_pD3DDevice->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

HRESULT m_IDirect3DDevice9::CreateDepthStencilSurface(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return m_pD3DDevice->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT m_IDirect3DDevice9::CreateIndexBuffer(THIS_ UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
	return m_pD3DDevice->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

HRESULT m_IDirect3DDevice9::CreateRenderTarget(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return m_pD3DDevice->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT m_IDirect3DDevice9::CreateTexture(THIS_ UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
	return m_pD3DDevice->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

HRESULT m_IDirect3DDevice9::CreateVertexBuffer(THIS_ UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
	return m_pD3DDevice->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

HRESULT m_IDirect3DDevice9::CreateVolumeTexture(THIS_ UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
	return m_pD3DDevice->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

HRESULT m_IDirect3DDevice9::BeginStateBlock()
{
	return m_pD3DDevice->BeginStateBlock();
}

HRESULT m_IDirect3DDevice9::CreateStateBlock(THIS_ D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
	return m_pD3DDevice->CreateStateBlock(Type, ppSB);
}

HRESULT m_IDirect3DDevice9::EndStateBlock(THIS_ IDirect3DStateBlock9** ppSB)
{
	return m_pD3DDevice->EndStateBlock(ppSB);
}

HRESULT m_IDirect3DDevice9::GetClipStatus(D3DCLIPSTATUS9 *pClipStatus)
{
	return m_pD3DDevice->GetClipStatus(pClipStatus);
}

HRESULT m_IDirect3DDevice9::GetDisplayMode(THIS_ UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
	return m_pD3DDevice->GetDisplayMode(iSwapChain, pMode);
}

HRESULT m_IDirect3DDevice9::GetRenderState(D3DRENDERSTATETYPE State, DWORD *pValue)
{
	return m_pD3DDevice->GetRenderState(State, pValue);
}

HRESULT m_IDirect3DDevice9::GetRenderTarget(THIS_ DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
	return m_pD3DDevice->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

HRESULT m_IDirect3DDevice9::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix)
{
	return m_pD3DDevice->GetTransform(State, pMatrix);
}

HRESULT m_IDirect3DDevice9::SetClipStatus(CONST D3DCLIPSTATUS9 *pClipStatus)
{
	return m_pD3DDevice->SetClipStatus(pClipStatus);
}

HRESULT m_IDirect3DDevice9::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
	Log() << "SetRenderState " << State << " " << Value;
	return m_pD3DDevice->SetRenderState(State, Value);
}

HRESULT m_IDirect3DDevice9::SetRenderTarget(THIS_ DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
	return m_pD3DDevice->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

HRESULT m_IDirect3DDevice9::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX *pMatrix)
{
	return m_pD3DDevice->SetTransform(State, pMatrix);
}

void m_IDirect3DDevice9::GetGammaRamp(THIS_ UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
	m_pD3DDevice->GetGammaRamp(iSwapChain, pRamp);
}

void m_IDirect3DDevice9::SetGammaRamp(THIS_ UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp)
{
	m_pD3DDevice->SetGammaRamp(iSwapChain, Flags, pRamp);
}

HRESULT m_IDirect3DDevice9::DeletePatch(UINT Handle)
{
	return m_pD3DDevice->DeletePatch(Handle);
}

HRESULT m_IDirect3DDevice9::DrawRectPatch(UINT Handle, CONST float *pNumSegs, CONST D3DRECTPATCH_INFO *pRectPatchInfo)
{
	return m_pD3DDevice->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT m_IDirect3DDevice9::DrawTriPatch(UINT Handle, CONST float *pNumSegs, CONST D3DTRIPATCH_INFO *pTriPatchInfo)
{
	return m_pD3DDevice->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT m_IDirect3DDevice9::GetIndices(THIS_ IDirect3DIndexBuffer9** ppIndexData)
{
	return m_pD3DDevice->GetIndices(ppIndexData);
}

HRESULT m_IDirect3DDevice9::SetIndices(THIS_ IDirect3DIndexBuffer9* pIndexData)
{
	return m_pD3DDevice->SetIndices(pIndexData);
}

UINT m_IDirect3DDevice9::GetAvailableTextureMem()
{
	return m_pD3DDevice->GetAvailableTextureMem();
}

HRESULT m_IDirect3DDevice9::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
	return m_pD3DDevice->GetCreationParameters(pParameters);
}

HRESULT m_IDirect3DDevice9::GetDeviceCaps(D3DCAPS9 *pCaps)
{
	return m_pD3DDevice->GetDeviceCaps(pCaps);
}

HRESULT m_IDirect3DDevice9::GetDirect3D(IDirect3D9 **ppD3D9)
{
	return m_pD3DDevice->GetDirect3D(ppD3D9);
}

HRESULT m_IDirect3DDevice9::GetRasterStatus(THIS_ UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
	return m_pD3DDevice->GetRasterStatus(iSwapChain, pRasterStatus);
}

HRESULT m_IDirect3DDevice9::GetLight(DWORD Index, D3DLIGHT9 *pLight)
{
	return m_pD3DDevice->GetLight(Index, pLight);
}

HRESULT m_IDirect3DDevice9::GetLightEnable(DWORD Index, BOOL *pEnable)
{
	return m_pD3DDevice->GetLightEnable(Index, pEnable);
}

HRESULT m_IDirect3DDevice9::GetMaterial(D3DMATERIAL9 *pMaterial)
{
	return m_pD3DDevice->GetMaterial(pMaterial);
}

HRESULT m_IDirect3DDevice9::LightEnable(DWORD LightIndex, BOOL bEnable)
{
	return m_pD3DDevice->LightEnable(LightIndex, bEnable);
}

HRESULT m_IDirect3DDevice9::SetLight(DWORD Index, CONST D3DLIGHT9 *pLight)
{

	return m_pD3DDevice->SetLight(Index, pLight);
}

HRESULT m_IDirect3DDevice9::SetMaterial(CONST D3DMATERIAL9 *pMaterial)
{
	return m_pD3DDevice->SetMaterial(pMaterial);
}

HRESULT m_IDirect3DDevice9::MultiplyTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX *pMatrix)
{
	return m_pD3DDevice->MultiplyTransform(State, pMatrix);
}

HRESULT m_IDirect3DDevice9::ProcessVertices(THIS_ UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
	return m_pD3DDevice->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

HRESULT m_IDirect3DDevice9::TestCooperativeLevel()
{
	return m_pD3DDevice->TestCooperativeLevel();
}

HRESULT m_IDirect3DDevice9::GetCurrentTexturePalette(UINT *pPaletteNumber)
{
	return m_pD3DDevice->GetCurrentTexturePalette(pPaletteNumber);
}

HRESULT m_IDirect3DDevice9::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY *pEntries)
{
	return m_pD3DDevice->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT m_IDirect3DDevice9::SetCurrentTexturePalette(UINT PaletteNumber)
{
	return m_pD3DDevice->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT m_IDirect3DDevice9::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY *pEntries)
{
	return m_pD3DDevice->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT m_IDirect3DDevice9::CreatePixelShader(THIS_ CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
	if (pFunction != nullptr)
	{
		Log() << "<CreatePixelShader> Disassembling shader and translating assembly to Direct3D 9 compatible code ...";

		/*if (*pFunction < D3DVS_VERSION(1, 0) || *pFunction > D3DVS_VERSION(1, 1))
		{
		Log() << "> Failed because of version mismatch ('" << std::showbase << std::hex << *pFunction << std::dec << std::noshowbase << "')! Only 'vs_1_x' shaders are supported.";

		return D3DERR_INVALIDCALL;
		}*/

		ID3DXBuffer *Disassembly = nullptr, *Assembly = nullptr, *ErrorBuffer = nullptr;

		HRESULT hr = D3DXDisassembleShader(pFunction, FALSE, nullptr, &Disassembly);

		if (FAILED(hr))
		{
			Log() << "> Failed to disassemble shader with error code " << std::hex << hr << std::dec << "!";

			return hr;
		}

		std::string SourceCode(static_cast<const char *>(Disassembly->GetBufferPointer()), Disassembly->GetBufferSize() - 1);
		const char *cstr = SourceCode.c_str();

		Log() << "> Dumping translated shader assembly:" << cstr;
	}

	return m_pD3DDevice->CreatePixelShader(pFunction, ppShader);
}

HRESULT m_IDirect3DDevice9::GetPixelShader(THIS_ IDirect3DPixelShader9** ppShader)
{
	return m_pD3DDevice->GetPixelShader(ppShader);
}

HRESULT m_IDirect3DDevice9::SetPixelShader(THIS_ IDirect3DPixelShader9* pShader)
{
	return m_pD3DDevice->SetPixelShader(pShader);
}

HRESULT m_IDirect3DDevice9::Present(CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion)
{
	return m_pD3DDevice->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT m_IDirect3DDevice9::DrawIndexedPrimitive(THIS_ D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	return m_pD3DDevice->DrawIndexedPrimitive(Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT m_IDirect3DDevice9::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinIndex, UINT NumVertices, UINT PrimitiveCount, CONST void *pIndexData, D3DFORMAT IndexDataFormat, CONST void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return m_pD3DDevice->DrawIndexedPrimitiveUP(PrimitiveType, MinIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT m_IDirect3DDevice9::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	return m_pD3DDevice->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT m_IDirect3DDevice9::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return m_pD3DDevice->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT m_IDirect3DDevice9::BeginScene()
{
	return m_pD3DDevice->BeginScene();
}

HRESULT m_IDirect3DDevice9::GetStreamSource(THIS_ UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* OffsetInBytes, UINT* pStride)
{
	return m_pD3DDevice->GetStreamSource(StreamNumber, ppStreamData, OffsetInBytes, pStride);
}

HRESULT m_IDirect3DDevice9::SetStreamSource(THIS_ UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
	return m_pD3DDevice->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT m_IDirect3DDevice9::GetBackBuffer(THIS_ UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
	return m_pD3DDevice->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
}

HRESULT m_IDirect3DDevice9::GetDepthStencilSurface(IDirect3DSurface9 **ppZStencilSurface)
{
	return m_pD3DDevice->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT m_IDirect3DDevice9::GetTexture(DWORD Stage, IDirect3DBaseTexture9 **ppTexture)
{
	return m_pD3DDevice->GetTexture(Stage, ppTexture);
}

HRESULT m_IDirect3DDevice9::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue)
{
	return m_pD3DDevice->GetTextureStageState(Stage, Type, pValue);
}

HRESULT m_IDirect3DDevice9::SetTexture(DWORD Stage, IDirect3DBaseTexture9 *pTexture)
{
	return m_pD3DDevice->SetTexture(Stage, pTexture);
}

HRESULT m_IDirect3DDevice9::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
	Log() << "SetTextureStageState " << Stage << " " << Type << " " << Value;
	return m_pD3DDevice->SetTextureStageState(Stage, Type, Value);
}

HRESULT m_IDirect3DDevice9::UpdateTexture(IDirect3DBaseTexture9 *pSourceTexture, IDirect3DBaseTexture9 *pDestinationTexture)
{
	return m_pD3DDevice->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT m_IDirect3DDevice9::ValidateDevice(DWORD *pNumPasses)
{
	HRESULT rt = m_pD3DDevice->ValidateDevice(pNumPasses);
	Log() << "ValidateDevice " << rt;
	return rt;
}

HRESULT m_IDirect3DDevice9::GetClipPlane(DWORD Index, float *pPlane)
{
	return m_pD3DDevice->GetClipPlane(Index, pPlane);
}

HRESULT m_IDirect3DDevice9::SetClipPlane(DWORD Index, CONST float *pPlane)
{
	return m_pD3DDevice->SetClipPlane(Index, pPlane);
}

HRESULT m_IDirect3DDevice9::Clear(DWORD Count, CONST D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
	return m_pD3DDevice->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT m_IDirect3DDevice9::GetViewport(D3DVIEWPORT9 *pViewport)
{
	return m_pD3DDevice->GetViewport(pViewport);
}

HRESULT m_IDirect3DDevice9::SetViewport(CONST D3DVIEWPORT9 *pViewport)
{
	return m_pD3DDevice->SetViewport(pViewport);
}

HRESULT m_IDirect3DDevice9::CreateVertexShader(THIS_ CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
	if (pFunction != nullptr)
	{
		Log() << "<CreateVertexShader> Disassembling shader and translating assembly to Direct3D 9 compatible code ...";

		if (*pFunction < D3DVS_VERSION(1, 0) || *pFunction > D3DVS_VERSION(1, 1))
		{
			Log() << "> Failed because of version mismatch ('" << std::showbase << std::hex << *pFunction << std::dec << std::noshowbase << "')! Only 'vs_1_x' shaders are supported.";

			return D3DERR_INVALIDCALL;
		}

		ID3DXBuffer *Disassembly = nullptr, *Assembly = nullptr, *ErrorBuffer = nullptr;

		HRESULT hr = D3DXDisassembleShader(pFunction, FALSE, nullptr, &Disassembly);

		if (FAILED(hr))
		{
			Log() << "> Failed to disassemble shader with error code " << std::hex << hr << std::dec << "!";

			return hr;
		}

		std::string SourceCode(static_cast<const char *>(Disassembly->GetBufferPointer()), Disassembly->GetBufferSize() - 1);
		const char *cstr = SourceCode.c_str();

		Log() << "> Dumping translated shader assembly:" << cstr;
	}

	return m_pD3DDevice->CreateVertexShader(pFunction, ppShader);
}

HRESULT m_IDirect3DDevice9::GetVertexShader(THIS_ IDirect3DVertexShader9** ppShader)
{
	return m_pD3DDevice->GetVertexShader(ppShader);
}

HRESULT m_IDirect3DDevice9::SetVertexShader(THIS_ IDirect3DVertexShader9* pShader)
{
	return m_pD3DDevice->SetVertexShader(pShader);
}

HRESULT m_IDirect3DDevice9::CreateQuery(THIS_ D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
	return m_pD3DDevice->CreateQuery(Type, ppQuery);
}

HRESULT m_IDirect3DDevice9::SetPixelShaderConstantB(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
{
	return m_pD3DDevice->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT m_IDirect3DDevice9::GetPixelShaderConstantB(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
	return m_pD3DDevice->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT m_IDirect3DDevice9::SetPixelShaderConstantI(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
	return m_pD3DDevice->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT m_IDirect3DDevice9::GetPixelShaderConstantI(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
	return m_pD3DDevice->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT m_IDirect3DDevice9::SetPixelShaderConstantF(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
	return m_pD3DDevice->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT m_IDirect3DDevice9::GetPixelShaderConstantF(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
	return m_pD3DDevice->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT m_IDirect3DDevice9::SetStreamSourceFreq(THIS_ UINT StreamNumber, UINT Divider)
{
	return m_pD3DDevice->SetStreamSourceFreq(StreamNumber, Divider);
}

HRESULT m_IDirect3DDevice9::GetStreamSourceFreq(THIS_ UINT StreamNumber, UINT* Divider)
{
	return m_pD3DDevice->GetStreamSourceFreq(StreamNumber, Divider);
}

HRESULT m_IDirect3DDevice9::SetVertexShaderConstantB(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
{
	return m_pD3DDevice->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT m_IDirect3DDevice9::GetVertexShaderConstantB(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
	return m_pD3DDevice->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT m_IDirect3DDevice9::SetVertexShaderConstantF(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
	return m_pD3DDevice->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT m_IDirect3DDevice9::GetVertexShaderConstantF(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
	return m_pD3DDevice->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT m_IDirect3DDevice9::SetVertexShaderConstantI(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
	return m_pD3DDevice->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT m_IDirect3DDevice9::GetVertexShaderConstantI(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
	return m_pD3DDevice->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT m_IDirect3DDevice9::SetFVF(THIS_ DWORD FVF)
{
	Log() << "SetFVF " << FVF;
	return m_pD3DDevice->SetFVF(FVF);
}

HRESULT m_IDirect3DDevice9::GetFVF(THIS_ DWORD* pFVF)
{
	Log() << "GetFVF " << *pFVF;
	return m_pD3DDevice->GetFVF(pFVF);
}

HRESULT m_IDirect3DDevice9::CreateVertexDeclaration(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
	return m_pD3DDevice->CreateVertexDeclaration(pVertexElements, ppDecl);
}

HRESULT m_IDirect3DDevice9::SetVertexDeclaration(THIS_ IDirect3DVertexDeclaration9* pDecl)
{
	return m_pD3DDevice->SetVertexDeclaration(pDecl);
}

HRESULT m_IDirect3DDevice9::GetVertexDeclaration(THIS_ IDirect3DVertexDeclaration9** ppDecl)
{
	return m_pD3DDevice->GetVertexDeclaration(ppDecl);
}

HRESULT m_IDirect3DDevice9::SetNPatchMode(THIS_ float nSegments)
{
	return m_pD3DDevice->SetNPatchMode(nSegments);
}

float m_IDirect3DDevice9::GetNPatchMode(THIS)
{
	return m_pD3DDevice->GetNPatchMode();
}

int m_IDirect3DDevice9::GetSoftwareVertexProcessing(THIS)
{
	return m_pD3DDevice->GetSoftwareVertexProcessing();
}

unsigned int m_IDirect3DDevice9::GetNumberOfSwapChains(THIS)
{
	return m_pD3DDevice->GetNumberOfSwapChains();
}

HRESULT m_IDirect3DDevice9::EvictManagedResources(THIS)
{
	return m_pD3DDevice->EvictManagedResources();
}

HRESULT m_IDirect3DDevice9::SetSoftwareVertexProcessing(THIS_ BOOL bSoftware)
{
	return m_pD3DDevice->SetSoftwareVertexProcessing(bSoftware);
}

HRESULT m_IDirect3DDevice9::SetScissorRect(THIS_ CONST RECT* pRect)
{
	return m_pD3DDevice->SetScissorRect(pRect);
}

HRESULT m_IDirect3DDevice9::GetScissorRect(THIS_ RECT* pRect)
{
	return m_pD3DDevice->GetScissorRect(pRect);
}

HRESULT m_IDirect3DDevice9::GetSamplerState(THIS_ DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
	return m_pD3DDevice->GetSamplerState(Sampler, Type, pValue);
}

HRESULT m_IDirect3DDevice9::SetSamplerState(THIS_ DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
	return m_pD3DDevice->SetSamplerState(Sampler, Type, Value);
}

HRESULT m_IDirect3DDevice9::SetDepthStencilSurface(THIS_ IDirect3DSurface9* pNewZStencil)
{
	return m_pD3DDevice->SetDepthStencilSurface(pNewZStencil);
}

HRESULT m_IDirect3DDevice9::CreateOffscreenPlainSurface(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return m_pD3DDevice->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT m_IDirect3DDevice9::ColorFill(THIS_ IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color)
{
	return m_pD3DDevice->ColorFill(pSurface, pRect, color);
}

HRESULT m_IDirect3DDevice9::StretchRect(THIS_ IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
	return m_pD3DDevice->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

HRESULT m_IDirect3DDevice9::GetFrontBufferData(THIS_ UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
	return m_pD3DDevice->GetFrontBufferData(iSwapChain, pDestSurface);
}

HRESULT m_IDirect3DDevice9::GetRenderTargetData(THIS_ IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
	return m_pD3DDevice->GetRenderTargetData(pRenderTarget, pDestSurface);
}

HRESULT m_IDirect3DDevice9::UpdateSurface(THIS_ IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint)
{
	return m_pD3DDevice->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

HRESULT m_IDirect3DDevice9::SetDialogBoxMode(THIS_ BOOL bEnableDialogs)
{
	return m_pD3DDevice->SetDialogBoxMode(bEnableDialogs);
}

HRESULT m_IDirect3DDevice9::GetSwapChain(THIS_ UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
	return m_pD3DDevice->GetSwapChain(iSwapChain, pSwapChain);
}
