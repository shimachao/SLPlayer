#include "ButtonModel.h"



ButtonModel::ButtonModel()
{
	m_eventToAction[Event::CLICK] = nullptr;
}


ButtonModel::~ButtonModel()
{
}


// 单击
void ButtonModel::click()
{
	if (m_eventToAction[Event::CLICK])
	{
		m_eventToAction[Event::CLICK]();
	}
}


// 连接事件和动作
void ButtonModel::connect(Event e, std::function<void()> action)
{
	m_eventToAction[Event::CLICK] = action;
}
