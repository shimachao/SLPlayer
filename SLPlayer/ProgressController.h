#pragma once
#include "ProgressModel.h"
#include <Windows.h>

class ProgressController
{
public:
	ProgressController(int left, int top, int width, int height);
	~ProgressController();

	// ����model
	void set_model(ProgressModel *model);

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
	// ����������
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	POINT m_mouse_pos; // ���λ��
	ProgressModel *m_mode = nullptr; // model������
};

