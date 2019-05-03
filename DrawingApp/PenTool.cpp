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

	linePoints.clear();
	held = false;
}

void PenTool::renderGraphics()
{
	if (linePoints.size()) {
		for (int i = 1; i < linePoints.size(); i++) {
			UI->drawLine(linePoints.at(i - 1).x, linePoints.at(i - 1).y, linePoints.at(i).x, linePoints.at(i).y);
		}
	}
}

void PenTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
	if (held) {
		linePoints.push_back({ x, y });
	}
}
