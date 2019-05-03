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
	// When drawing the scribble we need to track its bouding rectangle
	int sX = INT_MAX, sY = INT_MAX, bX = 0, bY = 0;
};

