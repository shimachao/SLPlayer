#pragma once
#include "ProgressModel.h"
#include <comdef.h>
#include <Gdiplus.h>

class ProgressView
{
public:
	ProgressView(int left, int top, int width, int height);
	~ProgressView();

	// ����model
	void set_model(ProgressModel *model);
	// ����
	void draw(Gdiplus::Graphics &g);

private:
	// ����״̬�Ļ��Ʒ���
	void normal_draw(Gdiplus::Graphics &g);
	// ����ʱ�Ļ��Ʒ���
	void highlight_draw(Gdiplus::Graphics &g);

private:
	// ����������
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	ProgressModel *m_model = nullptr;
};

