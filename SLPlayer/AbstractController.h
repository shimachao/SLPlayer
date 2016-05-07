#pragma once
class AbstractController
{
public:
	AbstractController();
	~AbstractController();

	// 设置有效范围
	virtual void set_pos(int left, int top, int width, int height) = 0;
	// 击中测试
	virtual bool hit_test(int x, int y) const = 0;
	// 光标移出
	virtual void mouse_move_out() = 0;
	// 光标移入
	virtual void mouse_move_in() = 0;
	// 鼠标左键按下
	virtual void left_button_down() = 0;
	// 鼠标左键弹起
	virtual void left_button_up() = 0;
};

