#include "ButtonModel.h"



ButtonModel::ButtonModel()
{
	m_eventToAction[Event::CLICK] = nullptr;
}


ButtonModel::~ButtonModel()
{
}


// 状态转为高亮
void ButtonModel::turn_to_highlight()
{
	m_state = State::HIGHLIGHT;
}


// 状态转为正常
void ButtonModel::turn_to_normal()
{
	m_state = State::NORMAL;
}


// 状态转为按下
void ButtonModel::turn_to_down()
{
	m_state = State::DOWN;
}


// 被单击了
void ButtonModel::click()
{
	if (m_eventToAction[Event::CLICK])
	{
		m_eventToAction[Event::CLICK]();
	}
}


// 查询状态
ButtonModel::State ButtonModel::get_state() const
{
	return m_state;
}

// 连接事件和动作
void ButtonModel::connect(Event e, std::function<void()> action)
{
	m_eventToAction[Event::CLICK] = action;
}
