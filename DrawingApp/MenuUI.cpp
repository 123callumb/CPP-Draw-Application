#include "MenuUI.h"

MenuUI::MenuUI(EasyGraphics *currrentUI)  : ui(currrentUI)
{
	// SHAPES BUTTON
	Control shapesButton = Control(ui, BoundingArea(0, 100, 68, 155, ShapeTool::RECT), this, L"Btn_Shapes.bmp", L"Btn_Shapes_Hover.bmp", -1); // -1 because it does not serve a function
	ControlExpand *shapesExpandButton = new ControlExpand(shapesButton);
	// BUTTONS INSIDE
	shapesExpandButton->addControl(new Control(ui, BoundingArea(68, 100, 134, 155, ShapeTool::RECT), this, L"Btn_Square.bmp", L"Btn_Square_Hover.bmp", 0));
	shapesExpandButton->addControl(new Control(ui, BoundingArea(134, 100, 202, 155, ShapeTool::RECT), this, L"Btn_Circle.bmp", L"Btn_Circle_Hover.bmp", 1));
	shapesExpandButton->addControl(new Control(ui, BoundingArea(202, 100, 270, 155, ShapeTool::RECT), this, L"Btn_Line.bmp", L"Btn_Line_Hover.bmp", 2));
	controls.push_back(shapesExpandButton); 
	
	// MOVE/TRANSFORM BUTTON
	controls.push_back(new Control(ui, BoundingArea(0, 155, 68, 210, ShapeTool::RECT), this, L"Btn_Move.bmp", L"Btn_Move_Hover.bmp", 3));

	// DELETE BUTTON
	controls.push_back(new Control(ui, BoundingArea(0, 210, 68, 265, ShapeTool::RECT), this, L"Btn_Bin.bmp", L"Btn_Bin_Hover.bmp", 4));

	// SAVE BUTTON
	controls.push_back(new Control(ui, BoundingArea(0, 265, 68, 320, ShapeTool::RECT), this, L"Btn_Save.bmp", L"Btn_Save_Hover.bmp", 5));

	// LOAD BUTTON
	controls.push_back(new Control(ui, BoundingArea(0, 320, 68, 375, ShapeTool::RECT), this, L"Btn_Load.bmp", L"Btn_Load_Hover.bmp", 6));

	// FILL COLOUR BUTTON
	controls.push_back(new Control(ui, BoundingArea(0, 375, 68, 430, ShapeTool::RECT), this, L"Btn_Fill.bmp", L"Btn_Fill_Hover.bmp", -1));

	/// OUTLINE COLOUR BUTTON
	controls.push_back(new Control(ui, BoundingArea(0, 430, 68, 485, ShapeTool::RECT), this, L"Btn_Outline.bmp", L"Btn_Outline_Hover.bmp", -1));

	
}


MenuUI::~MenuUI()
{
}

void MenuUI::onDraw()
{
	for (int i = 0; i < controls.size(); i++) {
		controls.at(i)->render();
	}
}

// Add click interactions to control buttons
void MenuUI::clickInteraction(int x, int y)
{
	for (int i = 0; i < controls.size(); i++) {
		controls.at(i)->click(x, y);
	}
}

// Add hover interation to control buttons
void MenuUI::hoverInteraction(int x, int y)
{
	for (int i = 0; i < controls.size(); i++) {
		controls.at(i)->hover(x, y);
	}
}


