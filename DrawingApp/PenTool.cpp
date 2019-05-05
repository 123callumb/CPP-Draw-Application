#include "PenTool.h"



PenTool::PenTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas) : Tool(currentInterface, iconName, currentCanvas)
{

}


PenTool::~PenTool()
{
}

void PenTool::onClickDown(int x, int y)
{
	held = true;
}

void PenTool::onClickUp(int x, int y)
{
	if (bX) { // BX is 0 when no points are added,  so theres no need to call this method.
		canvas->addScribble(linePoints, new BoundingArea(sX, sY, bX, bY, BoundingArea::SCRIBBLE), GlobalSettings::getInstance()->getOutlineColour());
		linePoints.clear();
	}
	sX = INT_MAX;
	sY = INT_MAX;
	bX = 0;
	bY = 0;
	held = false;
}

void PenTool::renderGraphics()
{
	if (linePoints.size()) {
		// TODO: itterator here
		for (int i = 1; i < linePoints.size(); i++) {
			UI->drawLine(linePoints.at(i - 1).x, linePoints.at(i - 1).y, linePoints.at(i).x, linePoints.at(i).y);
		}
	}
}

void PenTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
	if (held) {
		sX = sX < x ? sX : x;
		sY = sY < y ? sY : y;
		bX = bX > x ? bX : x;
		bY = bY > y ? bY : y;
		linePoints.push_back({ x, y });
	}
}
