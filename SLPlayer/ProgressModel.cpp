#include "ProgressModel.h"



ProgressModel::ProgressModel(int start, int end, int pos)
	:m_start(start), m_end(end), m_pos(pos)
{
	if (pos > end)
	{
		m_pos = end;
	}

	m_eventToAction[Event::SET_POS] = nullptr;
	m_eventToAction[Event::COMPLETE] = nullptr;
}


ProgressModel::~ProgressModel()
{
}


// 转为正常
void ProgressModel::turn_to_normal()
{
	m_state = State::NORMAL;
}


// 转为高亮
void ProgressModel::turn_to_highlight()
{
	m_state = State::HIGHLIGHT;
}


// 设置范围
void ProgressModel::set_range(int start, int end)
{
	m_start = start;
	m_end = end;
}


// 设置进度位置
void ProgressModel::set_pos(int pos)
{
	m_pos = pos;
	if (m_eventToAction[Event::SET_POS])
	{
		m_eventToAction[Event::SET_POS]();
	}
}


// 查询状态
ProgressModel::State ProgressModel::get_state() const
{
	return m_state;
}


// 查询范围和进度
void ProgressModel::get_range_pos(int &start, int &end, int &pos) const
{
	start = m_start;
	end = m_end;
	pos = m_pos;
}


// 连接事件和响应
void ProgressModel::connect(Event e, std::function<void()> action)
{
	m_eventToAction[e] = action;
}
