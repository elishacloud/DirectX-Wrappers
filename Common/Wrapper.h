#pragma once

#include <unordered_map>

template <typename D>
class AddressLookupTable
{
public:
	explicit AddressLookupTable(D *pDevice) : pDevice(pDevice) {}
	~AddressLookupTable()
	{
		while (g_map.size() != 0)
		{
			auto it = g_map.begin();

			it->second->DeleteMe();

			it = g_map.erase(it);
		}
	}

	template <typename T>
	T *FindAddress(void *Proxy)
	{
		if (Proxy == nullptr)
		{
			return nullptr;
		}

		T *Wrapper = static_cast<T *>(g_map[Proxy]);

		if (Wrapper == nullptr)
		{
			Wrapper = new T(static_cast<T *>(Proxy), pDevice);
		}

		return Wrapper;
	}

	template <typename T>
	void SaveAddress(T *Wrapper, void *Proxy)
	{
		if (Wrapper != nullptr && Proxy != nullptr)
		{
			g_map[Proxy] = Wrapper;
		}
	}

	template <typename T>
	void DeleteAddress(T *Wrapper)
	{
		if (Wrapper != nullptr)
		{
			for (auto it = g_map.begin(); it != g_map.end(); ++it)
			{
				if (it->second == Wrapper)
				{
					it->second->DeleteMe();

					it = g_map.erase(it);
					
					return;
				}
			}
		}
	}

private:
	D *const pDevice;
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
