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
	saveFile.open("saveFile.txt");
	if (saveFile.is_open()) {
		vector<CanvasShape*> s = canvas->getCanvasElements();
		saveFile.clear();
		//TODO: itterator here
		for (int i = 0; i < s.size(); i++) {
			saveFile << s.at(i)->getBoudingArea()->getShapeType() << " ";
			saveFile << s.at(i)->getFillColour() << " ";
			saveFile << s.at(i)->getOutlineColour() << " ";
			saveFile << s.at(i)->getBoudingArea()->getX() << " ";
			saveFile << s.at(i)->getBoudingArea()->getY() << " ";
			saveFile << s.at(i)->getBoudingArea()->getX1() << " ";
			saveFile << s.at(i)->getBoudingArea()->getY1() << "\n";
		}
		saveFile.close();
	}
}

void SaveTool::onClickUp(int x, int y)
{
}

void SaveTool::renderGraphics()
{
	UI->selectTextColour(UI->clBlack);
	UI->drawText(L"Click to save file", 0, 0);
}

void SaveTool::onMove(int x, int y)
{
}
