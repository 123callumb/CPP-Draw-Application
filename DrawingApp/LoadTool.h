#pragma once
#include "Tool.h"
#include <fstream>
#include "CanvasShape.h"

class LoadTool :
	public Tool
{
public:
	LoadTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas);
	~LoadTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected:
	void onMove(int x, int y);
private:
	bool error = false;
};

