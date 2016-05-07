#pragma once
#include "AbstractControl.h"
#include "ButtonView.h"
#include "ButtonController.h"
#include "ButtonModel.h"

class Button :
	public AbstractControl
{
public:
	Button(int left, int top, int width, int height);
	virtual ~Button();

	// 设置绘制范围
	void set_pos(int left, int top, int width, int height) override;
	// 绘制
	void draw(Gdiplus::Graphics &g) override;

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
	ButtonView *m_view = nullptr;
	ButtonController *m_controller = nullptr;
	ButtonModel *m_model = nullptr;
};

