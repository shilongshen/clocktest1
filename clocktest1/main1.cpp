#include "acllib.h"
#include"Clock.h"
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <math.h>

#define RAD(x) ((x)/360.0*2*3.1415926535)


Clock *c1[1000], *c2[2000];
int s, pos;
void timerEvent(int tid)
{
	beginPaint();
	clearDevice();
	if (s == 0)
	{
		c1[pos]->AddOneS();
		c1[pos]->DrawMyClockWithShape(30, 30, 250, 250);
	}
	else
	{
		c2[pos]->AddOneS();
		c2[pos]->DrawMyClockWithShape(30, 30, 250, 250);
	}
	/*	c2.AddOneS ();
		c2.DrawMyClockWithShape(30,30,250,250);
		c1.AddOneS ();
		c1.DrawMyClockWithShape(430,30,250,250);
		*/
		//s = (s + 1) % 2;
	endPaint();
}

int Setup()
{
	initWindow("Clock", DEFAULT, DEFAULT, 400, 300);

	registerTimerEvent(timerEvent);
	for (int i = 0; i < 1000; ++i)
		c1[i] = new Clock;
	for (int i = 0; i < 2000; ++i)
		c2[i] = new Clock(rectangleShape);

	srand((unsigned)time(NULL));
	s = rand() % 2;

	//s = 0;
	if (s == 0)//ÍÖÔ²
	{
		pos = rand() % 1000;
	}
	else//¾ØÐÎ
	{
		pos = rand() % 2000;
	}
	startTimer(0, 1000);
	//startTimer(0,100);
	//startTimer(0,10);
	//startTimer(0,1);


	return 0;
}
