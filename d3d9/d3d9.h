#pragma once

#include <d3d9.h>

class __declspec(uuid("81BDCBCA-64D4-426d-AE8D-AD0147F4275C")) m_IDirect3D9;
class __declspec(uuid("D0223B96-BF7A-43fd-92BD-A43B0D82B9EB")) m_IDirect3DDevice9;
class __declspec(uuid("B07C4FE5-310D-4ba8-A23C-4F0F206F218B")) m_IDirect3DStateBlock9;
class __declspec(uuid("05EEC05D-8F7D-4362-B999-D1BAF357C704")) m_IDirect3DResource9;
class __declspec(uuid("DD13C59C-36FA-4098-A8FB-C7ED39DC8546")) m_IDirect3DVertexDeclaration9;
class __declspec(uuid("EFC5557E-6265-4613-8A94-43857889EB36")) m_IDirect3DVertexShader9;
class __declspec(uuid("6D3BDBDC-5B02-4415-B852-CE5E8BCCB289")) m_IDirect3DPixelShader9;
class __declspec(uuid("580CA87E-1D3C-4d54-991D-B7D3E3C298CE")) m_IDirect3DBaseTexture9;
class __declspec(uuid("85C31227-3DE5-4f00-9B3A-F11AC38C18B5")) m_IDirect3DTexture9;
class __declspec(uuid("2518526C-E789-4111-A7B9-47EF328D13E6")) m_IDirect3DVolumeTexture9;
class __declspec(uuid("FFF32F81-D953-473a-9223-93D652ABA93F")) m_IDirect3DCubeTexture9;
class __declspec(uuid("B64BB1B5-FD70-4df6-BF91-19D0A12455E3")) m_IDirect3DVertexBuffer9;
class __declspec(uuid("7C9DD65E-D3F7-4529-ACEE-785830ACDE35")) m_IDirect3DIndexBuffer9;
class __declspec(uuid("0CFBAF3A-9FF6-429a-99B3-A2796AF8B89B")) m_IDirect3DSurface9;
class __declspec(uuid("24F416E6-1F67-4aa7-B88E-D33F6F3128A1")) m_IDirect3DVolume9;
class __declspec(uuid("794950F2-ADFC-458a-905E-10A10B0B503B")) m_IDirect3DSwapChain9;
class __declspec(uuid("d9771460-a695-4f26-bbd3-27b840b541cc")) m_IDirect3DQuery9;
class __declspec(uuid("02177241-69FC-400C-8FF1-93A44DF6861D")) m_IDirect3D9Ex;
class __declspec(uuid("B18B10CE-2649-405a-870F-95F777D4313A")) m_IDirect3DDevice9Ex;
class __declspec(uuid("91886CAF-1C3D-4d2e-A0AB-3E4C7D8D3303")) m_IDirect3DSwapChain9Ex;
class __declspec(uuid("187AEB13-AAF5-4C59-876D-E059088C0DF8")) m_IDirect3D9ExOverlayExtension;
class __declspec(uuid("26DC4561-A1EE-4ae7-96DA-118A36C0EC95")) m_IDirect3DDevice9Video;
class __declspec(uuid("FF24BEEE-DA21-4beb-98B5-D2F899F98AF9")) m_IDirect3DAuthenticatedChannel9;
class __declspec(uuid("FA0AB799-7A9C-48CA-8C5B-237E71A54434")) m_IDirect3DCryptoSession9;

typedef HRESULT(WINAPI *Direct3DShaderValidatorCreate9Proc)();
typedef HRESULT(WINAPI *PSGPErrorProc)();
typedef HRESULT(WINAPI *PSGPSampleTextureProc)();
typedef int(WINAPI *D3DPERF_BeginEventProc)(D3DCOLOR, LPCWSTR);
typedef int(WINAPI *D3DPERF_EndEventProc)();
typedef DWORD(WINAPI *D3DPERF_GetStatusProc)();
typedef BOOL(WINAPI *D3DPERF_QueryRepeatFrameProc)();
typedef void(WINAPI *D3DPERF_SetMarkerProc)(D3DCOLOR, LPCWSTR);
typedef void(WINAPI *D3DPERF_SetOptionsProc)(DWORD);
typedef void(WINAPI *D3DPERF_SetRegionProc)(D3DCOLOR, LPCWSTR);
typedef HRESULT(WINAPI *DebugSetLevelProc)(DWORD);
typedef void(WINAPI *DebugSetMuteProc)();
typedef void(WINAPI *Direct3D9EnableMaximizedWindowedModeShimProc)();
typedef IDirect3D9 *(WINAPI *Direct3DCreate9Proc)(UINT);
typedef HRESULT(WINAPI *Direct3DCreate9ExProc)(UINT, IDirect3D9Ex **);

#include "Logging.h"
#include "Wrappers.h"
#include "IDirect3D9.h"
#include "IDirect3D9Ex.h"
#include "IDirect3DDevice9.h"
#include "IDirect3DDevice9Ex.h"
#include "IDirect3DCubeTexture9.h"
#include "IDirect3DIndexBuffer9.h"
#include "IDirect3DPixelShader9.h"
#include "IDirect3DQuery9.h"
#include "IDirect3DStateBlock9.h"
#include "IDirect3DSurface9.h"
#include "IDirect3DSwapChain9.h"
#include "IDirect3DTexture9.h"
#include "IDirect3DVertexBuffer9.h"
#include "IDirect3DVertexDeclaration9.h"
#include "IDirect3DVertexShader9.h"
#include "IDirect3DVolume9.h"
#include "IDirect3DVolumeTexture9.h"
