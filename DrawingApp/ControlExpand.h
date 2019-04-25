#pragma once
#include "Control.h"
#include <vector>

using namespace std;

class ControlExpand : public Control
{
public:
	ControlExpand(Control initialControl);
	~ControlExpand();
	void addControl(Control* control);
protected:
	void onRender(), onHover(int x, int y), onClick(int x, int y);
private:
	vector<Control*> controlList;
};

