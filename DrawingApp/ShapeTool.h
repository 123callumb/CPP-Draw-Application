#pragma once
#include "Tool.h"

class ShapeTool :
	public Tool
{
public:
	ShapeTool(EasyGraphics * currentInterface, int shapeType, const wchar_t * iconTexture);
	~ShapeTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
	static const int RECT = 0, CIRCLE = 1, LINE = 2;
protected: 
	void onMove(int x, int y);
private:
	int shapeType;
	int s[2], e[2], c[2]; //Coords for start, current and end 0 = x 1 = y etc
	void drawRect(), drawCricle(), drawLine();
	//const wchar_t * shapeIcons[3] = { L"Icon_Rect.bmp", L"Icon_Circle.bmp", L"Icon_Line.bmp"}; this doesn't work, ask mike myb?
};

