#pragma once
#include "Tool.h"
class SaveTool :
	public Tool
{
public:
	SaveTool();
	~SaveTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected:
	virtual void onMove(int x, int y) ;
};

