#pragma once
#include "ButtonModel.h"
#include "AbstractController.h"

class ButtonController:public AbstractController
{
public:
	ButtonController(int left, int top, int width, int height);
	~ButtonController();
	// 设置model
	void set_model(ButtonModel *model);

	// 击中测试
	bool hit_test(int x, int y) const override;
	// 光标移出
	void mouse_move_out() override;
	// 光标移入
	void mouse_move_in() override;
	// 鼠标左键按下
	void left_button_down() override;
	// 鼠标左键弹起
	void left_button_up() override;

private:
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	ButtonModel *m_model = nullptr;
};

