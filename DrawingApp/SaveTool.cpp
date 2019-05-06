#include "SaveTool.h"



SaveTool::SaveTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas) : Tool(currentInterface, iconName, currentCanvas)
{
}


SaveTool::~SaveTool()
{
}

void SaveTool::onClickDown(int x, int y)
{
	OutputDebugStringW(L"Calling Save method");
	// Save to file function
	ofstream saveFile;

	ios_base::iostate exceptionMask = saveFile.exceptions() | ios::failbit; 
	saveFile.exceptions(exceptionMask);

	try {
		saveFile.open("saveFile.txt");
		if (!saveFile.fail() && saveFile.is_open()) {
			vector<CanvasShape*> s = canvas->getCanvasElements();
			saveFile.clear();
			//TODO: itterator here
			for (size_t i = 0; i < s.size(); i++) {
				saveFile << s.at(i)->getBoudingArea()->getShapeType() << " ";
				saveFile << s.at(i)->getFillColour() << " ";
				saveFile << s.at(i)->getOutlineColour() << " ";
				saveFile << s.at(i)->getBoudingArea()->getX() << " ";
				saveFile << s.at(i)->getBoudingArea()->getY() << " ";
				saveFile << s.at(i)->getBoudingArea()->getX1() << " ";
				saveFile << s.at(i)->getBoudingArea()->getY1() << " ";
				// If the rest of the shape is a scribble then store all the line points after it.
				if (s.at(i)->getBoudingArea()->getShapeType() == BoundingArea::SCRIBBLE) {
					vector<CanvasScribble::Point> scribPoints = dynamic_cast<CanvasScribble*>(s.at(i))->getPoints();
					saveFile << scribPoints.size() << " "; // Store the amount of points so loading the file is easier.
					for (int p = 0; p < scribPoints.size(); p++) {
						saveFile << scribPoints.at(p).x + s.at(i)->getBoudingArea()->getX() << " " << scribPoints.at(p).y + s.at(i)->getBoudingArea()->getY() << " ";
					}
				}
				saveFile << "\n";
			}
			saveFile.close();
		}
		else {
			error = true;
		}
	}
	catch (ios_base::failure) {
		error = true;
	}
		
}

void SaveTool::onClickUp(int x, int y)
{

}

void SaveTool::renderGraphics()
{
	UI->selectBackColour(UI->clDarkGrey);
	UI->setPenColour(UI->clBlack, 2);
	UI->drawRectangle(0, 0, 200, 30, true);
	UI->selectTextColour(UI->clWhite);
	UI->drawText(!error ? L"Click Canvas to Save File" : L"There was a problem saving the file.", 5, 5);
	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}

void SaveTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
}
