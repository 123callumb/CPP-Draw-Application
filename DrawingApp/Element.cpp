#include "Element.h"

Element::Element(EasyGraphics * uiTool, BoundingRect bRect) : UI(uiTool), rect(bRect), collisionRect(bRect)
{
}

Element::~Element()
{
}
