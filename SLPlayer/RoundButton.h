#pragma once
#include <string>
#include <map>
#include <functional>

class RoundButton
{

public:
	RoundButton();
	~RoundButton();

	// 鼠标移动到本按钮上
	void mouseMoveIn();
	// 鼠标移动到本按钮外
	void mouseMoveOut();
	// 按钮被按下
	void pressDown();
	// 按钮弹起
	void up();
	// 连接事件和响应动作
	enum class Event :unsigned int;
	void connect(Event event, std::function<void()> action);

	// --------------------类型定义----------------------------
public:
	// 按钮事件：按下、弹起、点击
	enum class Event :unsigned int
	{
		PRESS_DOWN, POP_UP, CLICK
	};

	// 按钮的状态：弹起，弹起+鼠标移入，按下
	enum class State :unsigned int
	{
		UP, UP_HIGHLIGHT, DOWN
	};

private:
	State m_state = State::UP; // 按钮的状态
	std::map<Event, std::function<void()>> m_eventToAction; // 事件和响应动作之间的映射
};

