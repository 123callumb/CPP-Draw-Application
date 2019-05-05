#include "ActionTool.h"



ActionTool::ActionTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas, void (*function)()) : Tool(currentInterface, iconName, currentCanvas), actionFunc(function)
{
}

ActionTool::~ActionTool()
{
}

