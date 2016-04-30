#pragma once
#include <map>
#include <functional>

class ProgressBar
{
public:
	ProgressBar(unsigned int min, unsigned int max, unsigned int pos = 0, unsigned int step = 1);
	~ProgressBar();

	// 查询范围
	void getRange(unsigned int &min, unsigned int &max) const;
	// 设置范围
	bool setRange(unsigned int min, unsigned int max);

	// 查询当前进度值
	unsigned int getPos() const;
	// 设置当前进度值
	bool setPos(unsigned int pos);

	// 查询步长
	unsigned int getStep() const;
	// 设置步长
	bool setStep(unsigned int step);
	
	// 按步长增加进度
	void increaseByStep();
	// 按给定值增加进度
	void increaseBy(unsigned int increment);

	// 连接事件和动作
	enum class Event:unsigned int;
	void connect(Event event, std::function<void()> action);

public:
	// 事件类型定义：进度已完成
	enum class Event:unsigned int
	{
		COMPLETED
	};
	
private:
	unsigned int m_min; // 范围的最小值
	unsigned int m_max; // 范围的最大值，范围是[min, max]
	unsigned int m_step; // 步长
	unsigned int m_pos; // 当前进度值
	std::map<Event, std::function<void()>> m_eventToAction; // 事件和响应动作之间的映射，暂时只有一个COMPLETED事件
};

