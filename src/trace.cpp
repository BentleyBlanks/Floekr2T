#include"trace.h"

namespace Floekr2T
{
	//trace::trace()
	//{
	//	//currentPoint = 0;
	//	sumPoints = -1;
	//	direction.zero();
	//}

	trace::trace()
	{
		//currentPoint = 0;
		//-1�����������Ϊ��
		sumPoints = 0;

		//��ʼ������
		direction.x = 0;
		direction.y = 1;
		direction.z = 0;
	}

	void trace::setStartup(f2Point& start)
	{
		//�ڶӿ�ͷ��ӿ�ʼ�� 
		//��points[0]=start
		points.push_back(start);
		currentPoint = start;
		sumPoints++;
	}

	f2Point& trace::getStartup()
	{
		if(points.size()>0)
			return points[0];
	}

	f2Point& trace::getNextPoint(int num)
	{
		//����������
		return points[num];
	}

	int trace::getSumPoint()
	{
		return sumPoints;
	}

	//��ӹؼ�֡��
	void trace::addTurningPoint(f2Point& point)
	{
		//��β�������µĹյ�
		points.push_back(point);
		
		sumPoints ++;
		////������ʼ��֮���һ����ӽ����Ķ���յ�
		//if(sumPoints == 1)
		//	direction = point - start;

		//�����о�����
		direction = points[sumPoints-1] - points[sumPoints - 2];
	}

	//�ķ�λ�о�
	void trace::turnLeft(int distance)
	{
		//����Z����ת90�� ����2Dƽ������ת
		direction.rotate(-90, f2Point(0, 0, 1));
		direction.normalize();
		direction *= distance;

		//���򲻱� �ȱ�����
		//ͬʱ��ǰ��ӵ��ĵ�Ҳ�Զ��ĸ���Ϊ�����ӵĹյ�
		currentPoint += direction;

		points.push_back(currentPoint);
		sumPoints ++;
	}

	void trace::turnRight(int distance)
	{
		//����Z����ת-90�� ����2Dƽ������ת
		direction.rotate(90, f2Point(0, 0, 1));
		direction.normalize();
		direction *= distance;

		//���򲻱� �ȱ�����
		//ͬʱ��ǰ��ӵ��ĵ�Ҳ�Զ��ĸ���Ϊ�����ӵĹյ�
		currentPoint += direction;

		points.push_back(currentPoint);
		sumPoints ++;
	}

	//����ԭ����
	void trace::goStraight(int distance)
	{
		//f2Point* point = &points[sumPoints-1];

		direction.normalize();
		direction *= distance;

		//���򲻱� �ȱ�����
		//ͬʱ��ǰ��ӵ��ĵ�Ҳ�Զ��ĸ���Ϊ�����ӵĹյ�
		currentPoint += direction;

		points.push_back(currentPoint);
		sumPoints ++;

		////��ʱ�ͷ�
		//delete(point);
	}

	//��ת180��
	void trace::goBack(int distance)
	{
		//����Z����ת180�� ����2Dƽ������ת
		direction.rotate(180, f2Point(0, 0, 1));
		direction.normalize();
		direction *= distance;

		//���򲻱� �ȱ�����
		//ͬʱ��ǰ��ӵ��ĵ�Ҳ�Զ��ĸ���Ϊ�����ӵĹյ�
		currentPoint += direction;

		points.push_back(currentPoint);
		sumPoints ++;
	}
}