#include "ShapeTool.h"



ShapeTool::ShapeTool(EasyGraphics * currentInterface, int shapeType, const wchar_t * iconTexture) : Tool(currentInterface, iconTexture), shapeType(shapeType)
{
}


ShapeTool::~ShapeTool()
{
}

void ShapeTool::onClickDown(int x, int y)
{
	clickHeld = true;
	s[0] = x;
	s[1] = y;
}

void ShapeTool::onClickUp(int x, int y)
{
	clickHeld = false;
	e[0] = x;
	e[1] = y;
}

void ShapeTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
	c[0] = x;
	c[1] = y;
}


void ShapeTool::renderGraphics() {
	if (clickHeld) {
		switch (shapeType)
		{
		case RECT:
			drawRect();
			break;
		case CIRCLE:
			drawCricle();
			break;
		case LINE:
			drawLine();
			break;
		default:
			break;
		}
	}
}

void ShapeTool::drawRect()
{
	UI->selectBackColour(UI->clBlack);
	UI->drawRectangle(s[0], s[1], clickHeld ? c[0] - s[0] : e[0] - s[0], clickHeld ? c[1] - s[1] : e[1] - s[1], true);
}

void ShapeTool::drawCricle()
{
	UI->selectBackColour(UI->clBlack);
	UI->drawCircle(s[0], s[1], clickHeld ? c[0] - s[0] : e[0] - s[0], true);
}

void ShapeTool::drawLine()
{
	UI->setPenColour(UI->clBlack ,1);
	UI->drawLine(s[0], s[1], clickHeld ? c[0] : e[0] , clickHeld ? c[1]  : e[1]);
}
