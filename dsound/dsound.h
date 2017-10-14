#pragma once

#include <dsound.h>
#include "..\Common\Wrapper.h"
#include "..\Common\Logging.h"

typedef HRESULT(WINAPI *DirectSoundCreateProc)(LPCGUID, LPDIRECTSOUND*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectSoundEnumerateAProc)(LPDSENUMCALLBACKA, LPVOID);
typedef HRESULT(WINAPI *DirectSoundEnumerateWProc)(LPDSENUMCALLBACKW, LPVOID);
typedef HRESULT(WINAPI *DllCanUnloadNowProc)();
typedef	HRESULT(WINAPI *DllGetClassObjectProc)(REFCLSID, REFIID, LPVOID *);
typedef HRESULT(WINAPI *DirectSoundCaptureCreateProc)(LPCGUID, LPDIRECTSOUNDCAPTURE*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectSoundCaptureEnumerateAProc)(LPDSENUMCALLBACKA, LPVOID);
typedef HRESULT(WINAPI *DirectSoundCaptureEnumerateWProc)(LPDSENUMCALLBACKW, LPVOID);
typedef HRESULT(WINAPI *GetDeviceIDProc)(LPCGUID, LPGUID);
typedef HRESULT(WINAPI *DirectSoundFullDuplexCreateProc)(LPCGUID, LPCGUID, LPCDSCBUFFERDESC, LPCDSBUFFERDESC, HWND, DWORD, LPDIRECTSOUNDFULLDUPLEX*, LPDIRECTSOUNDCAPTUREBUFFER8 *, LPDIRECTSOUNDBUFFER8 *, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectSoundCreate8Proc)(LPCGUID, LPDIRECTSOUND8*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectSoundCaptureCreate8Proc)(LPCGUID, LPDIRECTSOUNDCAPTURE8*, LPUNKNOWN);

void genericQueryInterface(REFIID riid, LPVOID * ppvObj);
extern AddressLookupTable<void> ProxyAddressLookupTable;

#include "IClassFactory.h"
#include "IDirectSound8.h"
#include "IDirectSound3DBuffer8.h"
#include "IDirectSound3DListener8.h"
#include "IDirectSoundBuffer8.h"
#include "IDirectSoundCapture8.h"
#include "IDirectSoundCaptureBuffer8.h"
#include "IDirectSoundCaptureFXAec8.h"
#include "IDirectSoundCaptureFXNoiseSuppress8.h"
#include "IDirectSoundFullDuplex8.h"
#include "IDirectSoundFXChorus8.h"
#include "IDirectSoundFXCompressor8.h"
#include "IDirectSoundFXDistortion8.h"
#include "IDirectSoundFXEcho8.h"
#include "IDirectSoundFXFlanger8.h"
#include "IDirectSoundFXGargle8.h"
#include "IDirectSoundFXI3DL2Reverb8.h"
#include "IDirectSoundFXParamEq8.h"
#include "IDirectSoundFXWavesReverb8.h"
#include "IDirectSoundNotify8.h"
#include "IKsPropertySet.h"
