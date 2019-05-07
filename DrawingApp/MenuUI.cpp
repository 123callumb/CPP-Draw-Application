#include "MenuUI.h"

MenuUI::MenuUI(EasyGraphics *currrentUI)  : ui(currrentUI)
{
	// SHAPES BUTTON
	ControlExpand *shapesExpandButton = new ControlExpand(ui, 0, controlH, controlW, controlH*2, BoundingArea::RECT, controlTextures[0], controlTextures[1]);
	for (size_t i = 2; i < 8; i+=2)
		shapesExpandButton->addControl(new Control(ui, controlW * (i/2), controlH, (controlW * (i/2)) + controlW, controlH * 2, BoundingArea::RECT, controlTextures[i], controlTextures[i+1], i/2 - 1));
	controls.push_back(shapesExpandButton); 

	for (size_t i = 8; i < 26; i+=2)
		controls.push_back(new Control(ui, 0, (controlH * ((i/2) -2)), controlW, ((controlH * ((i/2) - 2)) + controlH), BoundingArea::RECT, controlTextures[i], controlTextures[i + 1], i/2 - 1));
}


MenuUI::~MenuUI()
{

}

void MenuUI::onDraw()
{
	for (size_t i = 0; i < controls.size(); i++)
		controls.at(i)->render();

	// Drawing the current chosen colour here, no need for button etc.
	ui->setPenColour(GlobalSettings::getInstance()->getFillColour(), 1);
	ui->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	ui->drawRectangle(20, 509, 28, 27, true);
	ui->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 6);
	ui->drawLine(25, 586, 42, 569);
	ui->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
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

void MenuUI::onClose()
{
	for_each(controls.begin(), controls.end(), [](Control * p) {
		delete p;
	});
	controls.erase(controls.begin(), controls.end());
}

BoundingArea MenuUI::getMenuArea()
{
	return controls.size() ? BoundingArea(controls.at(0)->getBoudingArea()->getX(), controls.at(0)->getBoudingArea()->getY(), controls.at(controls.size() - 1)->getBoudingArea()->getX1(), controls.at(controls.size() - 1)->getBoudingArea()->getY1(), BoundingArea::RECT) : BoundingArea(0, 0, 0, 0, 0);
}


