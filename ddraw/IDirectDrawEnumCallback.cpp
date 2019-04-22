/**
* Copyright (C) 2019 Elisha Riedlinger
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

HRESULT CALLBACK m_IDirectDrawEnumSurface::ConvertCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext)
{
	ENUMSURFACE *lpCallbackContext = (ENUMSURFACE*)lpContext;

	if (lpDDSurface)
	{
		lpDDSurface = (LPDIRECTDRAWSURFACE)ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(lpDDSurface, lpCallbackContext->DirectXVersion);
	}

	return lpCallbackContext->lpCallback(lpDDSurface, lpDDSurfaceDesc, lpCallbackContext->lpContext);
}

HRESULT CALLBACK m_IDirectDrawEnumSurface::ConvertCallback2(LPDIRECTDRAWSURFACE7 lpDDSurface, LPDDSURFACEDESC2 lpDDSurfaceDesc2, LPVOID lpContext)
{
	ENUMSURFACE2 *lpCallbackContext = (ENUMSURFACE2*)lpContext;

	if (lpDDSurface)
	{
		lpDDSurface = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(lpDDSurface, lpCallbackContext->DirectXVersion);
	}

	return lpCallbackContext->lpCallback(lpDDSurface, lpDDSurfaceDesc2, lpCallbackContext->lpContext);
}
