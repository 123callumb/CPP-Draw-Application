#pragma once
#include "Tool.h"
#include "BoundingArea.h"


class ShapeTool :
	public Tool
{
public:
	ShapeTool(EasyGraphics * currentInterface, int shapeType, const wchar_t * iconTexture, Canvas * currentCanvas);
	~ShapeTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected: 
	void onMove(int x, int y);
private:
	int shapeType;
	int s[2], e[2], c[2]; //  Coords for start, current and end 0 = x 1 = y etc
	void drawRect(), drawCricle(), drawLine(), createShape();
	//const wchar_t * shapeIcons[3] = { L"Icon_Rect.bmp", L"Icon_Circle.bmp", L"Icon_Line.bmp"}; // TODO: this doesn't work, ask mike myb
};