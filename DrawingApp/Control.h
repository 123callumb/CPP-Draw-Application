#pragma once
#include "Element.h"
#include "GlobalSettings.h"

using namespace std;

class Control : public Element
{
public:
	Control(EasyGraphics *currentInterface, BoundingArea * bArea, const wchar_t *filename, const wchar_t *filenameSelected, int ID);
	~Control();
protected:
	bool selected = false;
	const wchar_t *image, *imageHover;
	int controlID; // This is how we identify the action.

	virtual void onClick(int x, int y), onRender(); // Overwriting these from element class.
};

inline Control::Control(EasyGraphics *currentInterface, BoundingArea * bArea, const wchar_t *filename, const wchar_t *filenameSelected, int ID) : Element(currentInterface, bArea), image(filename), imageHover(filenameSelected), controlID(ID)
{
}

inline Control::~Control()
{
}


inline void Control::onClick(int x, int y)
{
	GlobalSettings::getInstance()->setControlID(controlID);
}

inline void Control::onRender()
{
	UI->drawBitmap((hovering || (GlobalSettings::getInstance()->getControl() == controlID)) ? imageHover : image, area->getX(), area->getY(), area->getX1() - area->getX(), area->getY1() - area->getY(), UI->clWhite);
}
