#pragma once
#include "Element.h"
#include "ControlPanel.h"

using namespace std;

class Control : public Element
{
public:
	Control(EasyGraphics *currentInterface, BoundingArea bArea, ControlPanel * currentPanel,  const wchar_t *filename, const wchar_t *filenameSelected, int ID);
	~Control();
protected:
	bool selected = false;
	const wchar_t *image, *imageHover;
	int controlID; // This is how we identify the action.
	ControlPanel * panel;

	virtual void onClick(int x, int y), onRender(); // Overwriting these from element class.
};


