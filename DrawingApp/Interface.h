#pragma once
#include "EasyGraphics.h"
#include "MenuUI.h"
#include "Tools.h"

using namespace std;

class Interface :
	public EasyGraphics
{
public:
	Interface(HINSTANCE hInstance);
	~Interface();
private:
	MenuUI controlMenu;
	Tools tools;

	void onCreate();
	void onDraw();
	void onMouseMove(UINT nFlags, int x, int y);
	void onLButtonDown(UINT nFlags, int x, int y);
	void onLButtonUp(UINT nFlags, int x, int y);
};

