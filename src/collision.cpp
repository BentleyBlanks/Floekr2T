#include"collision.h"

namespace Floekr2T
{
	void collision::updateAABB(f2Point& position)
	{
		aabb.min.x = position.x + offsetX;
		aabb.min.y = position.y + offsetY;
		aabb.max.x = aabb.min.x + width;
		aabb.max.y = aabb.min.y + height;
	}

	void collision::setAABB(int offsetX, int offsetY, int width, int height)
	{
		this->offsetX = offsetX;
		this->offsetY = offsetY;
		
		this->width = width;
		this->height = height;

		aabb.min.x += offsetX;
		aabb.min.y += offsetY;
		aabb.max.x = aabb.min.x + width;
		aabb.max.y = aabb.min.y + height;
	}

	bool collision::AABBandAABB(Floekr2T::AABB& b)
	{
		if(aabb.max.x<b.min.x||aabb.min.x>b.max.x) return false;
		if(aabb.max.y<b.min.y||aabb.min.y>b.max.y) return false;
		return true;
	}
}