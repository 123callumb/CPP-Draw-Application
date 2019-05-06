#include "CanvasShape.h"

CanvasShape::CanvasShape(EasyGraphics * currentInterface, int x, int y, int x1, int y1, int shapeType, int fillColour, int outlineColour) : Element(currentInterface, x, y, x1, y1, shapeType), fillColour(fillColour), outlineColour(outlineColour)
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


int CanvasShape::getFillColour() {
	return fillColour;
}

int CanvasShape::getOutlineColour()
{
	return outlineColour;
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

	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}

void CanvasShape::onClick(int x, int y)
{
}
