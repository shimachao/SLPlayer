#include "LabelView.h"



LabelView::LabelView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
}


LabelView::~LabelView()
{
}



// 设置模型
void LabelView::set_model(LabelModel *model)
{
	m_model = model;
}


// 设置范围
void LabelView::set_pos(int left, int top, int width, int height)
{
	m_left = left;
	m_top = top;
	m_width = width;
	m_height = height;
}


// 绘制
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


// 显示状态的绘制
void LabelView::display_draw(Gdiplus::Graphics &g)
{
	// todo
}

// 编辑状态的绘制
void LabelView::edit_draw(Gdiplus::Graphics &g)
{
	//todo:绘制光标、文字、选中效果
}

