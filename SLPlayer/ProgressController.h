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
	// ����ƶ���Ϣ
	void mouse_move_over();
	// ����������
	void left_button_down();
	// ����������
	void left_button_up();
	// ��ѯ�Ƿ��������ƶ�
	bool track_mouse_move();

private:
	// ����������
	int m_left;
	int m_top;
	int m_width;
	int m_height;
	// ���������������
	int m_slider_left;
	int m_slider_top;
	int m_slider_width;
	int m_slider_height;

	POINT m_mouse_pos; // ���λ��

	bool m_track_mouse_move = false; // �Ƿ���ٹ���ƶ�

	ProgressModel *m_mode = nullptr; // model������
};

