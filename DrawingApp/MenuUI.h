#pragma once
#include "ControlPanel.h"
#include "EasyGraphics.h"
#include <vector>
#include "Control.h"
#include "BoundingArea.h"
#include "ControlExpand.h"
#include "ShapeTool.h"

using namespace std;

// This class is for the side menu.
class MenuUI : public ControlPanel
{
public:
	MenuUI(EasyGraphics *currentUI);
	~MenuUI();
	void onDraw(), clickInteraction(int x, int y), hoverInteraction(int x, int y);
private:
	EasyGraphics *ui;
	vector<Control*> controls;
};

