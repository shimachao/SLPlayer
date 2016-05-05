#pragma once
#include <comdef.h>
#include <Gdiplus.h>

class AbstractView
{
public:
	AbstractView();
	virtual ~AbstractView();

	// »æÖÆ
	virtual void draw(Gdiplus::Graphics &g) = 0;
};

