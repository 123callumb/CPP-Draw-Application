#pragma once
#include "Tool.h"
#include "CanvasScribble.h"

class PenTool :
	public Tool
{
public:
	PenTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas);
	~PenTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected:
	virtual void onMove(int x, int y);
private:
	vector<CanvasScribble::Point> linePoints;
	bool held = false;
};

