#pragma once
#include "ButtonModel.h"

class ButtonController
{
public:
	ButtonController(int left, int top, int width, int height);
	~ButtonController();
	// 设置model
	void set_model(ButtonModel *model);

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
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	ButtonModel *m_model = nullptr;
};

