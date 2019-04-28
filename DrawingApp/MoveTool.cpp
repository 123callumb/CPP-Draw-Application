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
		char debug[100];
		sprintf_s(debug, "ShapeID %d", shapeID);
		OutputDebugStringA(debug);
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
		canvas->moveShape(shapeID, x, y);
	}
}
