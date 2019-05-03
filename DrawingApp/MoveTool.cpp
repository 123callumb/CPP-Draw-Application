#include "MoveTool.h"



MoveTool::MoveTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas) : Tool(currentInterface, iconName, currentCanvas)
{
}


MoveTool::~MoveTool()
{
}

void MoveTool::onClickDown(int x, int y)
{
	//First we find the element that the mouse is over, this is the element which is on the highest layer. 
	if (canvas->shapeExistsAt(x, y)) {
		shapeID = canvas->getShapeIndexAt(x, y);
		BoundingArea currentShapeBounds = *canvas->getCanvasElements().at(shapeID)->getBoudingArea();
		dxy[0] = currentShapeBounds.getX() - x;
		dxy[1] = currentShapeBounds.getY() - y;
		dxy[2] = currentShapeBounds.getX1() - x;
		dxy[3] = currentShapeBounds.getY1() - y;
	}
}

void MoveTool::onClickUp(int x, int y)
{
	shapeID = -1;
}

void MoveTool::renderGraphics()
{
}

void MoveTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
	
	if (shapeID > -1) {
		canvas->moveShape(shapeID, x, y, dxy);
	}
}
