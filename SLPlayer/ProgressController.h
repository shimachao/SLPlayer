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
	// 光标移动消息
	void mouse_move_over();
	// 鼠标左键按下
	void left_button_down();
	// 鼠标左键弹起
	void left_button_up();
	// 查询是否跟踪鼠标移动
	bool track_mouse_move();

private:
	// 进度条坐标
	int m_left;
	int m_top;
	int m_width;
	int m_height;
	// 进度条滑块的坐标
	int m_slider_left;
	int m_slider_top;
	int m_slider_width;
	int m_slider_height;

	POINT m_mouse_pos; // 光标位置

	bool m_track_mouse_move = false; // 是否跟踪光标移动

	ProgressModel *m_mode = nullptr; // model的引用
};

