#include "MenuUI.h"

MenuUI::MenuUI(EasyGraphics *currrentUI)  : ui(currrentUI)
{
	// SHAPES BUTTON
	Control shapesButton = Control(ui,new BoundingArea(0, 100, 68, 155, BoundingArea::RECT), this, L"Btn_Shapes.bmp", L"Btn_Shapes_Hover.bmp", -1); // -1 because it does not serve a function
	ControlExpand *shapesExpandButton = new ControlExpand(shapesButton);
	// BUTTONS INSIDE
	shapesExpandButton->addControl(new Control(ui, new BoundingArea(68, 100, 134, 155, BoundingArea::RECT), this, L"Btn_Square.bmp", L"Btn_Square_Hover.bmp", 0));
	shapesExpandButton->addControl(new Control(ui, new BoundingArea(134, 100, 202, 155, BoundingArea::RECT), this, L"Btn_Circle.bmp", L"Btn_Circle_Hover.bmp", 1));
	shapesExpandButton->addControl(new Control(ui, new BoundingArea(202, 100, 270, 155, BoundingArea::RECT), this, L"Btn_Line.bmp", L"Btn_Line_Hover.bmp", 2));
	controls.push_back(shapesExpandButton); 
	
	// MOVE/TRANSFORM BUTTON
	controls.push_back(new Control(ui, new BoundingArea(0, 155, 68, 210, BoundingArea::RECT), this, L"Btn_Move.bmp", L"Btn_Move_Hover.bmp", 3));

	// DELETE BUTTON
	controls.push_back(new Control(ui, new BoundingArea(0, 210, 68, 265, BoundingArea::RECT), this, L"Btn_Bin.bmp", L"Btn_Bin_Hover.bmp", 4));

	// SAVE BUTTON
	controls.push_back(new Control(ui, new BoundingArea(0, 265, 68, 320, BoundingArea::RECT), this, L"Btn_Save.bmp", L"Btn_Save_Hover.bmp", 5));

	// LOAD BUTTON
	controls.push_back(new Control(ui, new BoundingArea(0, 320, 68, 375, BoundingArea::RECT), this, L"Btn_Load.bmp", L"Btn_Load_Hover.bmp", 6));

	// FILL COLOUR BUTTON
	ControlExpand *fillExpandButton = new ControlExpand(Control(ui, new BoundingArea(0, 375, 68, 430, BoundingArea::RECT), this, L"Btn_Fill.bmp", L"Btn_Fill_Hover.bmp", -1));
	fillExpandButton->addControl(new ControlColour(Control(ui, new BoundingArea(68, 375, 134, 430, BoundingArea::RECT), this, L"Btn_Square.bmp" , L"Btn_Square_Hover.bmp", 7), EasyGraphics::clCyan));
	fillExpandButton->addControl(new ControlColour(Control(ui, new BoundingArea(134, 375, 202, 430, BoundingArea::RECT), this, L"Btn_Square.bmp", L"Btn_Square_Hover.bmp", 8), EasyGraphics::clRed));
	fillExpandButton->addControl(new ControlColour(Control(ui, new BoundingArea(202, 375, 270, 430, BoundingArea::RECT), this, L"Btn_Square.bmp", L"Btn_Square_Hover.bmp", 9), EasyGraphics::clYellow));
	controls.push_back(fillExpandButton);

	/// OUTLINE COLOUR BUTTON
	ControlExpand *lineExpandButton = new ControlExpand(Control(ui, new BoundingArea(0, 430, 68, 485, BoundingArea::RECT), this, L"Btn_Outline.bmp", L"Btn_Outline_Hover.bmp", -1));
	lineExpandButton->addControl(new ControlColour(Control(ui, new BoundingArea(68, 430, 134, 485, BoundingArea::RECT), this, L"Btn_Square.bmp", L"Btn_Square_Hover.bmp", 10), EasyGraphics::clCyan));
	lineExpandButton->addControl(new ControlColour(Control(ui, new BoundingArea(134, 430, 202, 485, BoundingArea::RECT), this, L"Btn_Square.bmp", L"Btn_Square_Hover.bmp", 11), EasyGraphics::clRed));
	lineExpandButton->addControl(new ControlColour(Control(ui, new BoundingArea(202, 430, 270, 485, BoundingArea::RECT), this, L"Btn_Square.bmp", L"Btn_Square_Hover.bmp", 12), EasyGraphics::clYellow));
	controls.push_back(lineExpandButton);

	
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


