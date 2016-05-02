#include "LabelView.h"



LabelView::LabelView(unsigned int width, unsigned int height)
	:m_width(width), m_height(height)
{
}


LabelView::~LabelView()
{
}


// 设置标签文本
void LabelView::setText(std::wstring text)
{
	m_text = text;
}


// 添加字符
void LabelView::addCharacter(wchar_t c)
{
	if (m_selected)
	{
		// 用字符c替换掉被选中的文字
		m_text.replace(m_selectedStarPos, m_selectedEndPos - m_selectedStarPos, 1, c);
		m_selected = false;
		m_cursorPos = m_selectedStarPos + 1;
		m_selectedStarPos = m_selectedEndPos = 0;
	}
	else
	{
		// 添加字符c到光标所在的地方
		m_text.insert(m_text.begin() + m_cursorPos, c);
		m_cursorPos++;
	}
}
