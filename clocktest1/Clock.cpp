
#include<iostream>
#include"Clock.h"
#include"acllib.h"
#include"time.h"
#include"math.h"
using namespace std;
Clock::Clock(SHAPE  shape)
{
	time_t t;
	struct tm tmm;
	//h=m=s=0;
	t = time(NULL);
	localtime_s(&tmm, &t);
	h = tmm.tm_hour;
	m = tmm.tm_min;
	s = tmm.tm_sec;
	z = 8;
	this->shape = shape;
}

Clock::~Clock(void)
{
}
//根据指定时间初始化时钟
Clock::Clock(int z, int h, int m, int s, int shape)
{
	this->z = z;
	this->h = h;
	this->m = m;
	this->s = s;
	this->shape;
}
//根据已经存在的时钟初始化该时钟
Clock::Clock(Clock &c)
{
	z = c.z;
	h = c.h;
	m = c.m;
	s = c.s;
	shape = c.shape;
}
//设置时间
void Clock::SetTime(int h, int m, int s)
{
	this->h = h;
	this->m = m;
	this->s = s;
}
//获取时间
void Clock::GetTime(int &h, int &m, int &s)
{
	h = this->h;
	m = this->m;
	s = this->s;
}
//设置时区
void Clock::SetZone(int z)
{
	this->z = z;
}
//获取时区
int Clock::GetZone()
{
	return this->z;
}
void Clock::DispTime()
{
	cout << "时区：" << z << "时间： " << h << ":" << m << ":" << s << endl;
}
void Clock::AddOneS()
{
	s++;
	if (s >= 60)
	{
		m++;
		s = 0;
		if (m >= 60)
		{
			m = 0;
			h++;
			if (h >= 12)
			{
				h = 0;
			}
		}
	}
}
//下面的椭圆绘制来自于acllib的samples
double RAD(double x)
{
	return ((x) / 360.0 * 2 * 3.1415926535);
}
void Clock::DrawMyClockWithShape(int x, int y, int width, int height)
{
	switch (shape)
	{
	case ellipseShape: EllipseShape(x, y, width, height);
		break;
	case rectangleShape:RectangleShape(x, y, width, height);
		break;
	}
}
SHAPE Clock::GetShape()
{
	return shape;
}
void Clock::EllipseShape(int x, int y, int width, int height)
{
	int ox = x + width / 2;//150;
	int oy = y + height / 2;//150;

	int min = width < height ? width : height;
	int hl = min / 4 - min / 7;//46;
	int ml = min / 3 - min / 6;//74;
	int sl = min / 2 - min / 5;//120;

	int i;



	//	beginPaint();

	//	clearDevice();

		// circle
	setPenWidth(2);
	setPenColor(BLACK);
	setBrushColor(WHITE);
	ellipse(x, y, x + width, y + height);

	// label
	setPenWidth(1);
	setPenColor(BLACK);
	int len1 = min / 2 - min / 8, len2 = len1 + 10;
	for (i = 0; i < 12; ++i)
	{
		moveTo(ox + len1*sin(RAD(180 - i * 30)), oy + len1*cos(RAD(180 - i * 30)));
		lineTo(ox + len2*sin(RAD(180 - i * 30)), oy + len2*cos(RAD(180 - i * 30)));
	}

	// hour
	setPenWidth(8);
	setPenColor(BLACK);
	moveTo(ox, oy);
	lineTo(ox + hl*sin(RAD(180 - h * 30)), oy + hl*cos(RAD(180 - h * 30)));

	// minute
	setPenWidth(4);
	setPenColor(GREEN);
	moveTo(ox, oy);
	lineTo(ox + ml*sin(RAD(180 - m * 6)), oy + ml*cos(RAD(180 - m * 6)));

	// second
	setPenWidth(2);
	setPenColor(RED);
	moveTo(ox, oy);
	lineTo(ox + sl*sin(RAD(180 - s * 6)), oy + sl*cos(RAD(180 - s * 6)));

	//	endPaint();

}
void Clock::RectangleShape(int x, int y, int width, int height)
{
	int ox = x + width / 2;//150;
	int oy = y + height / 2;//150;

	int min = width < height ? width : height;
	int hl = min / 4 - min / 7;//46;
	int ml = min / 3 - min / 6;//74;
	int sl = min / 2 - min / 5;//120;

	int i;



	//	beginPaint();

	//	clearDevice();

		// circle
	setPenWidth(2);
	setPenColor(BLACK);
	setBrushColor(WHITE);
	rectangle(x, y, x + width, y + height);

	// label
	setPenWidth(1);
	setPenColor(BLACK);
	int len1 = min / 2 - min / 8, len2 = len1 + 10;
	for (i = 0; i < 12; ++i)
	{
		moveTo(ox + len1*sin(RAD(180 - i * 30)), oy + len1*cos(RAD(180 - i * 30)));
		lineTo(ox + len2*sin(RAD(180 - i * 30)), oy + len2*cos(RAD(180 - i * 30)));
	}

	// hour
	setPenWidth(8);
	setPenColor(BLACK);
	moveTo(ox, oy);
	lineTo(ox + hl*sin(RAD(180 - h * 30)), oy + hl*cos(RAD(180 - h * 30)));

	// minute
	setPenWidth(4);
	setPenColor(GREEN);
	moveTo(ox, oy);
	lineTo(ox + ml*sin(RAD(180 - m * 6)), oy + ml*cos(RAD(180 - m * 6)));

	// second
	setPenWidth(2);
	setPenColor(RED);
	moveTo(ox, oy);
	lineTo(ox + sl*sin(RAD(180 - s * 6)), oy + sl*cos(RAD(180 - s * 6)));

	//	endPaint();
}