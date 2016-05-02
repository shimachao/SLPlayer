#pragma once
#include "ButtonModel.h"

class ButtonController
{
public:
	ButtonController(int left, int top, int width, int height);
	~ButtonController();
	// ����model
	void set_model(ButtonModel *model);

	// ���в���
	bool hit_test(int x, int y) const;
	// ����Ƴ�
	void mouse_move_out();
	// �������
	void mouse_move_in();
	// ����������
	void left_button_down();
	// ����������
	void left_button_up();

private:
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	ButtonModel *m_model = nullptr;
};

