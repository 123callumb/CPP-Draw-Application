#pragma once
#include <vector>
#include <algorithm>
#include "Tool.h"
#include "EasyGraphics.h"
#include "ShapeTool.h"
#include "Canvas.h"
#include "MoveTool.h"
#include "ColourTool.h"
#include "DeleteTool.h"
#include "SaveTool.h"
#include "LoadTool.h"
#include "PenTool.h"
#include "GlobalSettings.h"
#include "ColourPicker.h"
// This is just a list of all the tools. This class serves as a connector to the menu and the canvas.
using namespace std;

class Tools
{
public:
	Tools(EasyGraphics * currentInterface, Canvas * currentCanvas, HINSTANCE currentInstance);
	~Tools();
	void currentToolMovement(int x, int y), currerntToolDown(int x, int y), currrentToolUp(int x, int y), renderCurrrentToolIcon(), renderCurrentToolGraphics(), onClose();
private:
	int currentToolID = 0;
	EasyGraphics * ui;
	Canvas * canvas;
	vector<Tool*> toolList;

};

