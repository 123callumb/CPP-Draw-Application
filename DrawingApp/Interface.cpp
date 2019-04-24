#include "Interface.h"
#include "BoundingRect.h"



Interface::Interface(HINSTANCE hInstance)
{
	setImmediateDrawMode(false);

	// Creating stuff here for now
	controls.push_back(Control(this, BoundingRect(0, 100, 68, 55), L"Btn_Shapes.bmp", L"Btn_Shapes_Hover.bmp"));
	controls.push_back(Control(this, BoundingRect(0, 155, 68, 55), L"Btn_Move.bmp", L"Btn_Move_Hover.bmp"));
	controls.push_back(Control(this, BoundingRect(0, 210, 68, 55), L"Btn_Bin.bmp", L"Btn_Bin_Hover.bmp"));
	controls.push_back(Control(this, BoundingRect(0, 265, 68, 55), L"Btn_Save.bmp", L"Btn_Save_Hover.bmp"));
	controls.push_back(Control(this, BoundingRect(0, 320, 68, 55), L"Btn_Load.bmp", L"Btn_Load_Hover.bmp"));
	controls.push_back(Control(this, BoundingRect(0, 375, 68, 55), L"Btn_Fill.bmp", L"Btn_Fill_Hover.bmp"));
	controls.push_back(Control(this, BoundingRect(0, 430, 68, 55), L"Btn_Outline.bmp", L"Btn_Outline_Hover.bmp"));

	create(hInstance, 1024, 720, 120, true);

}


Interface::~Interface()
{
}

void Interface::onCreate()
{
	EasyGraphics::onCreate();
	::SetWindowText(getHWND(), L"Drawing Application");
}

void Interface::onDraw() {
	clrscr(clWhite);
	for (int i = 0; i < controls.size(); i++) {
		controls.at(i).render();
	}
	EasyGraphics::onDraw();

}

void Interface::onMouseMove(UINT nFlags, int x, int y)
{
	for (int i = 0; i < controls.size(); i++) {
		controls.at(i).hover(x, y);
	}
	onDraw();
;}

void Interface::onLButtonDown(UINT nFlags, int x, int y)
{
	for (int i = 0; i < controls.size(); i++) {
		controls.at(i).click(x, y);
	}
	onDraw();
}
