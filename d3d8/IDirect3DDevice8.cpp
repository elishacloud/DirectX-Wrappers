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
*/

#include "d3d8.h"
#include "d3dx9.h"

myIDirect3DDevice8::myIDirect3DDevice8(LPDIRECT3DDEVICE8 pDevice, LPDIRECT3DDEVICE8 **ppDevice)
{
	mypD3DDevice = pDevice;
	*ppDevice = &mypD3DDevice;
}

ULONG myIDirect3DDevice8::AddRef()
{
	return mypD3DDevice->AddRef();
}

HRESULT myIDirect3DDevice8::QueryInterface(REFIID riid, LPVOID *ppvObj)
{
	return mypD3DDevice->QueryInterface(riid, ppvObj);
}

ULONG myIDirect3DDevice8::Release()
{
	return mypD3DDevice->Release();
}

HRESULT myIDirect3DDevice8::Reset(D3DPRESENT_PARAMETERS *pPresentationParameters)
{
	HRESULT hr = mypD3DDevice->Reset(pPresentationParameters);
	return hr;
}

HRESULT myIDirect3DDevice8::EndScene()
{
	return mypD3DDevice->EndScene();
}

void myIDirect3DDevice8::SetCursorPosition(THIS_ UINT XScreenSpace, UINT YScreenSpace, DWORD Flags)
{
	mypD3DDevice->SetCursorPosition(XScreenSpace, YScreenSpace, Flags);
}

HRESULT myIDirect3DDevice8::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface8 *pCursorBitmap)
{
	return mypD3DDevice->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

BOOL myIDirect3DDevice8::ShowCursor(BOOL bShow)
{
	return mypD3DDevice->ShowCursor(bShow);
}

HRESULT myIDirect3DDevice8::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain8 **ppSwapChain)
{
	return mypD3DDevice->CreateAdditionalSwapChain(pPresentationParameters, ppSwapChain);
}

HRESULT myIDirect3DDevice8::CreateCubeTexture(THIS_ UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture8** ppCubeTexture)
{
	return mypD3DDevice->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture);
}

HRESULT myIDirect3DDevice8::CreateDepthStencilSurface(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, IDirect3DSurface8** ppSurface)
{
	return mypD3DDevice->CreateDepthStencilSurface(Width, Height, Format, MultiSample, ppSurface);
}

HRESULT myIDirect3DDevice8::CreateIndexBuffer(THIS_ UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer8** ppIndexBuffer)
{
	return mypD3DDevice->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer);
}

HRESULT myIDirect3DDevice8::CreateRenderTarget(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, BOOL Lockable, IDirect3DSurface8** ppSurface)
{
	return mypD3DDevice->CreateRenderTarget(Width, Height, Format, MultiSample, Lockable, ppSurface);
}

HRESULT myIDirect3DDevice8::CreateTexture(THIS_ UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture8** ppTexture)
{
	return mypD3DDevice->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture);
}

HRESULT myIDirect3DDevice8::CreateVertexBuffer(THIS_ UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer8** ppVertexBuffer)
{
	return mypD3DDevice->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer);
}

HRESULT myIDirect3DDevice8::CreateVolumeTexture(THIS_ UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture8** ppVolumeTexture)
{
	return mypD3DDevice->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture);
}

HRESULT myIDirect3DDevice8::BeginStateBlock()
{
	return mypD3DDevice->BeginStateBlock();
}

HRESULT myIDirect3DDevice8::CreateStateBlock(THIS_ D3DSTATEBLOCKTYPE Type, DWORD* pToken)
{
	return mypD3DDevice->CreateStateBlock(Type, pToken);
}

HRESULT myIDirect3DDevice8::ApplyStateBlock(THIS_ DWORD Token)
{
	return mypD3DDevice->ApplyStateBlock(Token);
}

HRESULT myIDirect3DDevice8::CaptureStateBlock(THIS_ DWORD Token)
{
	return mypD3DDevice->CaptureStateBlock(Token);
}

HRESULT myIDirect3DDevice8::DeleteStateBlock(THIS_ DWORD Token)
{
	return mypD3DDevice->DeleteStateBlock(Token);
}

HRESULT myIDirect3DDevice8::EndStateBlock(THIS_ DWORD* pToken)
{
	return mypD3DDevice->EndStateBlock(pToken);
}

HRESULT myIDirect3DDevice8::GetClipStatus(D3DCLIPSTATUS8 *pClipStatus)
{
	return mypD3DDevice->GetClipStatus(pClipStatus);
}

HRESULT myIDirect3DDevice8::GetDisplayMode(THIS_ D3DDISPLAYMODE* pMode)
{
	return mypD3DDevice->GetDisplayMode(pMode);
}

HRESULT myIDirect3DDevice8::GetRenderState(D3DRENDERSTATETYPE State, DWORD *pValue)
{
	return mypD3DDevice->GetRenderState(State, pValue);
}

HRESULT myIDirect3DDevice8::GetRenderTarget(THIS_ IDirect3DSurface8** ppRenderTarget)
{
	return mypD3DDevice->GetRenderTarget(ppRenderTarget);
}

HRESULT myIDirect3DDevice8::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix)
{
	return mypD3DDevice->GetTransform(State, pMatrix);
}

HRESULT myIDirect3DDevice8::SetClipStatus(CONST D3DCLIPSTATUS8 *pClipStatus)
{
	return mypD3DDevice->SetClipStatus(pClipStatus);
}

HRESULT myIDirect3DDevice8::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
	LOG << "SetRenderState " << State << " " << Value << "\n";
	return mypD3DDevice->SetRenderState(State, Value);
}

HRESULT myIDirect3DDevice8::SetRenderTarget(THIS_ IDirect3DSurface8* pRenderTarget, IDirect3DSurface8* pNewZStencil)
{
	return mypD3DDevice->SetRenderTarget(pRenderTarget, pNewZStencil);
}

HRESULT myIDirect3DDevice8::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX *pMatrix)
{
	return mypD3DDevice->SetTransform(State, pMatrix);
}

void myIDirect3DDevice8::GetGammaRamp(THIS_ D3DGAMMARAMP* pRamp)
{
	mypD3DDevice->GetGammaRamp(pRamp);
}

void myIDirect3DDevice8::SetGammaRamp(THIS_ DWORD Flags, CONST D3DGAMMARAMP* pRamp)
{
	mypD3DDevice->SetGammaRamp(Flags, pRamp);
}

HRESULT myIDirect3DDevice8::DeletePatch(UINT Handle)
{
	return mypD3DDevice->DeletePatch(Handle);
}

HRESULT myIDirect3DDevice8::DrawRectPatch(UINT Handle, CONST float *pNumSegs, CONST D3DRECTPATCH_INFO *pRectPatchInfo)
{
	return mypD3DDevice->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT myIDirect3DDevice8::DrawTriPatch(UINT Handle, CONST float *pNumSegs, CONST D3DTRIPATCH_INFO *pTriPatchInfo)
{
	return mypD3DDevice->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT myIDirect3DDevice8::GetIndices(THIS_ IDirect3DIndexBuffer8** ppIndexData, UINT* pBaseVertexIndex)
{
	return mypD3DDevice->GetIndices(ppIndexData, pBaseVertexIndex);
}

HRESULT myIDirect3DDevice8::SetIndices(THIS_ IDirect3DIndexBuffer8* pIndexData, UINT BaseVertexIndex)
{
	return mypD3DDevice->SetIndices(pIndexData, BaseVertexIndex);
}

UINT myIDirect3DDevice8::GetAvailableTextureMem()
{
	return mypD3DDevice->GetAvailableTextureMem();
}

HRESULT myIDirect3DDevice8::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
	return mypD3DDevice->GetCreationParameters(pParameters);
}

HRESULT myIDirect3DDevice8::GetDeviceCaps(D3DCAPS8 *pCaps)
{
	return mypD3DDevice->GetDeviceCaps(pCaps);
}

HRESULT myIDirect3DDevice8::GetDirect3D(IDirect3D8 **ppD3D9)
{
	return mypD3DDevice->GetDirect3D(ppD3D9);
}

HRESULT myIDirect3DDevice8::GetRasterStatus(THIS_ D3DRASTER_STATUS* pRasterStatus)
{
	return mypD3DDevice->GetRasterStatus(pRasterStatus);
}

HRESULT myIDirect3DDevice8::GetLight(DWORD Index, D3DLIGHT8 *pLight)
{
	return mypD3DDevice->GetLight(Index, pLight);
}

HRESULT myIDirect3DDevice8::GetLightEnable(DWORD Index, BOOL *pEnable)
{
	return mypD3DDevice->GetLightEnable(Index, pEnable);
}

HRESULT myIDirect3DDevice8::GetMaterial(D3DMATERIAL8 *pMaterial)
{
	return mypD3DDevice->GetMaterial(pMaterial);
}

HRESULT myIDirect3DDevice8::LightEnable(DWORD LightIndex, BOOL bEnable)
{
	return mypD3DDevice->LightEnable(LightIndex, bEnable);
}

HRESULT myIDirect3DDevice8::SetLight(DWORD Index, CONST D3DLIGHT8 *pLight)
{

	return mypD3DDevice->SetLight(Index, pLight);
}

HRESULT myIDirect3DDevice8::SetMaterial(CONST D3DMATERIAL8 *pMaterial)
{
	return mypD3DDevice->SetMaterial(pMaterial);
}

HRESULT myIDirect3DDevice8::MultiplyTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX *pMatrix)
{
	return mypD3DDevice->MultiplyTransform(State, pMatrix);
}

HRESULT myIDirect3DDevice8::ProcessVertices(THIS_ UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer8* pDestBuffer, DWORD Flags)
{
	return mypD3DDevice->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, Flags);
}

HRESULT myIDirect3DDevice8::TestCooperativeLevel()
{
	return mypD3DDevice->TestCooperativeLevel();
}

HRESULT myIDirect3DDevice8::GetCurrentTexturePalette(UINT *pPaletteNumber)
{
	return mypD3DDevice->GetCurrentTexturePalette(pPaletteNumber);
}

HRESULT myIDirect3DDevice8::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY *pEntries)
{
	return mypD3DDevice->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT myIDirect3DDevice8::SetCurrentTexturePalette(UINT PaletteNumber)
{
	return mypD3DDevice->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT myIDirect3DDevice8::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY *pEntries)
{
	return mypD3DDevice->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT myIDirect3DDevice8::CreatePixelShader(THIS_ CONST DWORD* pFunction, DWORD* pHandle)
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

	return mypD3DDevice->CreatePixelShader(pFunction, pHandle);
}

HRESULT myIDirect3DDevice8::GetPixelShader(THIS_ DWORD* pHandle)
{
	return mypD3DDevice->GetPixelShader(pHandle);
}

HRESULT myIDirect3DDevice8::SetPixelShader(THIS_ DWORD Handle)
{
	return mypD3DDevice->SetPixelShader(Handle);
}

HRESULT myIDirect3DDevice8::DeletePixelShader(THIS_ DWORD Handle)
{
	return mypD3DDevice->DeletePixelShader(Handle);
}

HRESULT myIDirect3DDevice8::GetPixelShaderFunction(THIS_ DWORD Handle, void* pData, DWORD* pSizeOfData)
{
	return mypD3DDevice->GetPixelShaderFunction(Handle, pData, pSizeOfData);
}

HRESULT myIDirect3DDevice8::Present(CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion)
{
	return mypD3DDevice->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT myIDirect3DDevice8::DrawIndexedPrimitive(THIS_ D3DPRIMITIVETYPE Type, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	return mypD3DDevice->DrawIndexedPrimitive(Type, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT myIDirect3DDevice8::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinIndex, UINT NumVertices, UINT PrimitiveCount, CONST void *pIndexData, D3DFORMAT IndexDataFormat, CONST void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return mypD3DDevice->DrawIndexedPrimitiveUP(PrimitiveType, MinIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT myIDirect3DDevice8::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	return mypD3DDevice->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT myIDirect3DDevice8::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return mypD3DDevice->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT myIDirect3DDevice8::BeginScene()
{
	return mypD3DDevice->BeginScene();
}

HRESULT myIDirect3DDevice8::GetStreamSource(THIS_ UINT StreamNumber, IDirect3DVertexBuffer8** ppStreamData, UINT* pStride)
{
	return mypD3DDevice->GetStreamSource(StreamNumber, ppStreamData, pStride);
}

HRESULT myIDirect3DDevice8::SetStreamSource(THIS_ UINT StreamNumber, IDirect3DVertexBuffer8* pStreamData, UINT Stride)
{
	return mypD3DDevice->SetStreamSource(StreamNumber, pStreamData, Stride);
}

HRESULT myIDirect3DDevice8::GetBackBuffer(THIS_ UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface8** ppBackBuffer)
{
	return mypD3DDevice->GetBackBuffer(iBackBuffer, Type, ppBackBuffer);
}

HRESULT myIDirect3DDevice8::GetDepthStencilSurface(IDirect3DSurface8 **ppZStencilSurface)
{
	return mypD3DDevice->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT myIDirect3DDevice8::GetTexture(DWORD Stage, IDirect3DBaseTexture8 **ppTexture)
{
	return mypD3DDevice->GetTexture(Stage, ppTexture);
}

HRESULT myIDirect3DDevice8::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue)
{
	return mypD3DDevice->GetTextureStageState(Stage, Type, pValue);
}

HRESULT myIDirect3DDevice8::SetTexture(DWORD Stage, IDirect3DBaseTexture8 *pTexture)
{
	return mypD3DDevice->SetTexture(Stage, pTexture);
}

HRESULT myIDirect3DDevice8::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
	LOG << "SetTextureStageState " << Stage << " " << Type << " " << Value << "\n";
	return mypD3DDevice->SetTextureStageState(Stage, Type, Value);
}

HRESULT myIDirect3DDevice8::UpdateTexture(IDirect3DBaseTexture8 *pSourceTexture, IDirect3DBaseTexture8 *pDestinationTexture)
{
	return mypD3DDevice->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT myIDirect3DDevice8::ValidateDevice(DWORD *pNumPasses)
{
	HRESULT rt = mypD3DDevice->ValidateDevice(pNumPasses);
	LOG << "ValidateDevice " << rt << "\n";
	return rt;
}

HRESULT myIDirect3DDevice8::GetClipPlane(DWORD Index, float *pPlane)
{
	return mypD3DDevice->GetClipPlane(Index, pPlane);
}

HRESULT myIDirect3DDevice8::SetClipPlane(DWORD Index, CONST float *pPlane)
{
	return mypD3DDevice->SetClipPlane(Index, pPlane);
}

HRESULT myIDirect3DDevice8::Clear(DWORD Count, CONST D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
	return mypD3DDevice->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT myIDirect3DDevice8::GetViewport(D3DVIEWPORT8 *pViewport)
{
	return mypD3DDevice->GetViewport(pViewport);
}

HRESULT myIDirect3DDevice8::SetViewport(CONST D3DVIEWPORT8 *pViewport)
{
	return mypD3DDevice->SetViewport(pViewport);
}

HRESULT myIDirect3DDevice8::CreateVertexShader(THIS_ CONST DWORD* pDeclaration, CONST DWORD* pFunction, DWORD* pHandle, DWORD Usage)
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

	return mypD3DDevice->CreateVertexShader(pDeclaration, pFunction, pHandle, Usage);
}

HRESULT myIDirect3DDevice8::GetVertexShader(THIS_ DWORD* pHandle)
{
	return mypD3DDevice->GetVertexShader(pHandle);
}

HRESULT myIDirect3DDevice8::SetVertexShader(THIS_ DWORD Handle)
{
	return mypD3DDevice->SetVertexShader(Handle);
}

HRESULT myIDirect3DDevice8::DeleteVertexShader(THIS_ DWORD Handle)
{
	return mypD3DDevice->DeleteVertexShader(Handle);
}

HRESULT myIDirect3DDevice8::GetVertexShaderDeclaration(THIS_ DWORD Handle, void* pData, DWORD* pSizeOfData)
{
	return mypD3DDevice->GetVertexShaderDeclaration(Handle, pData, pSizeOfData);
}

HRESULT myIDirect3DDevice8::GetVertexShaderFunction(THIS_ DWORD Handle, void* pData, DWORD* pSizeOfData)
{
	return mypD3DDevice->GetVertexShaderFunction(Handle, pData, pSizeOfData);
}

HRESULT myIDirect3DDevice8::SetPixelShaderConstant(THIS_ DWORD Register, CONST void* pConstantData, DWORD ConstantCount)
{
	return mypD3DDevice->SetPixelShaderConstant(Register, pConstantData, ConstantCount);
}

HRESULT myIDirect3DDevice8::GetPixelShaderConstant(THIS_ DWORD Register, void* pConstantData, DWORD ConstantCount)
{
	return mypD3DDevice->GetPixelShaderConstant(Register, pConstantData, ConstantCount);
}


HRESULT myIDirect3DDevice8::SetVertexShaderConstant(THIS_ DWORD Register, CONST void* pConstantData, DWORD ConstantCount)
{
	return mypD3DDevice->SetVertexShaderConstant(Register, pConstantData, ConstantCount);
}

HRESULT myIDirect3DDevice8::GetVertexShaderConstant(THIS_ DWORD Register, void* pConstantData, DWORD ConstantCount)
{
	return mypD3DDevice->GetVertexShaderConstant(Register, pConstantData, ConstantCount);
}

HRESULT myIDirect3DDevice8::ResourceManagerDiscardBytes(THIS_ DWORD Bytes)
{
	return mypD3DDevice->ResourceManagerDiscardBytes(Bytes);
}

HRESULT myIDirect3DDevice8::CreateImageSurface(THIS_ UINT Width, UINT Height, D3DFORMAT Format, IDirect3DSurface8** ppSurface)
{
	return mypD3DDevice->CreateImageSurface(Width, Height, Format, ppSurface);
}

HRESULT myIDirect3DDevice8::CopyRects(THIS_ IDirect3DSurface8* pSourceSurface, CONST RECT* pSourceRectsArray, UINT cRects, IDirect3DSurface8* pDestinationSurface, CONST POINT* pDestPointsArray)
{
	return mypD3DDevice->CopyRects(pSourceSurface, pSourceRectsArray, cRects, pDestinationSurface, pDestPointsArray);
}

HRESULT myIDirect3DDevice8::GetFrontBuffer(THIS_ IDirect3DSurface8* pDestSurface)
{
	return mypD3DDevice->GetFrontBuffer(pDestSurface);
}

HRESULT myIDirect3DDevice8::GetInfo(THIS_ DWORD DevInfoID, void* pDevInfoStruct, DWORD DevInfoStructSize)
{
	return mypD3DDevice->GetInfo(DevInfoID, pDevInfoStruct, DevInfoStructSize);
}
