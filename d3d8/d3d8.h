#pragma once

#define INITGUID

#include <d3d8.h>

class m_IDirect3D8;
class m_IDirect3DDevice8;
class m_IDirect3DCubeTexture8;
class m_IDirect3DIndexBuffer8;
class m_IDirect3DSurface8;
class m_IDirect3DSwapChain8;
class m_IDirect3DTexture8;
class m_IDirect3DVertexBuffer8;
class m_IDirect3DVolume8;
class m_IDirect3DVolumeTexture8;

#include "AddressLookupTable.h"
#include "..\Common\Logging.h"

typedef void(WINAPI *Direct3D8EnableMaximizedWindowedModeShimProc)();
typedef HRESULT(WINAPI *ValidatePixelShaderProc)(DWORD*, DWORD*, BOOL, DWORD*);
typedef HRESULT(WINAPI *ValidateVertexShaderProc)(DWORD*, DWORD*, DWORD*, BOOL, DWORD*);
typedef void(WINAPI *DebugSetMuteProc)();
typedef IDirect3D8 *(WINAPI *Direct3DCreate8Proc)(UINT);

void genericQueryInterface(REFIID riid, LPVOID *ppvObj, m_IDirect3DDevice8* m_pDevice);

#include "IDirect3D8.h"
#include "IDirect3DDevice8.h"
#include "IDirect3DCubeTexture8.h"
#include "IDirect3DIndexBuffer8.h"
#include "IDirect3DSurface8.h"
#include "IDirect3DSwapChain8.h"
#include "IDirect3DTexture8.h"
#include "IDirect3DVertexBuffer8.h"
#include "IDirect3DVolume8.h"
#include "IDirect3DVolumeTexture8.h"
