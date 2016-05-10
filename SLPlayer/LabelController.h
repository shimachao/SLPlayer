#pragma once
#include "LabelModel.h"
#include "LabelView.h"
#include "AbstractController.h"

class LabelController : public AbstractController
{
public:
	LabelController(int left, int top, int width, int height);
	~LabelController();

	// ����model
	void set_model(LabelModel *model);
	// ���÷�Χ
	void set_pos(int left, int top, int width, int height) override;
	// ���в���
	bool hit_test(int x, int y) const override;
	// ����Ƴ�
	void mouse_move_out() override;
	// �������
	void mouse_move_in() override;
	// ����ƶ���Ϣ
	void mouse_move_over();
	// ����������
	void left_button_down() override;
	// ����������
	void left_button_up() override;
	// ������˫��
	void left_button_double_click();
	// �յ�WM_CHAR��Ϣ
	void receive_char(wchar_t c);
	// ʧȥ����
	void lost_focus();

private:
	int m_left;
	int m_top;
	int m_width;
	int m_height;
	bool m_select = false; // �Ƿ�����ѡ���ı�

	LabelModel *m_model = nullptr; // model����
	LabelView *m_view = nullptr; // view����
};

