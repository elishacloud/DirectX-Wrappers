#pragma once

#include <fstream>

#define GetOrCreateWrapperT(T, original) GetOrCreateWrapper<m_ ## T,T>((original))

template<class Wrap, class Orig>
Wrap* GetOrCreateWrapper(void* original)
{
	if (!original)
	{
		return nullptr;
	}

	void* wrapper = GetWrapper(original);

	if (!wrapper)
	{
		wrapper = new Wrap((Orig*)original);
		AddWrapper(wrapper, original);
	}

	return (Wrap*)wrapper;
}

// Very simple logging for the purpose of debugging only.
class Log
{
public:
	Log() {}
	~Log()
	{
		LOG << std::endl;
	}

	template <typename T>
	Log& operator<<(const T& t)
	{
		LOG << t;
		return *this;
	}

private:
	static std::ofstream LOG;
};

void logf(char * format, ...);

void* GetWrapper(void* original);
void AddWrapper(void* wrapper, void* original);
void RemoveWrapper(void* original);
