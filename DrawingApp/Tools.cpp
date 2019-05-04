#include "Tools.h"

Tools::Tools(EasyGraphics * currentInterface, Canvas * currentCanvas) : ui(currentInterface), canvas(currentCanvas)
{	
	ShapeTool * rectTool = new ShapeTool(ui, BoundingArea::RECT, L"Icon_Rect.bmp", canvas);
	ShapeTool * circleTool = new ShapeTool(ui, BoundingArea::CIRCLE, L"Icon_Circle.bmp", canvas);
	ShapeTool * lineTool = new ShapeTool(ui, BoundingArea::LINE, L"Icon_Line.bmp", canvas);

	MoveTool * moveTool = new MoveTool(ui, L"Icon_Move.bmp", canvas);
	
	DeleteTool * deleteTool = new DeleteTool(ui, L"Icon_Bin.bmp", canvas);

	SaveTool * saveTool = new SaveTool(ui, L"Icon_Rect.bmp", canvas);

	LoadTool * loadTool = new LoadTool(ui, L"Icon_Rect.bmp", canvas);

	ColourTool * cyanFillTool = new ColourTool(ui, L"Icon_Fill.bmp", canvas, ui->clCyan, false);
	ColourTool * redFillTool = new ColourTool(ui, L"Icon_Fill.bmp", canvas, ui->clRed, false);
	ColourTool * yellowFillTool = new ColourTool(ui, L"Icon_Fill.bmp", canvas, ui->clYellow, false);

	ColourTool * cyanOutlineTool = new ColourTool(ui, L"Icon_FillLine.bmp", canvas, ui->clCyan, true);
	ColourTool * redOutlineTool = new ColourTool(ui, L"Icon_FillLine.bmp", canvas, ui->clRed, true);
	ColourTool * yellowOutlineTool = new ColourTool(ui, L"Icon_FillLine.bmp", canvas, ui->clYellow, true);

	PenTool * penTool = new PenTool(ui, L"Icon_Pen.bmp", canvas);

	// I could just push these straight back with out doing a varible declare but no point for now.
	toolList.push_back(rectTool);
	toolList.push_back(circleTool);
	toolList.push_back(lineTool);
	toolList.push_back(penTool);
	toolList.push_back(moveTool);
	toolList.push_back(deleteTool);
	toolList.push_back(saveTool);
	toolList.push_back(loadTool);
	toolList.push_back(cyanFillTool);
	toolList.push_back(redFillTool);
	toolList.push_back(yellowFillTool);
	toolList.push_back(cyanOutlineTool);
	toolList.push_back(redOutlineTool);
	toolList.push_back(yellowOutlineTool);
}


Tools::~Tools()
{
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


