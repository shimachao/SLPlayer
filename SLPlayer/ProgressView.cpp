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

		case ProgressModel::State::SLIDE_HIGHLIGHT:
			slide_highlight_draw(g);
			break;

		case ProgressModel::State::ALL_HIGHLIGHT:
			all_highlight_draw(g);
			break;
		}
	}
}


// ����״̬�Ļ��Ʒ���
void ProgressView::normal_draw(Gdiplus::Graphics &g)
{
	// todo
}


// ��������ʱ�Ļ��Ʒ���
void ProgressView::slide_highlight_draw(Gdiplus::Graphics &g)
{
	// todo
}


// �����ͻ��鶼����ʱ�Ļ��Ʒ���
void ProgressView::all_highlight_draw(Gdiplus::Graphics &g)
{
	// todo
}
