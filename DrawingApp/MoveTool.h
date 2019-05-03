#pragma once
#include "Tool.h"
#include "CanvasShape.h"
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
	int shapeID = -1; 
	int dxy[4];
};

