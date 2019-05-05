#pragma once
#include "Tool.h"
class ColourTool :
	public Tool
{
public:
	ColourTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas, bool outline);
	~ColourTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected:
	void onMove(int x, int y);
private: 
	bool outline = false;
};

