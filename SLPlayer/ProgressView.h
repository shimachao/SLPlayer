#pragma once
#include "ProgressModel.h"
#include <comdef.h>
#include <Gdiplus.h>
#include "AbstractView.h"

class ProgressView : public AbstractView
{
public:
	ProgressView(int left, int top, int width, int height);
	~ProgressView();

	// 设置model
	void set_model(ProgressModel *model);
	// 设置范围
	void set_pos(int left, int top, int width, int height) override;
	// 绘制
	void draw(Gdiplus::Graphics &g) override;

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

