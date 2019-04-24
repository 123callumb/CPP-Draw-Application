#pragma once
#include "EasyGraphics.h"
#include <vector>
#include "Control.h"
using namespace std;



class Interface :
	public EasyGraphics
{
public:
	Interface(HINSTANCE hInstance);
	~Interface();
private:
	vector<Control> controls;

	void onCreate();
	void onDraw();
	void onMouseMove(UINT nFlags, int x, int y);
	void onLButtonDown(UINT nFlags, int x, int y);

};

