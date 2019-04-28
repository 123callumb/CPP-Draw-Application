#include "CanvasShape.h"

CanvasShape::CanvasShape(EasyGraphics * currentInterface, BoundingArea * shapeArea, int fillColour, int outlineColour) : Element(currentInterface, shapeArea), fillColour(fillColour), outlineColour(outlineColour)
{
}


CanvasShape::~CanvasShape()
{
}

void CanvasShape::setFillColour(int colour)
{
	fillColour = colour;
}

void CanvasShape::setOutlineColour(int colour)
{
	outlineColour = colour;
}

void CanvasShape::onRender() {
	switch (area->getShapeType())
	{
	case BoundingArea::RECT:
		UI->selectBackColour(fillColour);
		UI->drawRectangle(area->getX(), area->getY(), area->getX1() - area->getX(), area->getY1() - area->getY(), true);
		break;
	case BoundingArea::CIRCLE:
		UI->selectBackColour(fillColour);
		UI->drawCircle(area->getX(), area->getY(), area->getX1() - area->getX(), true);
		break;
	case BoundingArea::LINE:
		UI->setPenColour(fillColour, 1);
		UI->drawLine(area->getX(), area->getY(), area->getX1(), area->getY1());
		break;
	default:
		break;
	}
}

void CanvasShape::onClick(int x, int y)
{
}
