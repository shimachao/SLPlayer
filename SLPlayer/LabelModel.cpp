#include "LabelModel.h"



LabelModel::LabelModel()
{
}


LabelModel::~LabelModel()
{
}


// �����ı�
void LabelModel::set_text(std::wstring text)
{
	m_text = text;
}


// ��ѯ�ַ�
std::wstring LabelModel::get_text() const
{
	return m_text;
}


// ����ַ����ڹ������λ�����
void LabelModel::add_char(wchar_t c)
{
	m_text.insert(m_cursor_pos, 1, c);
}


// תΪ�༭״̬
void LabelModel::turn_to_edit()
{
	m_state = State::EDIT;
}


// תΪ��ʾ״̬
void LabelModel::turn_to_display()
{
	m_state = State::DISPLAY;
	m_selected_star_pos = m_selected_end_pos = 0;
}


// ��ѯ״̬
LabelModel::State LabelModel::get_state() const
{
	return m_state;
}



// ���ù��λ��
void LabelModel::set_cursor_pos(std::wstring::size_type pos)
{
	if (pos >= 0 && pos <= m_text.size())
	{
		m_cursor_pos = pos;
	}
}


// ��ѯ���λ��
std::wstring::size_type LabelModel::get_cursor_pos() const
{
	return m_cursor_pos;
}


// ���ñ�ѡ���ַ��ķ�Χ
void LabelModel::set_selected_range(std::wstring::size_type start, std::wstring::size_type end)
{
	if (start >= 0 && end <= m_text.size() && start < end)
	{
		m_selected_star_pos = start;
		m_selected_end_pos = end;
	}
}


// ��ѯ��ѡ���ı��ķ�Χ
void LabelModel::get_selected_range(std::wstring::size_type &start, std::wstring::size_type &end) const
{
	start = m_selected_star_pos;
	end = m_selected_end_pos;
}


// ȡ��ѡ�в���
void LabelModel::deselect()
{
	m_selected_star_pos = m_selected_end_pos = 0;
}
