#pragma once

#include <fstream>
#include <d3d9.h>
#include "IDirect3D9.h"
#include "IDirect3DDevice9.h"

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

typedef IDirect3D9 *(WINAPI *Direct3DCreate9Proc)(UINT);
extern Direct3DCreate9Proc m_pDirect3DCreate9;
