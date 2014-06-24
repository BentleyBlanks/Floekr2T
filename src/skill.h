#ifndef SKILL_H
#define SKILL_H

#include"settings.h"
#include"defendor.h"
#include"attacker.h"
#include"animation.h"
#include"collision.h"

namespace Floekr2T
{
	class defendor;
	class attacker;

	class skill:public Floekr2T::collision
	{
	public:
		skill(int type, float velocity, float damage, f2Point& position, Floekr2T::attacker* target, Floekr2T::animation& animation);

		void update();

		void draw();

		//保护成员变量
		int getWidth();

		int getHeight();

	//private:
		//释放的技能类型
		int type;
		//释放技能的伤害
		float damage;
		//是否消亡
		bool live;

		//技能运行速率
		float velocity;
		//当前行进的位置
		f2Point position;

		//技能追踪的敌方目标
		Floekr2T::attacker* target;
		//技能释放方向 由target目标来初始化
		f2Point direction;

		//当前技能所需要播放的帧动画
		Floekr2T::animation animation;

	};
}

#endif