#ifndef COLLISION_H
#define COLLISION_H

#include"AABB.h"

namespace Floekr2T
{
	class collision
	{
	public:
		//始终保持更新aabb的位置
		void updateAABB(f2Point& position);

		//设定自定义碰撞区域(沿xy轴位移的距离以及AABB的碰撞区域)
		void setAABB(int offsetX, int offsetY, int width, int height);

		//检测当前AABB碰撞与给定AABB是否碰撞
		bool AABBandAABB(Floekr2T::AABB& b);

		//作用范围的宽高
		int width;
		int height;

		//较给定position的偏移量
		int offsetX, offsetY;

		//碰撞区域
		Floekr2T::AABB aabb;
	};

	//检测量给定AABB是否发生碰撞
	inline bool AABBandAABB(Floekr2T::AABB& a, Floekr2T::AABB& b)
	{
		if(a.max.x<b.min.x||a.min.x>b.max.x) return false;
		if(a.max.y<b.min.y||a.min.y>b.max.y) return false;
		return true;
	}
}

#endif