#include"prey.h"

Prey::~Prey(void)
{
}
Prey::Prey(Prey& a)
{
	img = a.img;
	x = a.x;
	y = a.y;
	dx = a.dx;
	dy = a.dy;
	width = a.width;
	height = a.height;
	winWidth = a.winWidth;
	winHeight = a.winHeight;
}
Prey::Prey(char const* name, int x, int y, int dx, int dy, int w, int h, int winWidth, int winHeight)
{
	loadImage(name, &img);
	width = w;
	height = h;
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->winWidth = winWidth;
	this->winHeight = winHeight;
}
struct rect Prey::getRect()
{
	struct rect r;
	r.x = x;
	r.y = y;
	r.width = width;
	r.height = height;
	return r;
}
void Prey::move()
{
	x += dx;
	y += dy;
	if (x<0 || x> winWidth - width) dx *= -1;
	if (y<0 || y>winHeight - height) dy *= -1;
}
void Prey::draw(int w, int h)
{
	putImageScale(&img, x, y, w, h);
}