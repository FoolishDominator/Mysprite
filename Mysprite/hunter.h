#pragma once
#include"acllib.h"
#include"prey.h"

class Hunter
{
	ACL_Image img;
	int x, y;
	int dx, dy;
	int width, height;
	int winWidth, winHeight;
public:
	Hunter(Hunter&);
	Hunter(char const* name, int x, int y, int dx, int dy, int w, int h, int winWidth, int winHeight);
	~Hunter(void);

	void keyMove(int key);
	int collision(Prey& a);
	void draw(int w, int h);
};