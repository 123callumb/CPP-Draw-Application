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
}

void DeleteTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
}
