#include "RoundButton.h"



RoundButton::RoundButton()
{
	m_eventToAction[Event::PRESS_DOWN] = nullptr;
	m_eventToAction[Event::POP_UP] = nullptr;
	m_eventToAction[Event::CLICK] = nullptr;
}


RoundButton::~RoundButton()
{
}


// 鼠标移动到本按钮上
void RoundButton::mouseMoveIn()
{
	m_state = State::UP_HIGHLIGHT;
}


// 鼠标移动到本按钮外
void RoundButton::mouseMoveOut()
{
	m_state = State::UP;
}


// 按钮被按下
void RoundButton::pressDown()
{
	m_state = State::DOWN;
}


// 按钮弹起
void RoundButton::up()
{
	m_state = State::UP_HIGHLIGHT;
	
	if (m_eventToAction[Event::CLICK] != nullptr)
	{
		(m_eventToAction[Event::CLICK])();
	}
}


// 连接事件和响应动作
void RoundButton::connect(Event event, std::function<void()> action)
{
	m_eventToAction[event] = action;
}
