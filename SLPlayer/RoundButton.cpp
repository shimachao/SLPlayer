#include "RoundButton.h"



RoundButton::RoundButton()
{
	m_eventToAction[PRESS_DOWN] = nullptr;
	m_eventToAction[POP_UP] = nullptr;
	m_eventToAction[CLICK] = nullptr;
}


RoundButton::~RoundButton()
{
}


// 鼠标移动到本按钮上
void RoundButton::mouseMoveIn()
{
	m_state = UP_HIGHLIGHT;
}


// 鼠标移动到本按钮外
void RoundButton::mouseMoveOut()
{
	m_state = UP;
}


// 按钮被按下
void RoundButton::pressDown()
{
	m_state = DOWN;
}


// 按钮弹起
void RoundButton::up()
{
	m_state = UP_HIGHLIGHT;
	
	if (m_eventToAction[CLICK] != nullptr)
	{
		(m_eventToAction[CLICK])();
	}
}
