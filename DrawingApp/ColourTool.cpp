#include "ColourTool.h"



ColourTool::ColourTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas, int colour) : Tool(currentInterface, iconName, currentCanvas), colour(colour)
{
}


ColourTool::~ColourTool()
{
}

void ColourTool::onClickDown(int x, int y)
{
	if (canvas->shapeExistsAt(x, y)) {
		canvas->fillShape(canvas->getShapeIndexAt(x, y), colour);
	}
}

void ColourTool::onClickUp(int x, int y)
{
}

void ColourTool::renderGraphics()
{
}

void ColourTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
}
