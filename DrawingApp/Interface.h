#pragma once
#include "EasyGraphics.h"
#include "MenuUI.h"
#include "Tools.h"
#include "Canvas.h"
#include "GlobalSettings.h"

using namespace std;

class Interface :
	public EasyGraphics
{
public:
	Interface(HINSTANCE hInstance);
	~Interface();
private:
	HINSTANCE hInst;

	Canvas canvas = Canvas(this);
	MenuUI controlMenu = MenuUI(this);
	Tools tools = Tools(this, &canvas, hInst);

	void onCreate();
	void onDraw();
	void onMouseMove(UINT nFlags, int x, int y);
	void onLButtonDown(UINT nFlags, int x, int y);
	void onLButtonUp(UINT nFlags, int x, int y);
};

