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

myIDirect3DDevice9::myIDirect3DDevice9(LPDIRECT3DDEVICE9 pDevice, LPDIRECT3DDEVICE9 **ppDevice)
{
	mypD3DDevice = pDevice;
	*ppDevice = &mypD3DDevice;
}

ULONG myIDirect3DDevice9::AddRef()
{
	return mypD3DDevice->AddRef();
}

HRESULT myIDirect3DDevice9::QueryInterface(REFIID riid, LPVOID *ppvObj)
{
	return mypD3DDevice->QueryInterface(riid, ppvObj);
}

ULONG myIDirect3DDevice9::Release()
{
	return mypD3DDevice->Release();
}

HRESULT myIDirect3DDevice9::Reset(D3DPRESENT_PARAMETERS *pPresentationParameters)
{
	HRESULT hr = mypD3DDevice->Reset(pPresentationParameters);
	return hr;
}

HRESULT myIDirect3DDevice9::EndScene()
{
	return mypD3DDevice->EndScene();
}

void myIDirect3DDevice9::SetCursorPosition(int X, int Y, DWORD Flags)
{
	mypD3DDevice->SetCursorPosition(X, Y, Flags);
}

HRESULT myIDirect3DDevice9::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9 *pCursorBitmap)
{
	return mypD3DDevice->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

BOOL myIDirect3DDevice9::ShowCursor(BOOL bShow)
{
	return mypD3DDevice->ShowCursor(bShow);
}

HRESULT myIDirect3DDevice9::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain9 **ppSwapChain)
{
	return mypD3DDevice->CreateAdditionalSwapChain(pPresentationParameters, ppSwapChain);
}

HRESULT myIDirect3DDevice9::CreateCubeTexture(THIS_ UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
	return mypD3DDevice->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

HRESULT myIDirect3DDevice9::CreateDepthStencilSurface(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return mypD3DDevice->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT myIDirect3DDevice9::CreateIndexBuffer(THIS_ UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
	return mypD3DDevice->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

HRESULT myIDirect3DDevice9::CreateRenderTarget(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return mypD3DDevice->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT myIDirect3DDevice9::CreateTexture(THIS_ UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
	return mypD3DDevice->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

HRESULT myIDirect3DDevice9::CreateVertexBuffer(THIS_ UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
	return mypD3DDevice->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

HRESULT myIDirect3DDevice9::CreateVolumeTexture(THIS_ UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
	return mypD3DDevice->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

HRESULT myIDirect3DDevice9::BeginStateBlock()
{
	return mypD3DDevice->BeginStateBlock();
}

HRESULT myIDirect3DDevice9::CreateStateBlock(THIS_ D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
	return mypD3DDevice->CreateStateBlock(Type, ppSB);
}

HRESULT myIDirect3DDevice9::EndStateBlock(THIS_ IDirect3DStateBlock9** ppSB)
{
	return mypD3DDevice->EndStateBlock(ppSB);
}

HRESULT myIDirect3DDevice9::GetClipStatus(D3DCLIPSTATUS9 *pClipStatus)
{
	return mypD3DDevice->GetClipStatus(pClipStatus);
}

HRESULT myIDirect3DDevice9::GetDisplayMode(THIS_ UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
	return mypD3DDevice->GetDisplayMode(iSwapChain, pMode);
}

HRESULT myIDirect3DDevice9::GetRenderState(D3DRENDERSTATETYPE State, DWORD *pValue)
{
	return mypD3DDevice->GetRenderState(State, pValue);
}

HRESULT myIDirect3DDevice9::GetRenderTarget(THIS_ DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
	return mypD3DDevice->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

HRESULT myIDirect3DDevice9::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix)
{
	return mypD3DDevice->GetTransform(State, pMatrix);
}

HRESULT myIDirect3DDevice9::SetClipStatus(CONST D3DCLIPSTATUS9 *pClipStatus)
{
	return mypD3DDevice->SetClipStatus(pClipStatus);
}

HRESULT myIDirect3DDevice9::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
	LOG << "SetRenderState " << State << " " << Value << "\n";
	return mypD3DDevice->SetRenderState(State, Value);
}

HRESULT myIDirect3DDevice9::SetRenderTarget(THIS_ DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
	return mypD3DDevice->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

HRESULT myIDirect3DDevice9::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX *pMatrix)
{
	return mypD3DDevice->SetTransform(State, pMatrix);
}

void myIDirect3DDevice9::GetGammaRamp(THIS_ UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
	mypD3DDevice->GetGammaRamp(iSwapChain, pRamp);
}

void myIDirect3DDevice9::SetGammaRamp(THIS_ UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp)
{
	mypD3DDevice->SetGammaRamp(iSwapChain, Flags, pRamp);
}

HRESULT myIDirect3DDevice9::DeletePatch(UINT Handle)
{
	return mypD3DDevice->DeletePatch(Handle);
}

HRESULT myIDirect3DDevice9::DrawRectPatch(UINT Handle, CONST float *pNumSegs, CONST D3DRECTPATCH_INFO *pRectPatchInfo)
{
	return mypD3DDevice->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT myIDirect3DDevice9::DrawTriPatch(UINT Handle, CONST float *pNumSegs, CONST D3DTRIPATCH_INFO *pTriPatchInfo)
{
	return mypD3DDevice->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT myIDirect3DDevice9::GetIndices(THIS_ IDirect3DIndexBuffer9** ppIndexData)
{
	return mypD3DDevice->GetIndices(ppIndexData);
}

HRESULT myIDirect3DDevice9::SetIndices(THIS_ IDirect3DIndexBuffer9* pIndexData)
{
	return mypD3DDevice->SetIndices(pIndexData);
}

UINT myIDirect3DDevice9::GetAvailableTextureMem()
{
	return mypD3DDevice->GetAvailableTextureMem();
}

HRESULT myIDirect3DDevice9::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
	return mypD3DDevice->GetCreationParameters(pParameters);
}

HRESULT myIDirect3DDevice9::GetDeviceCaps(D3DCAPS9 *pCaps)
{
	return mypD3DDevice->GetDeviceCaps(pCaps);
}

HRESULT myIDirect3DDevice9::GetDirect3D(IDirect3D9 **ppD3D9)
{
	return mypD3DDevice->GetDirect3D(ppD3D9);
}

HRESULT myIDirect3DDevice9::GetRasterStatus(THIS_ UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
	return mypD3DDevice->GetRasterStatus(iSwapChain, pRasterStatus);
}

HRESULT myIDirect3DDevice9::GetLight(DWORD Index, D3DLIGHT9 *pLight)
{
	return mypD3DDevice->GetLight(Index, pLight);
}

HRESULT myIDirect3DDevice9::GetLightEnable(DWORD Index, BOOL *pEnable)
{
	return mypD3DDevice->GetLightEnable(Index, pEnable);
}

HRESULT myIDirect3DDevice9::GetMaterial(D3DMATERIAL9 *pMaterial)
{
	return mypD3DDevice->GetMaterial(pMaterial);
}

HRESULT myIDirect3DDevice9::LightEnable(DWORD LightIndex, BOOL bEnable)
{
	return mypD3DDevice->LightEnable(LightIndex, bEnable);
}

HRESULT myIDirect3DDevice9::SetLight(DWORD Index, CONST D3DLIGHT9 *pLight)
{

	return mypD3DDevice->SetLight(Index, pLight);
}

HRESULT myIDirect3DDevice9::SetMaterial(CONST D3DMATERIAL9 *pMaterial)
{
	return mypD3DDevice->SetMaterial(pMaterial);
}

HRESULT myIDirect3DDevice9::MultiplyTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX *pMatrix)
{
	return mypD3DDevice->MultiplyTransform(State, pMatrix);
}

HRESULT myIDirect3DDevice9::ProcessVertices(THIS_ UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
	return mypD3DDevice->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

HRESULT myIDirect3DDevice9::TestCooperativeLevel()
{
	return mypD3DDevice->TestCooperativeLevel();
}

HRESULT myIDirect3DDevice9::GetCurrentTexturePalette(UINT *pPaletteNumber)
{
	return mypD3DDevice->GetCurrentTexturePalette(pPaletteNumber);
}

HRESULT myIDirect3DDevice9::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY *pEntries)
{
	return mypD3DDevice->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT myIDirect3DDevice9::SetCurrentTexturePalette(UINT PaletteNumber)
{
	return mypD3DDevice->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT myIDirect3DDevice9::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY *pEntries)
{
	return mypD3DDevice->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT myIDirect3DDevice9::CreatePixelShader(THIS_ CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
	if (pFunction != nullptr)
	{
		LOG << "<CreatePixelShader> Disassembling shader and translating assembly to Direct3D 9 compatible code ...\n";

		/*if (*pFunction < D3DVS_VERSION(1, 0) || *pFunction > D3DVS_VERSION(1, 1))
		{
		LOG << "> Failed because of version mismatch ('" << std::showbase << std::hex << *pFunction << std::dec << std::noshowbase << "')! Only 'vs_1_x' shaders are supported.\n";

		return D3DERR_INVALIDCALL;
		}*/

		ID3DXBuffer *Disassembly = nullptr, *Assembly = nullptr, *ErrorBuffer = nullptr;

		HRESULT hr = D3DXDisassembleShader(pFunction, FALSE, nullptr, &Disassembly);

		if (FAILED(hr))
		{
			LOG << "> Failed to disassemble shader with error code " << std::hex << hr << std::dec << "!\n";

			return hr;
		}

		std::string SourceCode(static_cast<const char *>(Disassembly->GetBufferPointer()), Disassembly->GetBufferSize() - 1);
		const char *cstr = SourceCode.c_str();

		LOG << "> Dumping translated shader assembly:\n" << cstr;
	}

	return mypD3DDevice->CreatePixelShader(pFunction, ppShader);
}

HRESULT myIDirect3DDevice9::GetPixelShader(THIS_ IDirect3DPixelShader9** ppShader)
{
	return mypD3DDevice->GetPixelShader(ppShader);
}

HRESULT myIDirect3DDevice9::SetPixelShader(THIS_ IDirect3DPixelShader9* pShader)
{
	return mypD3DDevice->SetPixelShader(pShader);
}

HRESULT myIDirect3DDevice9::Present(CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion)
{
	return mypD3DDevice->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT myIDirect3DDevice9::DrawIndexedPrimitive(THIS_ D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	return mypD3DDevice->DrawIndexedPrimitive(Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT myIDirect3DDevice9::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinIndex, UINT NumVertices, UINT PrimitiveCount, CONST void *pIndexData, D3DFORMAT IndexDataFormat, CONST void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return mypD3DDevice->DrawIndexedPrimitiveUP(PrimitiveType, MinIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT myIDirect3DDevice9::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	return mypD3DDevice->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT myIDirect3DDevice9::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return mypD3DDevice->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT myIDirect3DDevice9::BeginScene()
{
	return mypD3DDevice->BeginScene();
}

HRESULT myIDirect3DDevice9::GetStreamSource(THIS_ UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* OffsetInBytes, UINT* pStride)
{
	return mypD3DDevice->GetStreamSource(StreamNumber, ppStreamData, OffsetInBytes, pStride);
}

HRESULT myIDirect3DDevice9::SetStreamSource(THIS_ UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
	return mypD3DDevice->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT myIDirect3DDevice9::GetBackBuffer(THIS_ UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
	return mypD3DDevice->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
}

HRESULT myIDirect3DDevice9::GetDepthStencilSurface(IDirect3DSurface9 **ppZStencilSurface)
{
	return mypD3DDevice->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT myIDirect3DDevice9::GetTexture(DWORD Stage, IDirect3DBaseTexture9 **ppTexture)
{
	return mypD3DDevice->GetTexture(Stage, ppTexture);
}

HRESULT myIDirect3DDevice9::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue)
{
	return mypD3DDevice->GetTextureStageState(Stage, Type, pValue);
}

HRESULT myIDirect3DDevice9::SetTexture(DWORD Stage, IDirect3DBaseTexture9 *pTexture)
{
	return mypD3DDevice->SetTexture(Stage, pTexture);
}

HRESULT myIDirect3DDevice9::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
	LOG << "SetTextureStageState " << Stage << " " << Type << " " << Value << "\n";
	return mypD3DDevice->SetTextureStageState(Stage, Type, Value);
}

HRESULT myIDirect3DDevice9::UpdateTexture(IDirect3DBaseTexture9 *pSourceTexture, IDirect3DBaseTexture9 *pDestinationTexture)
{
	return mypD3DDevice->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT myIDirect3DDevice9::ValidateDevice(DWORD *pNumPasses)
{
	HRESULT rt = mypD3DDevice->ValidateDevice(pNumPasses);
	LOG << "ValidateDevice " << rt << "\n";
	return rt;
}

HRESULT myIDirect3DDevice9::GetClipPlane(DWORD Index, float *pPlane)
{
	return mypD3DDevice->GetClipPlane(Index, pPlane);
}

HRESULT myIDirect3DDevice9::SetClipPlane(DWORD Index, CONST float *pPlane)
{
	return mypD3DDevice->SetClipPlane(Index, pPlane);
}

HRESULT myIDirect3DDevice9::Clear(DWORD Count, CONST D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
	return mypD3DDevice->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT myIDirect3DDevice9::GetViewport(D3DVIEWPORT9 *pViewport)
{
	return mypD3DDevice->GetViewport(pViewport);
}

HRESULT myIDirect3DDevice9::SetViewport(CONST D3DVIEWPORT9 *pViewport)
{
	return mypD3DDevice->SetViewport(pViewport);
}

HRESULT myIDirect3DDevice9::CreateVertexShader(THIS_ CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
	if (pFunction != nullptr)
	{
		LOG << "<CreateVertexShader> Disassembling shader and translating assembly to Direct3D 9 compatible code ...";

		if (*pFunction < D3DVS_VERSION(1, 0) || *pFunction > D3DVS_VERSION(1, 1))
		{
			LOG << "> Failed because of version mismatch ('" << std::showbase << std::hex << *pFunction << std::dec << std::noshowbase << "')! Only 'vs_1_x' shaders are supported.";

			return D3DERR_INVALIDCALL;
		}

		ID3DXBuffer *Disassembly = nullptr, *Assembly = nullptr, *ErrorBuffer = nullptr;

		HRESULT hr = D3DXDisassembleShader(pFunction, FALSE, nullptr, &Disassembly);

		if (FAILED(hr))
		{
			LOG << "> Failed to disassemble shader with error code " << std::hex << hr << std::dec << "!";

			return hr;
		}

		std::string SourceCode(static_cast<const char *>(Disassembly->GetBufferPointer()), Disassembly->GetBufferSize() - 1);
		const char *cstr = SourceCode.c_str();

		LOG << "> Dumping translated shader assembly:\n" << cstr;
	}

	return mypD3DDevice->CreateVertexShader(pFunction, ppShader);
}

HRESULT myIDirect3DDevice9::GetVertexShader(THIS_ IDirect3DVertexShader9** ppShader)
{
	return mypD3DDevice->GetVertexShader(ppShader);
}

HRESULT myIDirect3DDevice9::SetVertexShader(THIS_ IDirect3DVertexShader9* pShader)
{
	return mypD3DDevice->SetVertexShader(pShader);
}

HRESULT myIDirect3DDevice9::CreateQuery(THIS_ D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
	return mypD3DDevice->CreateQuery(Type, ppQuery);
}

HRESULT myIDirect3DDevice9::SetPixelShaderConstantB(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
{
	return mypD3DDevice->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT myIDirect3DDevice9::GetPixelShaderConstantB(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
	return mypD3DDevice->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT myIDirect3DDevice9::SetPixelShaderConstantI(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
	return mypD3DDevice->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT myIDirect3DDevice9::GetPixelShaderConstantI(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
	return mypD3DDevice->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT myIDirect3DDevice9::SetPixelShaderConstantF(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
	return mypD3DDevice->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT myIDirect3DDevice9::GetPixelShaderConstantF(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
	return mypD3DDevice->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT myIDirect3DDevice9::SetStreamSourceFreq(THIS_ UINT StreamNumber, UINT Divider)
{
	return mypD3DDevice->SetStreamSourceFreq(StreamNumber, Divider);
}

HRESULT myIDirect3DDevice9::GetStreamSourceFreq(THIS_ UINT StreamNumber, UINT* Divider)
{
	return mypD3DDevice->GetStreamSourceFreq(StreamNumber, Divider);
}

HRESULT myIDirect3DDevice9::SetVertexShaderConstantB(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
{
	return mypD3DDevice->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT myIDirect3DDevice9::GetVertexShaderConstantB(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
	return mypD3DDevice->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT myIDirect3DDevice9::SetVertexShaderConstantF(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
{
	return mypD3DDevice->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT myIDirect3DDevice9::GetVertexShaderConstantF(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
	return mypD3DDevice->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT myIDirect3DDevice9::SetVertexShaderConstantI(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
{
	return mypD3DDevice->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT myIDirect3DDevice9::GetVertexShaderConstantI(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
	return mypD3DDevice->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT myIDirect3DDevice9::SetFVF(THIS_ DWORD FVF)
{
	LOG << "SetFVF " << FVF << "\n";
	return mypD3DDevice->SetFVF(FVF);
}

HRESULT myIDirect3DDevice9::GetFVF(THIS_ DWORD* pFVF)
{
	LOG << "GetFVF " << *pFVF << "\n";
	return mypD3DDevice->GetFVF(pFVF);
}

HRESULT myIDirect3DDevice9::CreateVertexDeclaration(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
	return mypD3DDevice->CreateVertexDeclaration(pVertexElements, ppDecl);
}

HRESULT myIDirect3DDevice9::SetVertexDeclaration(THIS_ IDirect3DVertexDeclaration9* pDecl)
{
	return mypD3DDevice->SetVertexDeclaration(pDecl);
}

HRESULT myIDirect3DDevice9::GetVertexDeclaration(THIS_ IDirect3DVertexDeclaration9** ppDecl)
{
	return mypD3DDevice->GetVertexDeclaration(ppDecl);
}

HRESULT myIDirect3DDevice9::SetNPatchMode(THIS_ float nSegments)
{
	return mypD3DDevice->SetNPatchMode(nSegments);
}

float myIDirect3DDevice9::GetNPatchMode(THIS)
{
	return mypD3DDevice->GetNPatchMode();
}

int myIDirect3DDevice9::GetSoftwareVertexProcessing(THIS)
{
	return mypD3DDevice->GetSoftwareVertexProcessing();
}

unsigned int myIDirect3DDevice9::GetNumberOfSwapChains(THIS)
{
	return mypD3DDevice->GetNumberOfSwapChains();
}

HRESULT myIDirect3DDevice9::EvictManagedResources(THIS)
{
	return mypD3DDevice->EvictManagedResources();
}

HRESULT myIDirect3DDevice9::SetSoftwareVertexProcessing(THIS_ BOOL bSoftware)
{
	return mypD3DDevice->SetSoftwareVertexProcessing(bSoftware);
}

HRESULT myIDirect3DDevice9::SetScissorRect(THIS_ CONST RECT* pRect)
{
	return mypD3DDevice->SetScissorRect(pRect);
}

HRESULT myIDirect3DDevice9::GetScissorRect(THIS_ RECT* pRect)
{
	return mypD3DDevice->GetScissorRect(pRect);
}

HRESULT myIDirect3DDevice9::GetSamplerState(THIS_ DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
	return mypD3DDevice->GetSamplerState(Sampler, Type, pValue);
}

HRESULT myIDirect3DDevice9::SetSamplerState(THIS_ DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
	return mypD3DDevice->SetSamplerState(Sampler, Type, Value);
}

HRESULT myIDirect3DDevice9::SetDepthStencilSurface(THIS_ IDirect3DSurface9* pNewZStencil)
{
	return mypD3DDevice->SetDepthStencilSurface(pNewZStencil);
}

HRESULT myIDirect3DDevice9::CreateOffscreenPlainSurface(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return mypD3DDevice->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT myIDirect3DDevice9::ColorFill(THIS_ IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color)
{
	return mypD3DDevice->ColorFill(pSurface, pRect, color);
}

HRESULT myIDirect3DDevice9::StretchRect(THIS_ IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
	return mypD3DDevice->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

HRESULT myIDirect3DDevice9::GetFrontBufferData(THIS_ UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
	return mypD3DDevice->GetFrontBufferData(iSwapChain, pDestSurface);
}

HRESULT myIDirect3DDevice9::GetRenderTargetData(THIS_ IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
	return mypD3DDevice->GetRenderTargetData(pRenderTarget, pDestSurface);
}

HRESULT myIDirect3DDevice9::UpdateSurface(THIS_ IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint)
{
	return mypD3DDevice->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

HRESULT myIDirect3DDevice9::SetDialogBoxMode(THIS_ BOOL bEnableDialogs)
{
	return mypD3DDevice->SetDialogBoxMode(bEnableDialogs);
}

HRESULT myIDirect3DDevice9::GetSwapChain(THIS_ UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
	return mypD3DDevice->GetSwapChain(iSwapChain, pSwapChain);
}
