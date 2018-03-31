#pragma once

#define INITGUID

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include "..\Common\Wrapper.h"
#include "..\Common\Logging.h"

typedef HRESULT(WINAPI *DirectInput8CreateProc)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);
typedef HRESULT(WINAPI *DllCanUnloadNowProc)();
typedef	HRESULT(WINAPI *DllGetClassObjectProc)(REFCLSID, REFIID, LPVOID *);
typedef HRESULT(WINAPI *DllRegisterServerProc)();
typedef HRESULT(WINAPI *DllUnregisterServerProc)();

void genericQueryInterface(REFIID CalledID, LPVOID * ppvObj);
extern AddressLookupTable<void> ProxyAddressLookupTable;

#include "IDirectInput8A.h"
#include "IDirectInput8W.h"
#include "IDirectInputDevice8A.h"
#include "IDirectInputDevice8W.h"
#include "IDirectInputEffect.h"
#include "IDirectInputEnumDevice.h"
#include "IDirectInputEnumEffect.h"
