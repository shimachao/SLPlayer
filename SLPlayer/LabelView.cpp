#include "LabelView.h"



LabelView::LabelView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
	Gdiplus::FontFamily fontFamily(L"方正兰亭黑_GB18030");
	m_font = new Gdiplus::Font(&fontFamily, 16, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
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
	// 如果是第一次进入该函数，就利用g计算单个字符宽度
	static auto w = query_char_width(g);

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
	Gdiplus::SolidBrush textBrush(Gdiplus::Color::Black);
	Gdiplus::StringFormat stringFormat;
	stringFormat.SetAlignment(Gdiplus::StringAlignmentCenter);
	stringFormat.SetLineAlignment(Gdiplus::StringAlignmentCenter);
	Gdiplus::RectF rectF(m_left, m_top, m_width, m_height);
	g.DrawString(m_model->get_text().c_str(), -1, m_font, rectF, &stringFormat, &textBrush);
}

// 编辑状态的绘制
void LabelView::edit_draw(Gdiplus::Graphics &g)
{
	// 绘制边框
	Gdiplus::Pen pen(Gdiplus::Color::Black);
	g.DrawRectangle(&pen, m_left, m_top, m_width, m_height);

	// 绘制文字
	Gdiplus::SolidBrush textBrush(Gdiplus::Color::Black);
	Gdiplus::StringFormat stringFormat;
	stringFormat.SetAlignment(Gdiplus::StringAlignmentNear); // 水平方向左对齐
	stringFormat.SetLineAlignment(Gdiplus::StringAlignmentCenter); // 垂直方向居中对齐
	Gdiplus::RectF rectF(m_left, m_top, m_width, m_height);
	g.DrawString(m_model->get_text().c_str(), -1, m_font, rectF, &stringFormat, &textBrush);

	// 绘制光标
	size_t cursor_pos = m_model->get_cursor_pos();
	// 计算光标的位置
	Gdiplus::RectF rf;
	g.MeasureString(m_model->get_text().c_str(), cursor_pos, m_font, rectF, &stringFormat, &rf);
	g.DrawLine(&pen, rf.GetRight(), rf.Y, rf.GetRight(), rf.Y + rf.GetBottom());

	// 绘制文字选中效果
	size_t start = 0, end = 0; // 被选中文字的下标范围
	m_model->get_selected_range(start, end);
	// 如果需要绘制选中效果
	if (start < end)
	{
		// 计算被选中文本的x方向坐标范围
		g.MeasureString(m_model->get_text().c_str(), start, m_font, rectF, &stringFormat, &rectF);
		auto startx = rectF.X + rectF.Width; // 起始位置
		g.MeasureString(m_model->get_text().c_str(), end + 1, m_font, rectF, &stringFormat, &rectF);
		auto starty = rectF.X + rectF.Width; // 结束位置
		// 绘制效果
		Gdiplus::SolidBrush bgBrush(Gdiplus::Color(120, 0, 0, 255));
		g.FillRectangle(&bgBrush, (Gdiplus::REAL)startx, 
			(Gdiplus::REAL)m_top, (Gdiplus::REAL)(starty-startx), (Gdiplus::REAL)m_height);
	}
}


// 查询并设置单个字符宽度
int LabelView::query_char_width(Gdiplus::Graphics &g)
{
	Gdiplus::RectF layout(m_left, m_top, m_width, m_height);
	Gdiplus::RectF bound;
	int linesFilled = 0;
	int codePointsFitted = 0;
	g.MeasureString(L"hello你好", -1, m_font, layout, 0,&bound);
	
	m_char_width = bound.Width / wcsnlen(L"hello你好", 7);
	return m_char_width;
}


// 查询字符宽度
int LabelView::get_char_width() const
{
	return m_char_width;
}
