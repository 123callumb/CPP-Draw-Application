#pragma once
#include "Control.h"
class ControlColour :
	public Control
{
public:
	ControlColour(Control control, int colour);
	~ControlColour();
protected: 
	void onRender();
private:
	int colour; 
};

