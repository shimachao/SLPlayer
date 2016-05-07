#pragma once
#include <comdef.h>
#include <Gdiplus.h>

class AbstractView
{
public:
	AbstractView();
	virtual ~AbstractView();

	// …Ë÷√ªÊ÷∆∑∂Œß
	virtual void set_pos(int left, int top, int width, int height) = 0;
	// ªÊ÷∆
	virtual void draw(Gdiplus::Graphics &g) = 0;
};

