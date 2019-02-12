#pragma once

class m_IDirectSoundCapture8 : public IDirectSoundCapture8, public AddressLookupTableObject
{
private:
	LPDIRECTSOUNDCAPTURE8 ProxyInterface;

public:
	m_IDirectSoundCapture8(LPDIRECTSOUNDCAPTURE8 pSound8) : ProxyInterface(pSound8)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectSoundCapture8()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	LPDIRECTSOUNDCAPTURE8 GetProxyInterface() { return ProxyInterface; }

	// IUnknown methods
	STDMETHOD(QueryInterface)(THIS_ _In_ REFIID, _Outptr_ LPVOID*);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	// IDirectSoundCapture methods
	STDMETHOD(CreateCaptureBuffer)(THIS_ _In_ LPCDSCBUFFERDESC pcDSCBufferDesc, _Outptr_ LPDIRECTSOUNDCAPTUREBUFFER *ppDSCBuffer, _Pre_null_ LPUNKNOWN pUnkOuter);
	STDMETHOD(GetCaps)(THIS_ _Out_ LPDSCCAPS pDSCCaps);
	STDMETHOD(Initialize)(THIS_ _In_opt_ LPCGUID pcGuidDevice);
};
