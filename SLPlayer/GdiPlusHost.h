#pragma once
#include <Windows.h>

class GdiPlusHost
{
public:
	GdiPlusHost();
	~GdiPlusHost();

private:
	ULONG_PTR m_gidplusToken;
};

