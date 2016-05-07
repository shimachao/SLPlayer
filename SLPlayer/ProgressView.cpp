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


// ����״̬�Ļ��Ʒ���
void ProgressView::normal_draw(Gdiplus::Graphics &g)
{
	// todo
}


// ����ʱ�Ļ��Ʒ���
void ProgressView::highlight_draw(Gdiplus::Graphics &g)
{
	// todo
}
