#include "dsound.h"

void genericQueryInterface(REFIID riid, LPVOID * ppvObj)
{
#define QUERYINTERFACE(x) \
	if (riid == IID_ ## x) \
		{ \
			*ppvObj = ProxyAddressLookupTable.FindAddress<m_ ## x>(*ppvObj); \
		}

#define QUERYINTERFACE8(x) \
	if (riid == IID_ ## x || riid == IID_ ## x ## 8) \
		{ \
			*ppvObj = ProxyAddressLookupTable.FindAddress<m_ ## x ## 8>(*ppvObj); \
		}

	QUERYINTERFACE(IClassFactory);
	QUERYINTERFACE8(IDirectSound3DBuffer);
	QUERYINTERFACE8(IDirectSound3DListener);
	QUERYINTERFACE8(IDirectSound);
	QUERYINTERFACE8(IDirectSoundBuffer);
	QUERYINTERFACE8(IDirectSoundCapture);
	QUERYINTERFACE8(IDirectSoundCaptureBuffer);
	QUERYINTERFACE8(IDirectSoundCaptureFXAec);
	QUERYINTERFACE8(IDirectSoundCaptureFXNoiseSuppress);
	QUERYINTERFACE8(IDirectSoundFullDuplex);
	QUERYINTERFACE8(IDirectSoundFXChorus);
	QUERYINTERFACE8(IDirectSoundFXCompressor);
	QUERYINTERFACE8(IDirectSoundFXDistortion);
	QUERYINTERFACE8(IDirectSoundFXEcho);
	QUERYINTERFACE8(IDirectSoundFXFlanger);
	QUERYINTERFACE8(IDirectSoundFXGargle);
	QUERYINTERFACE8(IDirectSoundFXI3DL2Reverb);
	QUERYINTERFACE8(IDirectSoundFXParamEq);
	QUERYINTERFACE8(IDirectSoundFXWavesReverb);
	QUERYINTERFACE8(IDirectSoundNotify);
	QUERYINTERFACE(IKsPropertySet);
}
