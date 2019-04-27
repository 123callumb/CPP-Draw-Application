#pragma once
#include "Control.h"
#include <vector>

class ControlExpand : public Control
{
public:
	ControlExpand(Control initialControl);
	~ControlExpand();
	void addControl(Control * subControl);
protected:
	void onRender(), onHover(int x, int y), onClick(int x, int y);
private:
	vector<Control*> controlList;
};

