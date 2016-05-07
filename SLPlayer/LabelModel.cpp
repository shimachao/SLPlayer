#include "LabelModel.h"



LabelModel::LabelModel()
{
}


LabelModel::~LabelModel()
{
}


// 设置文本
void LabelModel::set_text(std::wstring text)
{
	m_text = text;
}


// 查询字符
std::wstring LabelModel::get_text() const
{
	return m_text;
}


// 添加字符，在光标所在位置添加
void LabelModel::add_char(wchar_t c)
{
	m_text.insert(m_cursor_pos, 1, c);
}


// 转为编辑状态
void LabelModel::turn_to_edit()
{
	m_state = State::EDIT;
}


// 转为显示状态
void LabelModel::turn_to_display()
{
	m_state = State::DISPLAY;
	m_selected_star_pos = m_selected_end_pos = 0;
}


// 查询状态
LabelModel::State LabelModel::get_state() const
{
	return m_state;
}



// 设置光标位置
void LabelModel::set_cursor_pos(std::wstring::size_type pos)
{
	if (pos >= 0 && pos <= m_text.size())
	{
		m_cursor_pos = pos;
	}
}


// 查询光标位置
std::wstring::size_type LabelModel::get_cursor_pos() const
{
	return m_cursor_pos;
}


// 设置被选中字符的范围
void LabelModel::set_selected_range(std::wstring::size_type start, std::wstring::size_type end)
{
	if (start >= 0 && end <= m_text.size() && start < end)
	{
		m_selected_star_pos = start;
		m_selected_end_pos = end;
	}
}


// 查询被选中文本的范围
void LabelModel::get_selected_range(std::wstring::size_type &start, std::wstring::size_type &end) const
{
	start = m_selected_star_pos;
	end = m_selected_end_pos;
}


// 取消选中操作
void LabelModel::deselect()
{
	m_selected_star_pos = m_selected_end_pos = 0;
}
