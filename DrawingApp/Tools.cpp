#include "Tools.h"

Tools::Tools(EasyGraphics * currentInterface, Canvas * currentCanvas, HINSTANCE currentInstance) : ui(currentInterface), canvas(currentCanvas)
{	
	toolList.push_back(new ShapeTool(ui, BoundingArea::RECT, L"Icon_Rect.bmp", canvas));
	toolList.push_back(new ShapeTool(ui, BoundingArea::CIRCLE, L"Icon_Circle.bmp", canvas));
	toolList.push_back(new ShapeTool(ui, BoundingArea::LINE, L"Icon_Line.bmp", canvas));
	toolList.push_back(new PenTool(ui, L"Icon_Pen.bmp", canvas));
	toolList.push_back(new MoveTool(ui, L"Icon_Move.bmp", canvas));
	toolList.push_back(new DeleteTool(ui, L"Icon_Bin.bmp", canvas));
	toolList.push_back(new SaveTool(ui, L"Icon_Rect.bmp", canvas));
	toolList.push_back(new LoadTool(ui, L"Icon_Rect.bmp", canvas));
	toolList.push_back(new ColourTool(ui, L"Icon_Fill.bmp", canvas, false));
	toolList.push_back(new ColourTool(ui, L"Icon_FillLine.bmp", canvas, true));
	toolList.push_back(new ColourPicker(ui, L"Icon_Fill.bmp", canvas, currentInstance, false));
	toolList.push_back(new ColourPicker(ui, L"Icon_FillLine.bmp", canvas, currentInstance, true));
}


Tools::~Tools()
{
	//delete canvas;
	//delete ui;
	//for_each(toolList.end(), toolList.begin(), [](Tool * tool) {
	//	delete tool;
	//});
}

void Tools::currentToolMovement(int x, int y)
{
	int currentTool = GlobalSettings::getInstance()->getControl();

	if (currentTool >= 0) {
		currentToolID = currentTool;
		toolList.at(currentToolID)->move(x, y);
	}
}

void Tools::currerntToolDown(int x, int y)
{
	if (currentToolID >= 0)
		toolList.at(currentToolID)->onClickDown(x, y);
}

void Tools::currrentToolUp(int x, int y)
{
	if (currentToolID >= 0)
		toolList.at(currentToolID)->onClickUp(x, y);
}

void Tools::renderCurrrentToolIcon()
{
	if (currentToolID >= 0) 
		toolList.at(currentToolID)->renderIcon();
}

void Tools::renderCurrentToolGraphics()
{
	if (currentToolID >= 0) 
		toolList.at(currentToolID)->renderGraphics();
}