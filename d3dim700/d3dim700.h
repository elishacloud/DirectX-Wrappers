#pragma once

#define INITGUID

#include <d3d.h>
#include "..\Common\Logging.h"
#include "..\Common\Wrapper.h"

typedef HRESULT(WINAPI *Direct3DCreateDeviceProc)(GUID FAR *, LPDIRECT3D, LPDIRECTDRAWSURFACE, LPDIRECT3D *, LPUNKNOWN);
typedef HRESULT(WINAPI *Direct3DCreateProc)(UINT, LPDIRECT3D *, LPUNKNOWN);

void genericQueryInterface(REFIID riid, LPVOID * ppvObj);
extern AddressLookupTable<void> ProxyAddressLookupTable;

#include "IDirect3D7.h"
#include "IDirect3DDevice7.h"
#include "IDirect3DVertexBuffer7.h"
#include "IDirectDraw.h"
#include "IDirectDraw7.h"
#include "IDirectDrawClipper.h"
#include "IDirectDrawEnumSurface.h"
#include "IDirectDrawPalette.h"
#include "IDirectDrawSurface.h"
#include "IDirectDrawSurface7.h"
