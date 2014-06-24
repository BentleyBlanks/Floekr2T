#ifndef COLLISITION_H
#define COLLISITION_H

#include"settings.h"

namespace Floekr2T
{
	//碰撞盒管理
	class AABB
	{
	public:
		AABB();
		//设定碰撞检测盒范围
		void setup(f2Point& min, f2Point& max);

		//包围矩形/碰撞检测矩形
		f2Point min;
		f2Point max;
	};
}

#endif