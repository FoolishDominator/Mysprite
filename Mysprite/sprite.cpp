#include"sprite.h"

Sprite::Sprite(Sprite& a) {
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

Sprite::Sprite(char const* name, int x, int y, int dx, int dy, int w, int h, int winWidth, int winHeight) {
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

Sprite::~Sprite()
{
}

void Sprite::move() {

}

void Sprite::draw(int w, int h) {

}