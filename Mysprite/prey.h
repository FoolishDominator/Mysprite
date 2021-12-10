#pragma once
#include"acllib.h"

struct rect
{
	int x, y, width, height;
};
class Prey
{
	ACL_Image img;
	int x, y;//����
	int dx, dy;//�ٶ�
	int width, height;//�ߴ�
	int winWidth, winHeight;
public:
	//Prey(void);
	Prey(Prey&);
	Prey(char const* name, int x, int y, int dx, int dy, int w, int h, int winWidth, int winHeight);
	~Prey(void);
	void move();
	void draw(int w, int h);
	struct rect getRect();
};