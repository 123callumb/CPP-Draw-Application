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


