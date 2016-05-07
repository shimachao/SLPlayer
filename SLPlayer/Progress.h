#pragma once
#include "AbstractControl.h"
#include "ProgressView.h"
#include "ProgressController.h"
#include "ProgressModel.h"

class Progress :
	public AbstractControl
{
public:
	Progress(int left, int top, int width, int height, int start = 0, int end = 100);
	virtual ~Progress();

	// 设置范围
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

	// 光标移动消息
	void mouse_move_over();

private:
	ProgressView *m_view = nullptr;
	ProgressController *m_controller = nullptr;
	ProgressModel *m_model = nullptr;
};

