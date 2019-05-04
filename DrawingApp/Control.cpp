#include "Control.h"

Control::Control(EasyGraphics *currentInterface, BoundingArea * bArea, const wchar_t *filename, const wchar_t *filenameSelected, int ID) : Element(currentInterface, bArea),  image(filename), imageHover(filenameSelected), controlID(ID)
{
}

Control::~Control()
{
}


void Control::onClick(int x, int y)
{
	GlobalSettings::getInstance()->setControlID(controlID);
}

void Control::onRender()
{ 
	UI->drawBitmap((hovering || (GlobalSettings::getInstance()->getControl() == controlID)) ? imageHover : image, area->getX(), area->getY(), area->getX1() - area->getX(), area->getY1() - area->getY(), UI->clWhite);
}
