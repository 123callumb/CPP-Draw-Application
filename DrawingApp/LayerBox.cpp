#include "LayerBox.h"



LayerBox::LayerBox(EasyGraphics * currentInterface, int xPos, int yPos, int shapeType, int layerNumber) : Element(currentInterface, xPos, yPos, xPos+LAYER_W, yPos+LAYER_H, BoundingArea::RECT), shape(shapeType), layerNo(layerNumber)
{
}


LayerBox::~LayerBox()
{
}

void LayerBox::onClickUp(int x, int y)
{
	dragging = false;
}

void LayerBox::onMove(int x, int y)
{
	if (dragging) {
		int y1 = y + dy[0];
		int y2 = y + dy[1];
		area->setY(y1);
		area->setY1(y2);
		collisionArea->setY(y1);
		collisionArea->setY1(y2);
	}
}

void LayerBox::onRender()
{
	UI->selectBackColour(dragging || hovering ? UI->clGrey : UI->clDarkGrey);
	UI->setPenColour(UI->clBlack, 1);
	UI->drawRectangle(area->getX(), area->getY(), LAYER_W, LAYER_H, true);
	UI->selectBackColour(UI->clWhite);
	UI->drawRectangle(area->getX() + 5, area->getY() + 5, LAYER_W - 10, LAYER_H - 10, true);
	UI->selectTextColour(UI->clBlack);
	UI->drawText(shape == 0 ? L"RECT" : shape == 1 ? L"CIRCLE" : shape == 2 ? L"LINE" : L"PEN", area->getX() + 10, area->getY() + 10);
	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}

void LayerBox::onClick(int x, int y)
{
	if (area->isInside(x, y)) {
		dy[0] = area->getY() - y;
		dy[1] = area->getY1() - y;
		dragging = true;
		GlobalSettings::getInstance()->setSelectedLayer(layerNo);
	}
}