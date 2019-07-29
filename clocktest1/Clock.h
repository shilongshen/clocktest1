#pragma once
/*����ʱ����ʱ����
����ʱ����1�Ĺ���
������״����
ע�⣺��Ҫ�������ɹ�������Ϊwin32��Ŀ
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
	//���ݵ���ʱ���ʼ��ʱ��,ȱʡ����Բ
	Clock(SHAPE  s = ellipseShape);
	//����ָ��ʱ���ʼ��ʱ��
	Clock(int z, int h, int m, int s, int shape);
	//�����Ѿ����ڵ�ʱ�ӳ�ʼ����ʱ��
	Clock(Clock &);
	~Clock(void);

	//����ʱ��
	void SetTime(int h, int m, int s);
	//��ȡʱ��
	void GetTime(int &h, int &m, int &s);
	//����ʱ��
	void SetZone(int z);
	//��ȡʱ��
	int GetZone();
	//ʱ����1
	void AddOneS();
	//��ȡ��״,ע�⣺ʱ�����ɺ󣬲����޸���״������û��������״�ĺ���
	SHAPE GetShape();

	void DispTime();

	void DrawMyClockWithShape(int x, int y, int w, int h);
};

