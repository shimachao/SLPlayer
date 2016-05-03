#pragma once
#include <map>
#include <functional>

class ButtonModel
{
public:
	ButtonModel();
	~ButtonModel();

	// 状态转为高亮
	void turn_to_highlight();
	// 状态转为正常
	void turn_to_normal();
	// 状态转为按下
	void turn_to_down();
	// 被单击了
	void click();

	// 查询状态
	enum class State;
	State get_state() const;

	// 连接事件和动作
	enum class Event;
	void connect(Event e, std::function<void()> action);

	// --------------------类型定义----------------------------
public:
	// 按钮事件：单击
	enum class Event
	{
		CLICK
	};

	// 按钮的状态：正常、高亮、按下
	enum class State
	{
		NORMAL, HIGHLIGHT, DOWN
	};

private:
	std::map<Event, std::function<void()>> m_eventToAction; // 事件和响应动作之间的映射
	State m_state = State::NORMAL;
};

