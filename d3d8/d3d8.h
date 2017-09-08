#pragma once

#include <d3d8.h>

class __declspec(uuid("1DD9E8DA-1C77-4D40-B0CF-98FEFDFF9512")) m_IDirect3D8;
class __declspec(uuid("7385E5DF-8FE8-41D5-86B6-D7B48547B6CF")) m_IDirect3DDevice8;
class __declspec(uuid("928C088B-76B9-4C6B-A536-A590853876CD")) m_IDirect3DSwapChain8;
class __declspec(uuid("1B36BB7B-09B7-410A-B445-7D1430D7B33F")) m_IDirect3DResource8;
class __declspec(uuid("B4211CFA-51B9-4A9F-AB78-DB99B2BB678E")) m_IDirect3DBaseTexture8;
class __declspec(uuid("E4CDD575-2866-4F01-B12E-7EECE1EC9358")) m_IDirect3DTexture8;
class __declspec(uuid("3EE5B968-2ACA-4C34-8BB5-7E0C3D19B750")) m_IDirect3DCubeTexture8;
class __declspec(uuid("4B8AAAFA-140F-42BA-9131-597EAFAA2EAD")) m_IDirect3DVolumeTexture8;
class __declspec(uuid("B96EEBCA-B326-4EA5-882F-2FF5BAE021DD")) m_IDirect3DSurface8;
class __declspec(uuid("BD7349F5-14F1-42E4-9C79-972380DB40C0")) m_IDirect3DVolume8;
class __declspec(uuid("8AEEEAC7-05F9-44D4-B591-000B0DF1CB95")) m_IDirect3DVertexBuffer8;
class __declspec(uuid("0E689C9A-053D-44A0-9D92-DB0E3D750F86")) m_IDirect3DIndexBuffer8;

typedef void(WINAPI *Direct3D8EnableMaximizedWindowedModeShimProc)();
typedef HRESULT(WINAPI *ValidatePixelShaderProc)(DWORD*, DWORD*, BOOL, DWORD*);
typedef HRESULT(WINAPI *ValidateVertexShaderProc)(DWORD*, DWORD*, DWORD*, BOOL, DWORD*);
typedef void(WINAPI *DebugSetMuteProc)();
typedef IDirect3D8 *(WINAPI *Direct3DCreate8Proc)(UINT);

#include "Logging.h"
#include "Wrappers.h"
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
