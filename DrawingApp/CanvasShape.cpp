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

void CanvasShape::setOutlineColour(int colour, int thickness)
{
	outlineColour = colour;
	lineThickness = thickness;
}

void CanvasShape::onRender() {

	// Set colours
	UI->selectBackColour(fillColour);
	UI->setPenColour(outlineColour, lineThickness);

	// Draw object
	switch (area->getShapeType())
	{
	case BoundingArea::RECT:
		UI->drawRectangle(area->getX(), area->getY(), area->getX1() - area->getX(), area->getY1() - area->getY(), true);
		break;
	case BoundingArea::CIRCLE:
		UI->drawCircle(area->getX(), area->getY(), area->getX1() - area->getX(), true);
		break;
	case BoundingArea::LINE:
		UI->drawLine(area->getX(), area->getY(), area->getX1(), area->getY1());
		break;
	default:
		break;
	}

	// set it back to normal after this
	UI->selectBackColour(UI->clBlack);
	UI->setPenColour(UI->clBlack, 1);
}

void CanvasShape::onClick(int x, int y)
{
}
