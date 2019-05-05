#pragma once
#include "Control.h"
class ControlColour :
	public Control
{
public:
	ControlColour(Control control, int colour, bool isOutline);
	~ControlColour();
protected: 
	void onRender(), onClick(int x, int y);
private:
	int colour; 
	bool outline = false;
};

