#ifndef TRACE_H
#define TRACE_H

#include"settings.h"

namespace Floekr2T
{
	class trace
	{
	public:
		trace();

		//������ʼ��
		void setStartup(f2Point& start);
		f2Point& getStartup();
		f2Point& getNextPoint(int num);
		int getSumPoint();

		//��ӹؼ�֡��
		void addTurningPoint(f2Point& point);

		//�ķ�λ�о� ��ζ��ת������н��������ؾ���
		//��ʱ����ת90��
		void turnLeft(int distance);
		//˳ʱ����ת90��
		void turnRight(int distance);
		//����ԭ����
		void goStraight(int distance);
		//��ת180��
		void goBack(int distance);

	private:
		//��Ǯ��ӵ��ĵ�
		f2Point currentPoint;
		//�յ�����
		//������points.capacity()�൱ ���ǿ��Լ���һ�κ�������
		int sumPoints;
		//��ǰ���н�����
		f2Point direction;

		//·����ʼ��
		//f2Point start;
		//���ڴ�Źյ� ·����ʼ��Ϊ[0]
		vector<f2Point> points;
	};
}

#endif