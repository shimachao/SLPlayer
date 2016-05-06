#pragma once
#include "ProgressModel.h"
#include <Windows.h>

class ProgressController
{
public:
	ProgressController(int left, int top, int width, int height);
	~ProgressController();

	// 设置model
	void set_model(ProgressModel *model);

	// 击中测试
	bool hit_test(int x, int y) const;
	// 光标移出
	void mouse_move_out();
	// 光标移入
	void mouse_move_in();
	// 鼠标左键按下
	void left_button_down();
	// 鼠标左键弹起
	void left_button_up();

private:
	// 进度条坐标
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	ProgressModel *m_mode = nullptr; // model的引用
};

