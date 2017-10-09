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

#include "d3dim700.h"

std::mutex mCallback;
std::mutex mCallback7;

LPDDENUMSURFACESCALLBACK m_IDirectDrawEnumSurface::lpCallback;
LPDDENUMSURFACESCALLBACK7 m_IDirectDrawEnumSurface7::lpCallback;

void m_IDirectDrawEnumSurface::SetCallback(LPDDENUMSURFACESCALLBACK a)
{
	mCallback.lock();
	lpCallback = a;
}

void m_IDirectDrawEnumSurface::ReleaseCallback()
{
	lpCallback = nullptr;
	mCallback.unlock();
}

HRESULT m_IDirectDrawEnumSurface::EnumSurfaceCallback(LPDIRECTDRAWSURFACE a, LPDDSURFACEDESC b, LPVOID c)
{
	if (a)
	{
		a = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface>(a);
	}

	return lpCallback(a, b, c);
}

void m_IDirectDrawEnumSurface7::SetCallback(LPDDENUMSURFACESCALLBACK7 a)
{
	mCallback7.lock();
	lpCallback = a;
}

void m_IDirectDrawEnumSurface7::ReleaseCallback()
{
	lpCallback = nullptr;
	mCallback7.unlock();
}

HRESULT m_IDirectDrawEnumSurface7::EnumSurface7Callback(LPDIRECTDRAWSURFACE7 a, LPDDSURFACEDESC2 b, LPVOID c)
{
	if (a)
	{
		a = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(a);
	}

	return lpCallback(a, b, c);
}
