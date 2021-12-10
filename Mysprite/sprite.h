#pragma once
#include"acllib.h"

class Sprite {
	ACL_Image img;
	int x, y;
	int dx, dy;
	int width, height;
	int winWidth, winHeight;
public:
	Sprite(Sprite& a);
	Sprite(char const* name, int x, int y, int dx, int dy, int w, int h, int winWidth, int winHeight);
	~Sprite();
	virtual void move() = 0;
	void draw(int w, int h);

};