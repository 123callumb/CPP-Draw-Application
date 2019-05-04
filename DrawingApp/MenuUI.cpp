#include "MenuUI.h"

MenuUI::MenuUI(EasyGraphics *currrentUI)  : ui(currrentUI)
{
	// SHAPES BUTTON
	ControlExpand *shapesExpandButton = new ControlExpand(Control(ui, new BoundingArea(0, controlH, controlW, controlH*2, BoundingArea::RECT), controlTextures[0], controlTextures[1], -1));
	for (size_t i = 2; i < 8; i+=2)
		shapesExpandButton->addControl(new Control(ui, new BoundingArea(controlW * (i/2), controlH, (controlW * (i/2)) + controlW, controlH * 2, BoundingArea::RECT), controlTextures[i], controlTextures[i+1], i/2 - 1));
	controls.push_back(shapesExpandButton); 

	for (size_t i = 8; i < 22; i+=2)
		controls.push_back(new Control(ui, new BoundingArea(0, (controlH * ((i/2) -2)), controlW, ((controlH * ((i/2) - 2)) + controlH), BoundingArea::RECT), controlTextures[i], controlTextures[i + 1], i/2 - 1));
}


MenuUI::~MenuUI()
{
}

void MenuUI::onDraw()
{
	for (size_t i = 0; i < controls.size(); i++)
		controls.at(i)->render();
}

// Add click interactions to control buttons
void MenuUI::clickInteraction(int x, int y)
{
	for (size_t i = 0; i < controls.size(); i++)
		controls.at(i)->click(x, y);
}

// Add hover interation to control buttons
void MenuUI::hoverInteraction(int x, int y)
{
	for (size_t i = 0; i < controls.size(); i++)
		controls.at(i)->hover(x, y);
}


