#pragma once
#include "Tool.h"

// This tool takes in a function as a paramater for simple functions, such as save, load, colour fill etc. 
class ActionTool :
	public Tool
{
public:
	ActionTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas, void(*function)());
	~ActionTool();
	inline void onClickDown(int x, int y), onClickUp(int x, int y), onMove(int x, int y);
private:
	inline void renderGraphics();
	void (*actionFunc)();
};

inline void ActionTool::onClickDown(int x, int y)
{
	//GlobalSettings::getInstance()->runCurrentAction(actionFunc);
}

inline void ActionTool::onClickUp(int x, int y)
{
}

inline void ActionTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
}

inline void ActionTool::renderGraphics()
{
	UI->drawText(L"Click canvas confirm action.", 0, 0);
}
