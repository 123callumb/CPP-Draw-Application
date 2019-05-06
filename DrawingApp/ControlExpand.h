#pragma once
#include "Control.h"
#include <vector>
#include <algorithm>

class ControlExpand : public Control
{
public:
	ControlExpand(EasyGraphics * currentInterface, int x, int y, int x1, int y1, int shapeType, const wchar_t * imageFile, const wchar_t * imageHover);
	~ControlExpand();
	void addControl(Control * subControl);
protected:
	void onRender(), onHover(int x, int y), onClick(int x, int y);
private:
	vector<Control*> controlList;
};

