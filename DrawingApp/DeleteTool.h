#pragma once
#include "Tool.h"
// Tool for deleting canvas elements
class DeleteTool :
	public Tool
{
public:
	DeleteTool(EasyGraphics * currentInterface, const wchar_t * iconTexture, Canvas * currentCanvas);
	~DeleteTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected:
	void onMove(int x, int y);
};

