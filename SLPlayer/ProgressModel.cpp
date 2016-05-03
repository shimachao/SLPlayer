#include "ProgressModel.h"



ProgressModel::ProgressModel(int start, int end, int pos)
	:m_start(start), m_end(end), m_pos(pos)
{
	if (pos > end)
	{
		m_pos = end;
	}

	m_eventToAction[Event::SET_POS] = nullptr;
	m_eventToAction[Event::COMPLETE] = nullptr;
}


ProgressModel::~ProgressModel()
{
}


// תΪ����
void ProgressModel::turn_to_normal()
{
	m_state = State::NORMAL;
}


// תΪ��������
void ProgressModel::turn_to_slide_highlight()
{
	m_state = State::SLIDE_HIGHLIGHT;
}


// תΪ�����ͻ��鶼����
void ProgressModel::turn_to_all_highlight()
{
	m_state = State::ALL_HIGHLIGHT;
}


// ���÷�Χ
void ProgressModel::set_range(int start, int end)
{
	m_start = start;
	m_end = end;
}


// ���ý���λ��
void ProgressModel::set_pos(int pos)
{
	m_pos = pos;
	if (m_eventToAction[Event::SET_POS])
	{
		m_eventToAction[Event::SET_POS]();
	}
}


// ��ѯ״̬
ProgressModel::State ProgressModel::get_state() const
{
	return m_state;
}


// ��ѯ��Χ�ͽ���
void ProgressModel::get_range_pos(int &start, int &end, int &pos) const
{
	start = m_start;
	end = m_end;
	pos = m_pos;
}