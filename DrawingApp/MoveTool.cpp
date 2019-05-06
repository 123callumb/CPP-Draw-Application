#include "MoveTool.h"



MoveTool::MoveTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas) : Tool(currentInterface, iconName, currentCanvas)
{
}


MoveTool::~MoveTool()
{
}

void MoveTool::onClickDown(int x, int y)
{
	//First we find the element that the mouse is over, this is the element which is on the highest layer. 
	bool shiftDown = GlobalSettings::getInstance()->isShiftDown();
	// See if shape exists at point
	if (canvas->shapeExistsAt(x, y)) {
		int shapeIndex = canvas->getShapeIndexAt(x, y);
		// if shift isnt down then clear the selected list and add the current clicked shape.
		if (!shiftDown) {
			selectedItems.clear();	
		}
		
		// Push the item to the selected list. Start with unknown dy/dx as it's updated again later
		SelectData newShape = { shapeIndex, {0, 0, 0, 0} };
		selectedItems.push_back(newShape);

		// Then create the new dy/dx in respect to the new formed bounding area.
		selectedBounds = *canvas->getCanvasElements().at(selectedItems.at(0).id)->getBoudingArea();
		// Add all the bouding boxes together
		for (size_t i = 1; i < selectedItems.size(); i++) {
			BoundingArea currentArea = *canvas->getCanvasElements().at(selectedItems.at(i).id)->getBoudingArea();
			selectedBounds = selectedBounds + currentArea;
		}

	}

	// We then need to update the dy/dx of each shape in relation to the new mouse position
	for (size_t i = 0; i < selectedItems.size(); i++) {
		BoundingArea current = *canvas->getCanvasElements().at(selectedItems.at(i).id)->getBoudingArea();
		SelectData newData = { selectedItems.at(i).id, { current.getX() - x, current.getY() - y, current.getX1() - x, current.getY1() - y } };
		selectedItems.at(i) = newData;
	}


	// Set movingto true
	moving = selectedBounds.isInside(x, y);

}

void MoveTool::onClickUp(int x, int y)
{
	moving = false;
}

void MoveTool::renderGraphics()
{
	// Shift notification in corner
	if (GlobalSettings::getInstance()->isShiftDown()) {
		UI->selectBackColour(UI->clDarkGrey);
		UI->setPenColour(UI->clBlack, 2);
		UI->drawRectangle(0, 0, 240, 30, true);
		UI->selectTextColour(UI->clWhite);
		UI->drawText(L"Shift is down, multiselect mode enabled.", 5, 5);

	}
	else {
		UI->selectBackColour(UI->clDarkGrey);
		UI->setPenColour(UI->clBlack, 2);
		UI->drawRectangle(0, 0, 240, 30, true);
		UI->selectTextColour(UI->clWhite);
		UI->drawText(L"Hold Shift for multi select.", 5, 5);
	}

	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);

	// render selected area around shapes
	UI->setPenColour(UI->clDarkGrey, 1);
	UI->drawLine(selectedBounds.getX() - 10, selectedBounds.getY() - 10, selectedBounds.getX1() + 10, selectedBounds.getY() - 10);
	UI->drawLine(selectedBounds.getX1() + 10, selectedBounds.getY1() + 10, selectedBounds.getX() - 10, selectedBounds.getY1() + 10);
	UI->drawLine(selectedBounds.getX() - 10, selectedBounds.getY() - 10, selectedBounds.getX() - 10, selectedBounds.getY1() + 10);
	UI->drawLine(selectedBounds.getX1() + 10, selectedBounds.getY() - 10, selectedBounds.getX1() + 10, selectedBounds.getY1() + 10);
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}

void MoveTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
	
	if (moving) {
		selectedBounds = BoundingArea(INT_MAX, INT_MAX, 0, 0, BoundingArea::RECT);
		for (size_t i = 0; i < selectedItems.size(); i++) {
			canvas->moveShape(selectedItems.at(i).id, x, y, selectedItems.at(i).dxy);
			// Then update bouding area so the red box follows the moving object,
			selectedBounds = selectedBounds + *canvas->getCanvasElements().at(selectedItems.at(i).id)->getBoudingArea();
		}
	}

}
