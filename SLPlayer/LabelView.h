#pragma once
#include "LabelModel.h"
#include <comdef.h>
#include <gdiplus.h>

class LabelView
{
public:
	LabelView(int left, int top, int width, int height);
	~LabelView();

	// ����ģ��
	void set_model(LabelModel *model);
	// ����
	void draw(Gdiplus::Graphics &g);

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

