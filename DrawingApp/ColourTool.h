#pragma once
#include "Tool.h"
class ColourTool :
	public Tool
{
public:
	ColourTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas, int colour, bool outline);
	~ColourTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected:
	void onMove(int x, int y);
private: 
	int colour;
	bool outline = false;
};

