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


// 设置范围
void ProgressView::set_pos(int left, int top, int width, int height)
{
	m_left = left;
	m_top = top;
	m_width = width;
	m_height = height;
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

		case ProgressModel::State::HIGHLIGHT:
			highlight_draw(g);
			break;
		}
	}
}


// 正常状态的绘制方法
void ProgressView::normal_draw(Gdiplus::Graphics &g)
{
	// todo
}


// 高亮时的绘制方法
void ProgressView::highlight_draw(Gdiplus::Graphics &g)
{
	// todo
}
