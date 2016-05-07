#include "ProgressView.h"



ProgressView::ProgressView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
}


ProgressView::~ProgressView()
{
}


// ����model
void ProgressView::set_model(ProgressModel *model)
{
	m_model = model;
}


// ���÷�Χ
void ProgressView::set_pos(int left, int top, int width, int height)
{
	m_left = left;
	m_top = top;
	m_width = width;
	m_height = height;
}


// ����
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


// ����״̬�Ļ��Ʒ���
void ProgressView::normal_draw(Gdiplus::Graphics &g)
{
	// ���Ʊ߿�
	Gdiplus::Pen whitePen(Gdiplus::Color::White);
	g.DrawRectangle(&whitePen, m_left, m_top, m_width, m_height);
	// ���ƽ���
	int real_start, real_end, real_pos; // ʵ�����ݵķ�Χ�ͽ���
	m_model->get_range_pos(real_start, real_end, real_pos);

	int pos = ((real_pos - real_start) / (real_end - real_start))*m_width; // �����ϻ��ƽ���
	Gdiplus::SolidBrush brush(Gdiplus::Color(100, 255, 255, 255));
	g.FillRectangle(&brush, m_left, m_top, pos, m_height);

}


// ����ʱ�Ļ��Ʒ���
void ProgressView::highlight_draw(Gdiplus::Graphics &g)
{
	// todo
}
