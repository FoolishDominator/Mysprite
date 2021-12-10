#include "acllib.h"
#include"prey.h"
#include"hunter.h"
#include <time.h>
const int winWidth = 880, winHeight = 600, width = 100, height = 100;
const int MAXNUM = 10;
Prey* preys[MAXNUM] = { NULL };
Hunter* hunter = NULL;
void timerEvent(int id);
void paintSprites();
void keyEvent(int key, int e);

int Setup()
{
	initWindow("My Window", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));
	int x, y, dx, dy;
	x = rand() % (winWidth - width);
	y = rand() % (winHeight - height);
	dx = dy = 5;
	hunter = new Hunter("tom.bmp", x, y, dx, dy, width, height, winWidth, winHeight);
	registerTimerEvent(timerEvent);
	startTimer(0, 500);
	startTimer(1, 50);
	registerKeyboardEvent(keyEvent);
	paintSprites();
	return 0;
}
void timerEvent(int id)
{
	switch (id)
	{
	case 0://timeid为0：生成猎物
		for (int i = 0; i < MAXNUM; i++) {
			if (preys[i] == NULL) {
				int x, y, dx, dy;
				x = rand() % (winWidth - width);
				y = rand() % (winHeight - height);
				dx = rand() % 5 + 1;
				dy = rand() % 5 + 1;
				preys[i] = new Prey("jerry.bmp", x, y, dx, dy, width, height, winWidth, winHeight);
				break;
			}
		}

		break;
	case 1://timeid为1：更新猎物坐标并画出来
		for (int i = 0; i < MAXNUM; ++i)
			if (preys[i])
				preys[i]->move();

		paintSprites();

		break;
	}
}
void paintSprites()
{
	int i;
	beginPaint();
	clearDevice();
	for (i = 0; i < MAXNUM; ++i)
	{
		if (preys[i])
		{
			preys[i]->draw(width, height);
		}
	}
	hunter->draw(width, height);
	endPaint();
}
void keyEvent(int key, int e)//更新猎人坐标并画出来
{
	if (e != KEY_DOWN)return;
	hunter->keyMove(key);
	for (int i = 0; i < MAXNUM; ++i)
	{
		if (preys[i])
		{
			if (hunter->collision(*preys[i]))
			{
				delete preys[i];
				preys[i] = NULL;
			}
		}
	}
	paintSprites();
}