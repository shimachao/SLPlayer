#pragma once
#include <map>
#include <functional>

class ButtonModel
{
public:
	ButtonModel();
	~ButtonModel();

	// 单击
	void click();
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

private:
	std::map<Event, std::function<void()>> m_eventToAction; // 事件和响应动作之间的映射
};

