#include"AABB.h"
namespace Floekr2T
{
	AABB::AABB()
	{
		//��ʼ���������½�
		min.zero();
		max.zero();
	}

	void AABB::setup(f2Point& min, f2Point& max)
	{
		this->min = min;
		this->max = max;
	}
}