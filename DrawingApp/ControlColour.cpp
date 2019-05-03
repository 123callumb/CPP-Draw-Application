#include "ControlColour.h"



ControlColour::ControlColour(Control control, int colour) : Control(control), colour(colour)
{
}


ControlColour::~ControlColour()
{
}

void ControlColour::onRender()
{
	UI->drawBitmap((hovering || (panel->getSelectedControl() == controlID)) ? imageHover : image, area->getX(), area->getY(), area->getX1() - area->getX(), area->getY1() - area->getY(), UI->clWhite);
	UI->selectBackColour(colour);
	UI->setPenColour(UI->clBlack, 1);
	UI->drawRectangle(area->getX() + 17, area->getY() + 12, (area->getX1() - area->getX()) - 34, (area->getY1() - area->getY()) - 25, true);
	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}
