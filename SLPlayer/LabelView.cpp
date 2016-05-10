#include "LabelView.h"



LabelView::LabelView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
	Gdiplus::FontFamily fontFamily(L"������ͤ��_GB18030");
	m_font = new Gdiplus::Font(&fontFamily, 16, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
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
	// ����ǵ�һ�ν���ú�����������g���㵥���ַ����
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


// ��ʾ״̬�Ļ���
void LabelView::display_draw(Gdiplus::Graphics &g)
{
	// ���Ʊ�����ɫ
	Gdiplus::SolidBrush bgBrush(Gdiplus::Color::Yellow);
	g.FillRectangle(&bgBrush, m_left, m_top, m_width, m_height);

	// ��������
	Gdiplus::SolidBrush textBrush(Gdiplus::Color::Black);
	Gdiplus::StringFormat stringFormat;
	stringFormat.SetAlignment(Gdiplus::StringAlignmentCenter);
	stringFormat.SetLineAlignment(Gdiplus::StringAlignmentCenter);
	Gdiplus::RectF rectF(m_left, m_top, m_width, m_height);
	g.DrawString(m_model->get_text().c_str(), -1, m_font, rectF, &stringFormat, &textBrush);
}

// �༭״̬�Ļ���
void LabelView::edit_draw(Gdiplus::Graphics &g)
{
	// ���Ʊ߿�
	Gdiplus::Pen pen(Gdiplus::Color::Black);
	g.DrawRectangle(&pen, m_left, m_top, m_width, m_height);

	// ��������
	Gdiplus::SolidBrush textBrush(Gdiplus::Color::Black);
	Gdiplus::StringFormat stringFormat;
	stringFormat.SetAlignment(Gdiplus::StringAlignmentNear); // ˮƽ���������
	stringFormat.SetLineAlignment(Gdiplus::StringAlignmentCenter); // ��ֱ������ж���
	Gdiplus::RectF rectF(m_left, m_top, m_width, m_height);
	g.DrawString(m_model->get_text().c_str(), -1, m_font, rectF, &stringFormat, &textBrush);

	// ���ƹ��
	size_t cursor_pos = m_model->get_cursor_pos();
	// �������λ��
	Gdiplus::RectF rf;
	g.MeasureString(m_model->get_text().c_str(), cursor_pos, m_font, rectF, &stringFormat, &rf);
	g.DrawLine(&pen, rf.GetRight(), rf.Y, rf.GetRight(), rf.Y + rf.GetBottom());

	// ��������ѡ��Ч��
	size_t start = 0, end = 0; // ��ѡ�����ֵ��±귶Χ
	m_model->get_selected_range(start, end);
	// �����Ҫ����ѡ��Ч��
	if (start < end)
	{
		// ���㱻ѡ���ı���x�������귶Χ
		g.MeasureString(m_model->get_text().c_str(), start, m_font, rectF, &stringFormat, &rectF);
		auto startx = rectF.X + rectF.Width; // ��ʼλ��
		g.MeasureString(m_model->get_text().c_str(), end + 1, m_font, rectF, &stringFormat, &rectF);
		auto starty = rectF.X + rectF.Width; // ����λ��
		// ����Ч��
		Gdiplus::SolidBrush bgBrush(Gdiplus::Color(120, 0, 0, 255));
		g.FillRectangle(&bgBrush, (Gdiplus::REAL)startx, 
			(Gdiplus::REAL)m_top, (Gdiplus::REAL)(starty-startx), (Gdiplus::REAL)m_height);
	}
}


// ��ѯ�����õ����ַ����
int LabelView::query_char_width(Gdiplus::Graphics &g)
{
	Gdiplus::RectF layout(m_left, m_top, m_width, m_height);
	Gdiplus::RectF bound;
	int linesFilled = 0;
	int codePointsFitted = 0;
	g.MeasureString(L"hello���", -1, m_font, layout, 0,&bound);
	
	m_char_width = bound.Width / wcsnlen(L"hello���", 7);
	return m_char_width;
}


// ��ѯ�ַ����
int LabelView::get_char_width() const
{
	return m_char_width;
}
