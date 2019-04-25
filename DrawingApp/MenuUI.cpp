#include "MenuUI.h"
#include "ControlExpand.h"



MenuUI::MenuUI(EasyGraphics *currrentUI)  : ui(currrentUI)
{
	// SHAPES BUTTON
	ControlExpand *shapesExpandButton = new ControlExpand(Control(ui, BoundingRect(0, 100, 68, 55), L"Btn_Shapes.bmp", L"Btn_Shapes_Hover.bmp"));
	// BUTTONS INSIDE
	shapesExpandButton->addControl(new Control(ui, BoundingRect(68, 100, 68, 55), L"Btn_Square.bmp", L"Btn_Square_Hover.bmp"));
	shapesExpandButton->addControl(new Control(ui, BoundingRect(136, 100, 68, 55), L"Btn_Circle.bmp", L"Btn_Circle_Hover.bmp"));
	shapesExpandButton->addControl(new Control(ui, BoundingRect(204, 100, 68, 55), L"Btn_Line.bmp", L"Btn_Line_Hover.bmp"));
	controls.push_back(shapesExpandButton);

	// MOVE/TRANSFORM BUTTON
	controls.push_back(new Control(ui, BoundingRect(0, 155, 68, 55), L"Btn_Move.bmp", L"Btn_Move_Hover.bmp"));

	// DELETE BUTTON
	controls.push_back(new Control(ui, BoundingRect(0, 210, 68, 55), L"Btn_Bin.bmp", L"Btn_Bin_Hover.bmp"));

	// SAVE BUTTON
	controls.push_back(new Control(ui, BoundingRect(0, 265, 68, 55), L"Btn_Save.bmp", L"Btn_Save_Hover.bmp"));

	// LOAD BUTTON
	controls.push_back(new Control(ui, BoundingRect(0, 320, 68, 55), L"Btn_Load.bmp", L"Btn_Load_Hover.bmp"));

	// FILL COLOUR BUTTON
	controls.push_back(new Control(ui, BoundingRect(0, 375, 68, 55), L"Btn_Fill.bmp", L"Btn_Fill_Hover.bmp"));

	/// OUTLINE COLOUR BUTTON
	controls.push_back(new Control(ui, BoundingRect(0, 430, 68, 55), L"Btn_Outline.bmp", L"Btn_Outline_Hover.bmp"));
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


