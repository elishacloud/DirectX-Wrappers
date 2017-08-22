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

HRESULT myIDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType,
	HWND hFocusWindow, DWORD BehaviorFlags,
	D3DPRESENT_PARAMETERS *pPresentationParameters,
	IDirect3DDevice9 **ppReturnedDeviceInterface)
{
	LPDIRECT3DDEVICE9 *temp = ppReturnedDeviceInterface;

	*temp = new myIDirect3DDevice9(*ppReturnedDeviceInterface, &ppReturnedDeviceInterface);
	*ppReturnedDeviceInterface = *temp;
	delete temp;

	HRESULT hr = mypD3D->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);

	return hr;
}

ULONG myIDirect3D9::AddRef()
{
	return mypD3D->AddRef();
}

HRESULT myIDirect3D9::QueryInterface(REFIID riid, LPVOID *ppvObj)
{
	return mypD3D->QueryInterface(riid, ppvObj);
}

ULONG myIDirect3D9::Release()
{
	return mypD3D->Release();
}

HRESULT myIDirect3D9::EnumAdapterModes(THIS_ UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
	return mypD3D->EnumAdapterModes(Adapter, Format, Mode, pMode);
}

UINT myIDirect3D9::GetAdapterCount()
{
	UINT Count = mypD3D->GetAdapterCount();
	LOG << "GetAdapterCount " << Count << "\n";
	return  Count;
}

HRESULT myIDirect3D9::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE *pMode)
{
	return mypD3D->GetAdapterDisplayMode(Adapter, pMode);
}

HRESULT myIDirect3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9 *pIdentifier)
{
	return mypD3D->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

UINT myIDirect3D9::GetAdapterModeCount(THIS_ UINT Adapter, D3DFORMAT Format)
{
	UINT Count = mypD3D->GetAdapterModeCount(Adapter, Format);
	LOG << "GetAdapterModeCount Adapter " << Adapter << " Format " << Format << " Count " << Count << "\n";
	return Count;
}

HMONITOR myIDirect3D9::GetAdapterMonitor(UINT Adapter)
{
	return mypD3D->GetAdapterMonitor(Adapter);
}

HRESULT myIDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9 *pCaps)
{
	return mypD3D->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

HRESULT myIDirect3D9::RegisterSoftwareDevice(void *pInitializeFunction)
{
	return mypD3D->RegisterSoftwareDevice(pInitializeFunction);
}

HRESULT myIDirect3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
	LOG << "CheckDepthStencilMatch " << Adapter << " " << DeviceType << " " << AdapterFormat << " " << RenderTargetFormat << " " << DepthStencilFormat << "\n";
	return mypD3D->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

HRESULT myIDirect3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
	return mypD3D->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

HRESULT myIDirect3D9::CheckDeviceMultiSampleType(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
	return mypD3D->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
}

HRESULT myIDirect3D9::CheckDeviceType(UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed)
{
	return mypD3D->CheckDeviceType(Adapter, CheckType, DisplayFormat, BackBufferFormat, Windowed);
}


HRESULT myIDirect3D9::CheckDeviceFormatConversion(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
	return mypD3D->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
}
