#include "ShapeTool.h"



ShapeTool::ShapeTool(EasyGraphics * currentInterface, int shapeType, const wchar_t * iconTexture, Canvas * currentCanvas) : Tool(currentInterface, iconTexture, currentCanvas), shapeType(shapeType)
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
	createShape();
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
		case BoundingArea::RECT:
			drawRect();
			break;
		case BoundingArea::CIRCLE:
			drawCricle();
			break;
		case BoundingArea::LINE:
			drawLine();
			break;
		default:
			break;
		}
	}
}

void ShapeTool::drawRect()
{
	UI->drawRectangle(s[0], s[1], c[0] - s[0], c[1] - s[1], true);
}

void ShapeTool::drawCricle()
{
	UI->drawCircle(s[0], s[1], c[0] - s[0], true);
}

void ShapeTool::drawLine()
{
	UI->drawLine(s[0], s[1], c[0], c[1]);
}

// This will create the shape and add it to the canvas.
void ShapeTool::createShape()
{
	// This stops the drawing of 0px objects 
	if (s[0] != e[0] && s[1] != e[1]) {
		canvas->addToCanvas(s[0], s[1], e[0], e[1], shapeType, GlobalSettings::getInstance()->getFillColour(), GlobalSettings::getInstance()->getOutlineColour());
	}
}

