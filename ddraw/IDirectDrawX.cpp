/**
* Copyright (C) 2018 Elisha Riedlinger
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

#include "ddraw.h"

std::unordered_map<HWND, IDirectDraw7*> g_hookmap;

/************************/
/*** IUnknown methods ***/
/************************/

HRESULT m_IDirectDrawX::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	return ProxyQueryInterface(ProxyInterface, riid, ppvObj, WrapperID, WrapperInterface);
}

ULONG m_IDirectDrawX::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectDrawX::Release()
{
	ULONG ref = ProxyInterface->Release();

	if (ref == 0)
	{
		if (WrapperInterface)
		{
			WrapperInterface->DeleteMe();
		}
		else
		{
			delete this;
		}
	}

	return ref;
}

/***************************/
/*** IDirectDraw methods ***/
/***************************/

HRESULT m_IDirectDrawX::Compact()
{
	return ProxyInterface->Compact();
}

HRESULT m_IDirectDrawX::CreateClipper(DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR * lplpDDClipper, IUnknown FAR * pUnkOuter)
{
	HRESULT hr = ProxyInterface->CreateClipper(dwFlags, lplpDDClipper, pUnkOuter);

	if (SUCCEEDED(hr) && lplpDDClipper)
	{
		*lplpDDClipper = ProxyAddressLookupTable.FindAddress<m_IDirectDrawClipper>(*lplpDDClipper);
	}

	return hr;
}

HRESULT m_IDirectDrawX::CreatePalette(DWORD dwFlags, LPPALETTEENTRY lpDDColorArray, LPDIRECTDRAWPALETTE FAR * lplpDDPalette, IUnknown FAR * pUnkOuter)
{
	HRESULT hr = ProxyInterface->CreatePalette(dwFlags, lpDDColorArray, lplpDDPalette, pUnkOuter);

	if (SUCCEEDED(hr) && lplpDDPalette)
	{
		*lplpDDPalette = ProxyAddressLookupTable.FindAddress<m_IDirectDrawPalette>(*lplpDDPalette);
	}

	return hr;
}

template HRESULT m_IDirectDrawX::CreateSurface<LPDDSURFACEDESC>(LPDDSURFACEDESC, LPDIRECTDRAWSURFACE7 FAR *, IUnknown FAR *);
template HRESULT m_IDirectDrawX::CreateSurface<LPDDSURFACEDESC2>(LPDDSURFACEDESC2, LPDIRECTDRAWSURFACE7 FAR *, IUnknown FAR *);
template <typename T>
HRESULT m_IDirectDrawX::CreateSurface(T lpDDSurfaceDesc, LPDIRECTDRAWSURFACE7 FAR * lplpDDSurface, IUnknown FAR * pUnkOuter)
{
	if (!lplpDDSurface || !lpDDSurfaceDesc)
	{
		return DDERR_INVALIDPARAMS;
	}

	HRESULT hr = ProxyInterface->CreateSurface((LPDDSURFACEDESC2)lpDDSurfaceDesc, (LPDIRECTDRAWSURFACE7*)lplpDDSurface, pUnkOuter);

	if (SUCCEEDED(hr))
	{
		*lplpDDSurface = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(*lplpDDSurface, DirectXVersion);
	}

	return hr;
}

HRESULT m_IDirectDrawX::DuplicateSurface(LPDIRECTDRAWSURFACE7 lpDDSurface, LPDIRECTDRAWSURFACE7 FAR * lplpDupDDSurface)
{
	if (lpDDSurface)
	{
		lpDDSurface = static_cast<m_IDirectDrawSurface7 *>(lpDDSurface)->GetProxyInterface();
	}

	HRESULT hr = ProxyInterface->DuplicateSurface(lpDDSurface, lplpDupDDSurface);

	if (SUCCEEDED(hr) && lplpDupDDSurface && lpDDSurface)
	{
		*lplpDupDDSurface = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(*lplpDupDDSurface, ((m_IDirectDrawSurface7 *)lpDDSurface)->GetDirectXVersion());
	}

	return hr;
}

template HRESULT m_IDirectDrawX::EnumDisplayModes<LPDDSURFACEDESC>(DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK);
template HRESULT m_IDirectDrawX::EnumDisplayModes<LPDDSURFACEDESC2>(DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMMODESCALLBACK2);
template <typename T, typename D>
HRESULT m_IDirectDrawX::EnumDisplayModes(DWORD dwFlags, T lpDDSurfaceDesc, LPVOID lpContext, D lpEnumModesCallback)
{
	return ProxyInterface->EnumDisplayModes(dwFlags, (LPDDSURFACEDESC2)lpDDSurfaceDesc, lpContext, (LPDDENUMMODESCALLBACK2)lpEnumModesCallback);
}

template HRESULT m_IDirectDrawX::EnumSurfaces<LPDDSURFACEDESC, LPDDENUMSURFACESCALLBACK>(DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK);
template HRESULT m_IDirectDrawX::EnumSurfaces<LPDDSURFACEDESC2, LPDDENUMSURFACESCALLBACK2>(DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMSURFACESCALLBACK2);
template HRESULT m_IDirectDrawX::EnumSurfaces<LPDDSURFACEDESC2, LPDDENUMSURFACESCALLBACK7>(DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMSURFACESCALLBACK7);
template <typename T, typename D>
HRESULT m_IDirectDrawX::EnumSurfaces(DWORD dwFlags, T lpDDSD, LPVOID lpContext, D lpEnumSurfacesCallback)
{
	ENUMSURFACE CallbackContext;
	CallbackContext.lpContext = lpContext;
	CallbackContext.lpCallback = (LPDDENUMSURFACESCALLBACK7)lpEnumSurfacesCallback;
	CallbackContext.DirectXVersion = DirectXVersion;
	D lpCallback = m_IDirectDrawEnumSurface::ConvertCallback;

	return ProxyInterface->EnumSurfaces(dwFlags, (LPDDSURFACEDESC2)lpDDSD, &CallbackContext, (LPDDENUMSURFACESCALLBACK7)lpCallback);
}

HRESULT m_IDirectDrawX::FlipToGDISurface()
{
	return ProxyInterface->FlipToGDISurface();
}

HRESULT m_IDirectDrawX::GetCaps(LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps)
{
	return ProxyInterface->GetCaps(lpDDDriverCaps, lpDDHELCaps);
}

template HRESULT m_IDirectDrawX::GetDisplayMode<LPDDSURFACEDESC>(LPDDSURFACEDESC);
template HRESULT m_IDirectDrawX::GetDisplayMode<LPDDSURFACEDESC2>(LPDDSURFACEDESC2);
template <typename T>
HRESULT m_IDirectDrawX::GetDisplayMode(T lpDDSurfaceDesc)
{
	if (!lpDDSurfaceDesc)
	{
		return DDERR_INVALIDPARAMS;
	}

	return ProxyInterface->GetDisplayMode((LPDDSURFACEDESC2)lpDDSurfaceDesc);
}

HRESULT m_IDirectDrawX::GetFourCCCodes(LPDWORD lpNumCodes, LPDWORD lpCodes)
{
	return ProxyInterface->GetFourCCCodes(lpNumCodes, lpCodes);
}

HRESULT m_IDirectDrawX::GetGDISurface(LPDIRECTDRAWSURFACE7 FAR * lplpGDIDDSSurface)
{
	HRESULT hr = ProxyInterface->GetGDISurface(lplpGDIDDSSurface);

	if (SUCCEEDED(hr) && lplpGDIDDSSurface)
	{
		*lplpGDIDDSSurface = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(*lplpGDIDDSSurface, DirectXVersion);
	}

	return hr;
}

HRESULT m_IDirectDrawX::GetMonitorFrequency(LPDWORD lpdwFrequency)
{
	return ProxyInterface->GetMonitorFrequency(lpdwFrequency);
}

HRESULT m_IDirectDrawX::GetScanLine(LPDWORD lpdwScanLine)
{
	return ProxyInterface->GetScanLine(lpdwScanLine);
}

HRESULT m_IDirectDrawX::GetVerticalBlankStatus(LPBOOL lpbIsInVB)
{
	return ProxyInterface->GetVerticalBlankStatus(lpbIsInVB);
}

HRESULT m_IDirectDrawX::Initialize(GUID FAR * lpGUID)
{
	return ProxyInterface->Initialize(lpGUID);
}

HRESULT m_IDirectDrawX::RestoreDisplayMode()
{
	return ProxyInterface->RestoreDisplayMode();
}

// Fixes a bug in ddraw in Windows 8 and 10 where the exclusive flag remains even after the window (hWnd) closes
LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	if (nCode == HCBT_DESTROYWND)
	{
		HWND hWnd = (HWND)wParam;
		IDirectDraw7 *Interface = (IDirectDraw7*)InterlockedExchangePointer((PVOID*)&CurrentDDInterface, nullptr);
		if (Interface && Interface == g_hookmap[hWnd])
		{
			Interface->SetCooperativeLevel(hWnd, DDSCL_NORMAL);
		}
		g_hookmap.erase(hWnd);
	}

	return CallNextHookEx(nullptr, nCode, wParam, lParam);
}

HRESULT m_IDirectDrawX::SetCooperativeLevel(HWND hWnd, DWORD dwFlags)
{
	// Release previouse Exclusive flag
	// Hook window message to get notified when the window is about to exit to remove the exclusive flag
	if ((dwFlags & DDSCL_EXCLUSIVE) && hWnd && hWnd != chWnd)
	{
		if (IsWindow(chWnd))
		{
			ProxyInterface->SetCooperativeLevel(chWnd, DDSCL_NORMAL);
		}
		else
		{
			if (g_hook)
			{
				UnhookWindowsHookEx(g_hook);
				g_hook = nullptr;
			}

			g_hookmap[hWnd] = ProxyInterface;
			g_hook = SetWindowsHookEx(WH_CBT, CBTProc, nullptr, GetWindowThreadProcessId(hWnd, nullptr));
		}

		if (chWnd)
		{
			g_hookmap.erase(chWnd);
		}

		chWnd = hWnd;
	}

	return ProxyInterface->SetCooperativeLevel(hWnd, dwFlags);
}

HRESULT m_IDirectDrawX::SetDisplayMode(DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags)
{
	if (ProxyDirectXVersion == 1)
	{
		return ((IDirectDraw*)ProxyInterface)->SetDisplayMode(dwWidth, dwHeight, dwBPP);
	}

	return ProxyInterface->SetDisplayMode(dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags);
}

HRESULT m_IDirectDrawX::WaitForVerticalBlank(DWORD dwFlags, HANDLE hEvent)
{
	return ProxyInterface->WaitForVerticalBlank(dwFlags, hEvent);
}

/*********************************/
/*** Added in the v2 interface ***/
/*********************************/

template HRESULT m_IDirectDrawX::GetAvailableVidMem<LPDDSCAPS>(LPDDSCAPS, LPDWORD, LPDWORD);
template HRESULT m_IDirectDrawX::GetAvailableVidMem<LPDDSCAPS2>(LPDDSCAPS2, LPDWORD, LPDWORD);
template <typename T>
HRESULT m_IDirectDrawX::GetAvailableVidMem(T lpDDSCaps, LPDWORD lpdwTotal, LPDWORD lpdwFree)
{
	return ProxyInterface->GetAvailableVidMem((LPDDSCAPS2)lpDDSCaps, lpdwTotal, lpdwFree);
}

/*********************************/
/*** Added in the V4 Interface ***/
/*********************************/

HRESULT m_IDirectDrawX::GetSurfaceFromDC(HDC hdc, LPDIRECTDRAWSURFACE7 * lpDDS)
{
	HRESULT hr = ProxyInterface->GetSurfaceFromDC(hdc, lpDDS);

	if (SUCCEEDED(hr) && lpDDS)
	{
		*lpDDS = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(*lpDDS, DirectXVersion);
	}

	return hr;
}

HRESULT m_IDirectDrawX::RestoreAllSurfaces()
{
	return ProxyInterface->RestoreAllSurfaces();
}

HRESULT m_IDirectDrawX::TestCooperativeLevel()
{
	return ProxyInterface->TestCooperativeLevel();
}

template HRESULT m_IDirectDrawX::GetDeviceIdentifier<LPDDDEVICEIDENTIFIER>(LPDDDEVICEIDENTIFIER, DWORD);
template HRESULT m_IDirectDrawX::GetDeviceIdentifier<LPDDDEVICEIDENTIFIER2>(LPDDDEVICEIDENTIFIER2, DWORD);
template <typename T>
HRESULT m_IDirectDrawX::GetDeviceIdentifier(T lpdddi, DWORD dwFlags)
{
	if (!lpdddi)
	{
		return DDERR_INVALIDPARAMS;
	}

	return ProxyInterface->GetDeviceIdentifier((LPDDDEVICEIDENTIFIER2)lpdddi, dwFlags);
}

HRESULT m_IDirectDrawX::StartModeTest(LPSIZE lpModesToTest, DWORD dwNumEntries, DWORD dwFlags)
{
	return ProxyInterface->StartModeTest(lpModesToTest, dwNumEntries, dwFlags);
}

HRESULT m_IDirectDrawX::EvaluateMode(DWORD dwFlags, DWORD * pSecondsUntilTimeout)
{
	return ProxyInterface->EvaluateMode(dwFlags, pSecondsUntilTimeout);
}
