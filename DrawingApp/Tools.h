#pragma once
#include <vector>
#include "Tool.h"
#include "EasyGraphics.h"
#include "ShapeTool.h"
#include "Canvas.h"
#include "MoveTool.h"
#include "ColourTool.h"
// This is just a list of all the tools. This class serves as a connector to the menu and the canvas.
using namespace std;

class Tools
{
public:
	Tools(EasyGraphics * currentInterface, Canvas * currentCanvas);
	~Tools();
	void currentToolMovement(int x, int y, int currentTool), currerntToolDown(int x, int y), currrentToolUp(int x, int y), renderCurrrentToolIcon(), renderCurrentToolGraphics();
private:
	int currentToolID = 0;
	EasyGraphics * ui;
	Canvas * canvas;
	vector<Tool*> toolList;
};

