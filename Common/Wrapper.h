#pragma once

#include <unordered_map>

template <typename D>
class AddressLookupTable
{
public:
	explicit AddressLookupTable(D *pDevice) : m_pDevice(pDevice) {}
	~AddressLookupTable()
	{
		while (g_map.size() != 0)
		{
			auto it = g_map.begin();

			if (it->second != nullptr)
			{
				it->second->DeleteMe();
			}

			it = g_map.erase(it);
		}
	}

	template <typename T>
	T *FindAddress(void *Wrapper)
	{
		if (Wrapper == nullptr)
		{
			return nullptr;
		}

		T *Proxy = static_cast<T *>(g_map[Wrapper]);

		if (Proxy == nullptr)
		{
			Proxy = new T(static_cast<T *>(Wrapper), m_pDevice);
		}

		return Proxy;
	}

	template <typename T>
	void SaveAddress(T *Proxy, void *Wrapper)
	{
		if (Proxy != nullptr && Wrapper != nullptr)
		{
			g_map[Wrapper] = Proxy;
		}
	}

	void DeleteAddress(void* Wrapper)
	{
		if (g_map[Wrapper] != nullptr)
		{
			g_map[Wrapper]->DeleteMe();
		}

		g_map.erase(Wrapper);
	}

private:
	D *const m_pDevice;
	std::unordered_map<void*, class AddressLookupTableObject*> g_map;
};

class AddressLookupTableObject
{
public:
	virtual ~AddressLookupTableObject() { }

	void DeleteMe()
	{
		delete this;
	}
};
