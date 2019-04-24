#pragma once
#include "Element.h"
#include "BoundingRect.h"

using namespace std;

class Control : public Element
{
public:
	Control(EasyGraphics *currentInterface, BoundingRect rect, const wchar_t *filename, const wchar_t *filenameSelected);
	~Control();
protected:
	void onClick(), onRender(); // Overwriting these from element class.
private: 
	bool selected = false;
	const wchar_t *image, *imageHover;
};

