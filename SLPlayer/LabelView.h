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

	// 设置模型
	void set_model(LabelModel *model);
	// 设置范围
	void set_pos(int left, int top, int width, int height) override;
	// 绘制
	void draw(Gdiplus::Graphics &g) override;
	// 查询字符宽度
	int get_char_width() const;

private:
	// 显示状态的绘制
	void display_draw(Gdiplus::Graphics &g);
	// 编辑状态的绘制
	void edit_draw(Gdiplus::Graphics &g);
	// 查询并设置单个字符宽度
	int query_char_width(Gdiplus::Graphics &g);

private:
	int m_left;
	int m_top;
	int m_width;
	int m_height;
	Gdiplus::Font* m_font = nullptr; // 字体
	int m_char_width = 0; // 字符宽度
	LabelModel *m_model = nullptr; // 模型引用
};

