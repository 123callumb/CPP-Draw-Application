#pragma once
// This class is for the side menu.
#include "Control.h"
#include <vector>
#include "EasyGraphics.h"
#include "BoundingRect.h"

class MenuUI
{
public:
	MenuUI(EasyGraphics *currentUI);
	~MenuUI();
	void onDraw(), clickInteraction(int x, int y), hoverInteraction(int x, int y);
private:
	EasyGraphics *ui;
	vector<Control*> controls;
};

