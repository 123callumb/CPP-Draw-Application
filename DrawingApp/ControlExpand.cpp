#include "ControlExpand.h"


ControlExpand::ControlExpand(Control initialControl) : Control(initialControl)
{
}

ControlExpand::~ControlExpand()
{
}

void ControlExpand::addControl(Control * subControl)
{
	collisionArea->setX1(subControl->getBoudingArea()->getX1());
	controlList.push_back(subControl);
}

void ControlExpand::onRender()
{
	// Draw initial button
	UI->drawBitmap((hovering || selected) ? imageHover : image, area->getX(), area->getY(), area->getX1() - area->getX(), area->getY1() - area->getY(), UI->clWhite);
	// Then draw the additional buttons if currently hovering.
	if (hovering || selected) {
		// CHANGE THIS TO STL ITTERATOR
		for (int i = 0; i < controlList.size(); i++) {
			controlList.at(i)->render();
		}
	}
}


// This is an virtual function that is stored in element that we can use to add interaction to our controls inside this class.
void ControlExpand::onHover(int x, int y)
{
		// CHANGE THIS TO STL ITTERATOR
		for (int i = 0; i < controlList.size(); i++) {
			controlList.at(i)->hover(x, y);
		}
}

void ControlExpand::onClick(int x, int y)
{
	// CHANGE THIS TO STL ITTERATOR
	for (int i = 0; i < controlList.size(); i++) {
		controlList.at(i)->click(x, y);
	}
}
