#pragma once
#include <map>
#include <functional>

class ProgressModel
{
public:
	ProgressModel(int start, int end, int pos = 0);
	~ProgressModel();

	// 转为正常
	void turn_to_normal();
	// 转为高亮
	void turn_to_highlight();
	
	// 设置范围
	void set_range(int start, int end);
	// 设置进度位置
	void set_pos(int pos);
	// 查询范围和进度
	void get_range_pos(int &start, int &end, int &pos) const;

	// 查询状态
	enum class State;
	State get_state() const;

	// --------------------类型定义----------------------------
public:
	// 进度的状态：正常、高亮
	enum class State
	{
		NORMAL, HIGHLIGHT
	};

	// 进度条事件：设置位置，进度完成
	enum class Event
	{
		SET_POS, COMPLETE
	};


private:
	int m_start = 0; // 进度范围最小值
	int m_end = 10; // 进度范围最大值
	int m_pos = 0; // 进度的当前位置
	std::map<Event, std::function<void()>> m_eventToAction; // 事件和响应动作之间的映射
	State m_state = State::NORMAL;
};

