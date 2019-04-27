#include "Element.h"

Element::Element(EasyGraphics * uiTool, BoundingArea bArea) : UI(uiTool), area(bArea), collisionArea(bArea)
{
}

Element::~Element()
{
}
