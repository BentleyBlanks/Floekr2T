#ifndef COLLISITION_H
#define COLLISITION_H

#include"settings.h"

namespace Floekr2T
{
	//��ײ�й���
	class AABB
	{
	public:
		AABB();
		//�趨��ײ���з�Χ
		void setup(f2Point& min, f2Point& max);

		//��Χ����/��ײ������
		f2Point min;
		f2Point max;
	};
}

#endif