#include "Control.h"

Control::Control(EasyGraphics *currentInterface, BoundingArea * bArea, ControlPanel * currentPanel, const wchar_t *filename, const wchar_t *filenameSelected, int ID) : Element(currentInterface, bArea), panel(currentPanel),  image(filename), imageHover(filenameSelected), controlID(ID)
{
}

Control::~Control()
{
}


void Control::onClick(int x, int y)
{
	panel->setSelectedControl(controlID);
}

void Control::onRender()
{ 
	UI->drawBitmap((hovering || (panel->getSelectedControl() == controlID)) ? imageHover : image, area->getX(), area->getY(), area->getX1() - area->getX(), area->getY1() - area->getY(), UI->clWhite);
}
