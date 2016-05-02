#include "ButtonModel.h"



ButtonModel::ButtonModel()
{
	m_eventToAction[Event::CLICK] = nullptr;
}


ButtonModel::~ButtonModel()
{
}


// ״̬תΪ����
void ButtonModel::turn_to_highlight()
{
	m_state = State::HIGHLIGHT;
}


// ״̬תΪ����
void ButtonModel::turn_to_normal()
{
	m_state = State::NORMAL;
}


// ״̬תΪ����
void ButtonModel::turn_to_down()
{
	m_state = State::PRESSDOWN;
}


// ����
void ButtonModel::click()
{
	if (m_eventToAction[Event::CLICK])
	{
		m_eventToAction[Event::CLICK]();
	}
}


// �����¼��Ͷ���
void ButtonModel::connect(Event e, std::function<void()> action)
{
	m_eventToAction[Event::CLICK] = action;
}
