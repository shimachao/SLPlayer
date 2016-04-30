#include "ProgressBar.h"



ProgressBar::ProgressBar(unsigned int min, unsigned int max, unsigned int pos, unsigned int step)
	:m_min(min), m_max(max), m_pos(pos), m_step(step)
{
	if (min > max)
	{
		m_min = max;
		m_max = min;
	}

	if (step > m_max - m_min)
	{
		m_step = m_max - m_min;
	}

	m_eventToAction[Event::COMPLETED] = nullptr;
}


ProgressBar::~ProgressBar()
{
}


// ��ѯ��Χ
void ProgressBar::getRange(unsigned int &min, unsigned int &max) const
{
	min = m_min;
	max = m_max;
}


// ���÷�Χ
bool ProgressBar::setRange(unsigned int min, unsigned int max)
{
	if (min < max)
	{
		m_min = min;
		m_max = max;

		return true;
	}

	return false;
}


// ��ѯ��ǰ����ֵ
unsigned int ProgressBar::getPos() const
{
	return m_pos;
}


// ���õ�ǰ����ֵ
bool ProgressBar::setPos(unsigned int pos)
{
	if (pos >= m_min && pos <= m_max)
	{
		m_pos = pos;

		return true;
	}

	return false;
}


// ��ѯ����
unsigned int ProgressBar::getStep() const
{
	return m_step;
}


// ���ò���
bool ProgressBar::setStep(unsigned int step)
{
	if (step <= m_max - m_min)
	{
		m_step = step;
		
		return true;
	}

	return false;
}


// ���������ӽ���
void ProgressBar::increaseByStep()
{
	m_pos += m_step;
	if (m_pos >= m_max)
	{
		m_pos = m_max;
	}

	// ���������ɣ���ָ���˶�Ӧ����Ӧ��������ִ����Ӧ����
	if (m_pos == m_max && m_eventToAction[Event::COMPLETED])
	{
		m_eventToAction[Event::COMPLETED]();
	}
}


// ������ֵ���ӽ���
void ProgressBar::increaseBy(unsigned int increment)
{
	m_pos += increment;
	if (m_pos >= m_max)
	{
		m_pos = m_max;
	}

	// ���������ɣ���ָ���˶�Ӧ����Ӧ��������ִ����Ӧ����
	if (m_pos == m_max && m_eventToAction[Event::COMPLETED])
	{
		m_eventToAction[Event::COMPLETED]();
	}
}


// �����¼��Ͷ���
void ProgressBar::connect(Event event, std::function<void()> action)
{
	m_eventToAction[event] = action;
}
