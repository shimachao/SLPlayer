#pragma once
#include "AbstractControl.h"
#include "LabelView.h"
#include "LabelController.h"
#include "LabelModel.h"

class Label :
	public AbstractControl
{
public:
	Label(int left, int top, int width, int height);
	virtual ~Label();

	// ����
	void draw(Gdiplus::Graphics &g) override;

	// ���в���
	bool hit_test(int x, int y) const override;
	// ����Ƴ�
	void mouse_move_out() override;
	// �������
	void mouse_move_in() override;
	// ����������
	void left_button_down() override;
	// ����������
	void left_button_up() override;

	// ����ƶ���Ϣ
	void mouse_move_over();
	// ������˫��
	void left_button_double_click();
	// �յ�WM_CHAR��Ϣ
	void receive_char(wchar_t c);


private:
	LabelView *m_view = nullptr;
	LabelController *m_controller = nullptr;
	LabelModel *m_model = nullptr;
};

