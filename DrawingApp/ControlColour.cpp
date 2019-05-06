#include "ControlColour.h"



ControlColour::ControlColour(EasyGraphics * currentInterface, int x, int y, int x1, int y1, int shapeType, const wchar_t * imageFile, const wchar_t * imageHover, int colour, bool isOutline) : Control(currentInterface, x, y, x1, y1, shapeType, imageFile, imageHover, -1), colour(colour), outline(isOutline)
{
}


ControlColour::~ControlColour()
{
}

void ControlColour::onRender()
{
	UI->drawBitmap((hovering || ((outline ? GlobalSettings::getInstance()->getOutlineColour() : GlobalSettings::getInstance()->getFillColour()) == colour)) ? imageHover : image, area->getX(), area->getY(), area->getX1() - area->getX(), area->getY1() - area->getY(), UI->clWhite);
	UI->selectBackColour(colour);
	UI->setPenColour(UI->clBlack, 1);
	UI->drawRectangle(area->getX() + 17, area->getY() + 12, (area->getX1() - area->getX()) - 34, (area->getY1() - area->getY()) - 25, true);
	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}

void ControlColour::onClick(int x, int y)
{
	if (outline)
		GlobalSettings::getInstance()->setOutlineColour(colour);
	else
		GlobalSettings::getInstance()->setFillColour(colour);
}
