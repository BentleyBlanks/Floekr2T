#ifndef COLLISION_H
#define COLLISION_H

#include"AABB.h"

namespace Floekr2T
{
	class collision
	{
	public:
		//ʼ�ձ��ָ���aabb��λ��
		void updateAABB(f2Point& position);

		//�趨�Զ�����ײ����(��xy��λ�Ƶľ����Լ�AABB����ײ����)
		void setAABB(int offsetX, int offsetY, int width, int height);

		//��⵱ǰAABB��ײ�����AABB�Ƿ���ײ
		bool AABBandAABB(Floekr2T::AABB& b);

		//���÷�Χ�Ŀ��
		int width;
		int height;

		//�ϸ���position��ƫ����
		int offsetX, offsetY;

		//��ײ����
		Floekr2T::AABB aabb;
	};

	//���������AABB�Ƿ�����ײ
	inline bool AABBandAABB(Floekr2T::AABB& a, Floekr2T::AABB& b)
	{
		if(a.max.x<b.min.x||a.min.x>b.max.x) return false;
		if(a.max.y<b.min.y||a.min.y>b.max.y) return false;
		return true;
	}
}

#endif