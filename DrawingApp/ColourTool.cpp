#include "ColourTool.h"



ColourTool::ColourTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas, bool outline) : Tool(currentInterface, iconName, currentCanvas), outline(outline)
{
}


ColourTool::~ColourTool()
{
}

void ColourTool::onClickDown(int x, int y)
{
	if (canvas->shapeExistsAt(x, y)) {
		if (outline) {
			canvas->fillOutline(canvas->getShapeIndexAt(x, y)); // thickness is defaultto 2 for now until I implement a thickness meter.
		} else {
			canvas->fillShape(canvas->getShapeIndexAt(x, y));
		}
	}
}

void ColourTool::onClickUp(int x, int y)
{
}

void ColourTool::renderGraphics()
{
	UI->selectBackColour(UI->clDarkGrey);
	UI->setPenColour(UI->clBlack, 2);
	UI->drawRectangle(0, 0, 200, 30, true);
	UI->selectTextColour(UI->clWhite);
	UI->drawText(L"Click a Shape to Fill it in.", 5, 5);
	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}

void ColourTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
}
