#include "Control.h"


Control::Control(EasyGraphics * currentInterface, BoundingRect bRect, const wchar_t * filename, const wchar_t * filenameSelected) : Element(currentInterface, bRect), image(filename), imageHover(filenameSelected)
{
}

Control::~Control()
{
}


void Control::onClick(int x, int y)
{
	selected = selected ? 0 : 1; /// er this may work with just !selected
}

void Control::onRender()
{
	UI->drawBitmap((hovering || selected) ? imageHover : image, rect.x, rect.y, rect.w, rect.h, UI->clWhite);
}
