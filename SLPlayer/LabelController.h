#pragma once
#include "LabelModel.h"
#include "LabelView.h"

class LabelController
{
public:
	LabelController(int left, int top, int width, int height);
	~LabelController();

	// ����model
	void set_model(LabelModel *model);

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
	// �յ�WM_CHAR��Ϣ
	void receive_char(wchar_t c);

private:
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	LabelModel *m_model = nullptr; // model����
	LabelView *m_view = nullptr; // view����
};

