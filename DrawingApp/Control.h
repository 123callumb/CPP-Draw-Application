#pragma once
#include "Element.h"
#include "BoundingRect.h"

using namespace std;

class Control : public Element
{
public:
	Control(EasyGraphics *currentInterface, BoundingRect rect, const wchar_t *filename, const wchar_t *filenameSelected);
	~Control();
	inline void deselect(); 
	inline int getSelected();
protected:
	int selected = 0; // 0 is not selected, 1 is selected It is an int so a button can have more than binary options.
	const wchar_t *image, *imageHover;

	virtual void onClick(int x, int y), onRender(); // Overwriting these from element class.
};

/// Get current controls selected value
inline int Control::getSelected() {
	return selected; 
}

// Deselect the current control, used in menu class for only one control active at one time
inline void Control::deselect() {
	selected = 0; 
}
