#include "Tools.h"

Tools::Tools(EasyGraphics * currentInterface, Canvas * currentCanvas) : ui(currentInterface), canvas(currentCanvas)
{	
	ShapeTool * rectTool = new ShapeTool(ui, BoundingArea::RECT, L"Icon_Rect.bmp", canvas);
	ShapeTool * circleTool = new ShapeTool(ui, BoundingArea::CIRCLE, L"Icon_Circle.bmp", canvas);
	ShapeTool * lineTool = new ShapeTool(ui, BoundingArea::LINE, L"Icon_Line.bmp", canvas);

	toolList.push_back(rectTool);
	toolList.push_back(circleTool);
	toolList.push_back(lineTool);
}


Tools::~Tools()
{
}

void Tools::currentToolMovement(int x, int y, int currentTool)
{
	if (currentTool >= 0) {
		currentToolID = currentTool;
		toolList.at(currentToolID)->move(x, y);
	}
}

void Tools::currerntToolDown(int x, int y)
{
	if (currentToolID >= 0) {
		toolList.at(currentToolID)->onClickDown(x, y);
	}
}

void Tools::currrentToolUp(int x, int y)
{
	if (currentToolID >= 0) {
		toolList.at(currentToolID)->onClickUp(x, y);
	}
}

void Tools::renderCurrrentToolIcon()
{
	if (currentToolID >= 0) {
		toolList.at(currentToolID)->renderIcon();
	}
}

void Tools::renderCurrentToolGraphics()
{
	if (currentToolID >= 0) {
		toolList.at(currentToolID)->renderGraphics();
	}
}


