#pragma once
#include "ProgressModel.h"
#include <comdef.h>
#include <Gdiplus.h>

class ProgressView
{
public:
	ProgressView(int left, int top, int width, int height);
	~ProgressView();

	// 设置model
	void set_model(ProgressModel *model);
	// 绘制
	void draw(Gdiplus::Graphics &g);

private:
	// 正常状态的绘制方法
	void normal_draw(Gdiplus::Graphics &g);
	// 高亮时的绘制方法
	void highlight_draw(Gdiplus::Graphics &g);

private:
	// 进度条坐标
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	ProgressModel *m_model = nullptr;
};

