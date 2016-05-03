#include "ProgressView.h"



ProgressView::ProgressView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
}


ProgressView::~ProgressView()
{
}


// 设置model
void ProgressView::set_model(ProgressModel *model)
{
	m_model = model;
}


// 绘制
void ProgressView::draw(Gdiplus::Graphics &g)
{
	if (m_model)
	{
		auto state = m_model->get_state();
		switch (state)
		{
		case ProgressModel::State::NORMAL:
			normal_draw(g);
			break;

		case ProgressModel::State::SLIDE_HIGHLIGHT:
			slide_highlight_draw(g);
			break;

		case ProgressModel::State::ALL_HIGHLIGHT:
			all_highlight_draw(g);
			break;
		}
	}
}


// 正常状态的绘制方法
void ProgressView::normal_draw(Gdiplus::Graphics &g)
{
	// todo
}


// 滑道高亮时的绘制方法
void ProgressView::slide_highlight_draw(Gdiplus::Graphics &g)
{
	// todo
}


// 滑道和滑块都高亮时的绘制方法
void ProgressView::all_highlight_draw(Gdiplus::Graphics &g)
{
	// todo
}
