#pragma once
#include "LabelModel.h"
#include <comdef.h>
#include <gdiplus.h>
#include "AbstractView.h"

class LabelView : public AbstractView
{
public:
	LabelView(int left, int top, int width, int height);
	~LabelView();

	// ����ģ��
	void set_model(LabelModel *model);
	// ���÷�Χ
	void set_pos(int left, int top, int width, int height) override;
	// ����
	void draw(Gdiplus::Graphics &g) override;

private:
	// ��ʾ״̬�Ļ���
	void display_draw(Gdiplus::Graphics &g);
	// �༭״̬�Ļ���
	void edit_draw(Gdiplus::Graphics &g);

private:
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	LabelModel *m_model = nullptr; // ģ������
};

