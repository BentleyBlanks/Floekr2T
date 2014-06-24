#include"skill.h"
namespace Floekr2T
{
	skill::skill(int type, float velocity, float damage, f2Point& position, Floekr2T::attacker* target, Floekr2T::animation& animation)
		:type(type), velocity(velocity), damage(damage), position(position), target(target), animation(animation)
	{
		//由target目标来初始化位置和运动方向
		direction = target->aabb.min - position;
		direction.normalize();

		live = true;

		////默认宽高为第一张起始帧动画宽高
		//width = animation.pictures[0].width;
		//height = animation.pictures[0].height;
		////默认AABB
		//aabb.min = position;
		//aabb.max.x = position.x + width;
		//aabb.max.y = position.y + height;

		//默认宽高为第一张起始帧动画宽高
		//默认没有偏移
		setAABB(0, 0, animation.pictures[0].width, animation.pictures[0].height);
	}

	void skill::update()
	{
		//根据技能类型来更新位置信息
		switch (type)
		{
		case TRACK:
			//追踪目标
			//实时根据目标点更新运动方向
			direction = target->aabb.min - position;
			direction.normalize();

			//放大倍数为速率
			direction *= velocity;

			//更新位置
			position += direction;
			break;

		case PATH:
			//与Track不同的是 Path的技能只会根据自身的运动方向行动 而不会根据target时时变化 target只是用于初始化释放方向
			direction.normalize();
			direction *= velocity;

			//更新位置
			position += direction;
			break;

		case SCOPE:
			//直接对range范围内的地方受到一定程度的伤害
			//由于此技能类型只存在与逻辑上 所以病不需要进行更新……因为根本不会创建
			break;
		}
		updateAABB(position);
	}

	void skill::draw()
	{
		animation.drawCurrentFrame(position);
	}

	int skill::getWidth()
	{
		return width;
	}

	int skill::getHeight()
	{
		return height;
	}
}
