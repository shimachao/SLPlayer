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


// 查询范围
void ProgressBar::getRange(unsigned int &min, unsigned int &max) const
{
	min = m_min;
	max = m_max;
}


// 设置范围
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


// 查询当前进度值
unsigned int ProgressBar::getPos() const
{
	return m_pos;
}


// 设置当前进度值
bool ProgressBar::setPos(unsigned int pos)
{
	if (pos >= m_min && pos <= m_max)
	{
		m_pos = pos;

		return true;
	}

	return false;
}


// 查询步长
unsigned int ProgressBar::getStep() const
{
	return m_step;
}


// 设置步长
bool ProgressBar::setStep(unsigned int step)
{
	if (step <= m_max - m_min)
	{
		m_step = step;
		
		return true;
	}

	return false;
}


// 按步长增加进度
void ProgressBar::increaseByStep()
{
	m_pos += m_step;
	if (m_pos >= m_max)
	{
		m_pos = m_max;
	}

	// 如果进度完成，且指定了对应的响应动作，就执行响应动作
	if (m_pos == m_max && m_eventToAction[Event::COMPLETED])
	{
		m_eventToAction[Event::COMPLETED]();
	}
}


// 按给定值增加进度
void ProgressBar::increaseBy(unsigned int increment)
{
	m_pos += increment;
	if (m_pos >= m_max)
	{
		m_pos = m_max;
	}

	// 如果进度完成，且指定了对应的响应动作，就执行响应动作
	if (m_pos == m_max && m_eventToAction[Event::COMPLETED])
	{
		m_eventToAction[Event::COMPLETED]();
	}
}


// 连接事件和动作
void ProgressBar::connect(Event event, std::function<void()> action)
{
	m_eventToAction[event] = action;
}
