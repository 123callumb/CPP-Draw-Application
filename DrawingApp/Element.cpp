#include "Element.h"

Element::Element(EasyGraphics * uiTool, BoundingArea * bArea) : UI(uiTool), area(bArea)
{
	collisionArea = new BoundingArea(bArea->getX(), bArea->getY(), bArea->getX1(), bArea->getY1(), bArea->getShapeType());
}

Element::~Element()
{
}
