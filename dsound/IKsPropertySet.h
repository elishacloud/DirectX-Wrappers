#pragma once

class m_IKsPropertySet : public IKsPropertySet, public AddressLookupTableObject
{
private:
	IKsPropertySet *ProxyInterface;

public:
	m_IKsPropertySet(IKsPropertySet *pSound8) : ProxyInterface(pSound8)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IKsPropertySet()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	IKsPropertySet *GetProxyInterface() { return ProxyInterface; }

	// IUnknown methods
	STDMETHOD(QueryInterface)(THIS_ _In_ REFIID, _Outptr_ LPVOID*);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	// IKsPropertySet methods
	STDMETHOD(Get)(THIS_ _In_ REFGUID rguidPropSet, ULONG ulId, _In_reads_bytes_opt_(ulInstanceLength) LPVOID pInstanceData, ULONG ulInstanceLength,
		_Out_writes_bytes_(ulDataLength) LPVOID pPropertyData, ULONG ulDataLength, _Out_opt_ PULONG pulBytesReturned);
	STDMETHOD(Set)(THIS_ _In_ REFGUID rguidPropSet, ULONG ulId, _In_reads_bytes_opt_(ulInstanceLength)  LPVOID pInstanceData, ULONG ulInstanceLength,
		_In_reads_bytes_(ulDataLength) LPVOID pPropertyData, ULONG ulDataLength);
	STDMETHOD(QuerySupport)(THIS_ _In_ REFGUID rguidPropSet, ULONG ulId, _Out_ PULONG pulTypeSupport);
};
