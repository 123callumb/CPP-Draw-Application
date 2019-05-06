#pragma once
#include "Tool.h"
#include <fstream>
#include <vector>

class SaveTool :
	public Tool
{
public:
	SaveTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas);
	~SaveTool();
	void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected:
	virtual void onMove(int x, int y);
private:
	bool error = false;
};

