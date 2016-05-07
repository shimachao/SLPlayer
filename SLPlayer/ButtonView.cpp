#include "ButtonView.h"



ButtonView::ButtonView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height), m_normal_img(nullptr)
{
}


ButtonView::~ButtonView()
{
}


// 设置model
void ButtonView::set_model(ButtonModel *model)
{
	m_model = model;
}


// 设置范围
void ButtonView::set_pos(int left, int top, int width, int height)
{
	m_left = left;
	m_top = top;
	m_width = width;
	m_height = height;
}


// 绘制
void ButtonView::draw(Gdiplus::Graphics &g)
{
	auto state = m_model->get_state();
	switch (state)
	{
	case ButtonModel::State::NORMAL:
		normal_draw(g);
		break;
	case ButtonModel::State::HIGHLIGHT:
		highlight_draw(g);
		break;
	case ButtonModel::State::DOWN:
		down_draw(g);
		break;
	}
}


// 设置正常状态时的背景图片
void ButtonView::set_normal_img(Gdiplus::Image *img)
{
	m_normal_img = img;
}


// 设置高亮时的背景图片
void ButtonView::set_highlight_img(Gdiplus::Image *img)
{
	m_highlight_img = img;
}


// 设置按下时的背景图片
void ButtonView::set_down_img(Gdiplus::Image *img)
{
	m_down_img = img;
}


// 正常状态绘制
void ButtonView::normal_draw(Gdiplus::Graphics &g)
{
	if (m_normal_img)
	{
		g.DrawImage(m_normal_img, m_left, m_top, m_width, m_height);
	}
}


// 高亮绘制
void ButtonView::highlight_draw(Gdiplus::Graphics &g)
{
	if (m_highlight_img)
	{
		g.DrawImage(m_highlight_img, m_left, m_top, m_width, m_height);
	}
}


// 按下状态时绘制
void ButtonView::down_draw(Gdiplus::Graphics &g)
{
	if (m_down_img)
	{
		g.DrawImage(m_down_img, m_left, m_top, m_width, m_height);
	}
}
