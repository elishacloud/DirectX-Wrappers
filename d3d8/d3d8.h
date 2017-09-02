#pragma once

#include <fstream>
#include <d3d8.h>
#include "IDirect3D8.h"
#include "IDirect3DDevice8.h"

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

typedef IDirect3D8 *(WINAPI *Direct3DCreate8Proc)(UINT);
extern Direct3DCreate8Proc m_pDirect3DCreate8;
