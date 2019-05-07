#include "DeleteTool.h"


DeleteTool::DeleteTool(EasyGraphics * currentInterface, const wchar_t * iconTexture, Canvas * currentCanvas) : Tool(currentInterface, iconTexture, currentCanvas)
{
}

DeleteTool::~DeleteTool()
{
}

void DeleteTool::onClickDown(int x, int y)
{
	if (canvas->shapeExistsAt(x, y)) {
		canvas->deleteShape(canvas->getShapeIndexAt(x, y));
	}
}

void DeleteTool::onClickUp(int x, int y)
{
}

void DeleteTool::renderGraphics()
{
	UI->selectBackColour(UI->clDarkGrey);
	UI->setPenColour(UI->clBlack, 2);
	UI->drawRectangle(0, 0, 200, 30, true);
	UI->selectTextColour(UI->clWhite);
	UI->drawText(L"Click on a shape to delete it.", 5, 5);
	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}

void DeleteTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
}
