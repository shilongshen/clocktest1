#pragma once
/*具有时区的时钟类
增加时间增1的功能
增加形状功能
注意：需要重新生成工程类型为win32项目
*/
enum SHAPE { rectangleShape, ellipseShape };
class Clock
{
private:
	int h, m, s, z;
	SHAPE shape;
	void EllipseShape(int x, int y, int width, int height);
	void RectangleShape(int x, int y, int widht, int height);
public:
	//根据电脑时间初始化时钟,缺省是椭圆
	Clock(SHAPE  s = ellipseShape);
	//根据指定时间初始化时钟
	Clock(int z, int h, int m, int s, int shape);
	//根据已经存在的时钟初始化该时钟
	Clock(Clock &);
	~Clock(void);

	//设置时间
	void SetTime(int h, int m, int s);
	//获取时间
	void GetTime(int &h, int &m, int &s);
	//设置时区
	void SetZone(int z);
	//获取时区
	int GetZone();
	//时间增1
	void AddOneS();
	//获取形状,注意：时钟生成后，不能修改形状，所以没有设置形状的函数
	SHAPE GetShape();

	void DispTime();

	void DrawMyClockWithShape(int x, int y, int w, int h);
};

