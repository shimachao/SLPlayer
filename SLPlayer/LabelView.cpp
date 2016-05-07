#include "LabelView.h"



LabelView::LabelView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
}


LabelView::~LabelView()
{
}



// ����ģ��
void LabelView::set_model(LabelModel *model)
{
	m_model = model;
}


// ���÷�Χ
void LabelView::set_pos(int left, int top, int width, int height)
{
	m_left = left;
	m_top = top;
	m_width = width;
	m_height = height;
}


// ����
void LabelView::draw(Gdiplus::Graphics &g)
{
	if (m_model)
	{
		auto state = m_model->get_state();
		if (state == LabelModel::State::DISPLAY)
		{
			display_draw(g);
		}
		else if (state == LabelModel::State::EDIT)
		{
			edit_draw(g);
		}
	}
}


// ��ʾ״̬�Ļ���
void LabelView::display_draw(Gdiplus::Graphics &g)
{
	// todo
}

// �༭״̬�Ļ���
void LabelView::edit_draw(Gdiplus::Graphics &g)
{
	//todo:���ƹ�ꡢ���֡�ѡ��Ч��
}

