#pragma once
#include <comdef.h>
#include <Gdiplus.h>

class AbstractView
{
public:
	AbstractView();
	virtual ~AbstractView();

	// ���û��Ʒ�Χ
	virtual void set_pos(int left, int top, int width, int height) = 0;
	// ����
	virtual void draw(Gdiplus::Graphics &g) = 0;
};

