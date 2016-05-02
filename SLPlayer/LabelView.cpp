#include "LabelView.h"



LabelView::LabelView(unsigned int width, unsigned int height)
	:m_width(width), m_height(height)
{
}


LabelView::~LabelView()
{
}


// ���ñ�ǩ�ı�
void LabelView::setText(std::wstring text)
{
	m_text = text;
}


// ����ַ�
void LabelView::addCharacter(wchar_t c)
{
	if (m_selected)
	{
		// ���ַ�c�滻����ѡ�е�����
		m_text.replace(m_selectedStarPos, m_selectedEndPos - m_selectedStarPos, 1, c);
		m_selected = false;
		m_cursorPos = m_selectedStarPos + 1;
		m_selectedStarPos = m_selectedEndPos = 0;
	}
	else
	{
		// ����ַ�c��������ڵĵط�
		m_text.insert(m_text.begin() + m_cursorPos, c);
		m_cursorPos++;
	}
}
