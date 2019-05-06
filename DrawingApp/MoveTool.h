#pragma once
#include "Tool.h"
#include "CanvasShape.h"

struct SelectData{
	int id;
	int dxy[4];
};

class MoveTool :
	public Tool
{
public:
	MoveTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas);
	~MoveTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected:
	void onMove(int x, int y);
private:
	int moving = false; 
	vector<SelectData> selectedItems;
	BoundingArea selectedBounds = BoundingArea(INT_MAX, INT_MAX, 0, 0, BoundingArea::RECT);
};

