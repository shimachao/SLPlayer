#pragma once
#include <comdef.h>
#include <Gdiplus.h>
#include "ButtonModel.h"

class ButtonView
{
public:
	ButtonView(int left, int top, int width, int height);
	~ButtonView();

	// 设置model
	void set_model(ButtonModel *model);

	// 绘制
	void draw(Gdiplus::Graphics &g);
	// 设置图片
	void set_img(Gdiplus::Image *img);

private:
	// 正常状态绘制
	void normal_draw(Gdiplus::Graphics &g);
	// 高亮绘制
	void highlight_draw(Gdiplus::Graphics &g);
	// 按下状态时绘制
	void press_down_draw(Gdiplus::Graphics &g);

private:
	int m_left; // 绘制范围左侧
	int m_top; // 顶端
	int m_width; // 宽
	int m_height; // 高
	Gdiplus::Image *m_img; // 背景图片

	ButtonModel *m_model = nullptr; // model引用
};

