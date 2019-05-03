#include "ColourTool.h"



ColourTool::ColourTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas, int colour, bool outline) : Tool(currentInterface, iconName, currentCanvas), colour(colour), outline(outline)
{
}


ColourTool::~ColourTool()
{
}

void ColourTool::onClickDown(int x, int y)
{
	if (canvas->shapeExistsAt(x, y)) {
		if (outline) {
			GlobalSettings::getInstance()->setOutlineColour(colour);
			canvas->fillOutline(canvas->getShapeIndexAt(x, y)); // thickness is defaultto 2 for now until I implement a thickness meter.
		}
		else {
			GlobalSettings::getInstance()->setFillColour(colour);
			canvas->fillShape(canvas->getShapeIndexAt(x, y));
		}
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
