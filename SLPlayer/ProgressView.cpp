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


// 正常状态的绘制方法
void ProgressView::normal_draw(Gdiplus::Graphics &g)
{
	// 绘制边框
	Gdiplus::Pen whitePen(Gdiplus::Color::White);
	g.DrawRectangle(&whitePen, m_left, m_top, m_width, m_height);
	// 绘制进度
	int real_start, real_end, real_pos; // 实际数据的范围和进度
	m_model->get_range_pos(real_start, real_end, real_pos);

	int pos = ((real_pos - real_start) / (real_end - real_start))*m_width; // 界面上绘制进度
	Gdiplus::SolidBrush brush(Gdiplus::Color(100, 255, 255, 255));
	g.FillRectangle(&brush, m_left, m_top, pos, m_height);

}


// 高亮时的绘制方法
void ProgressView::highlight_draw(Gdiplus::Graphics &g)
{
	// todo
}
