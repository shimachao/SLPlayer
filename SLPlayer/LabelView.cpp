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


// 显示状态的绘制
void LabelView::display_draw(Gdiplus::Graphics &g)
{
	// 绘制背景颜色
	Gdiplus::SolidBrush bgBrush(Gdiplus::Color::Yellow);
	g.FillRectangle(&bgBrush, m_left, m_top, m_width, m_height);

	// 绘制文字
	Gdiplus::FontFamily fontFamily(L"微软雅黑");
	Gdiplus::Font font(&fontFamily, 14, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
	Gdiplus::SolidBrush textBrush(Gdiplus::Color::Black);
	Gdiplus::StringFormat stringFormat;
	stringFormat.SetAlignment(Gdiplus::StringAlignmentCenter);
	stringFormat.SetLineAlignment(Gdiplus::StringAlignmentCenter);
	Gdiplus::RectF rectF(m_left, m_top, m_width, m_height);
	g.DrawString(m_model->get_text().c_str(), -1, &font, rectF, &stringFormat, &textBrush);
}

// 编辑状态的绘制
void LabelView::edit_draw(Gdiplus::Graphics &g)
{
	//todo:绘制光标、文字、选中效果
}

