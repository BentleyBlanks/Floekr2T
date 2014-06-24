#ifndef ATTACKER_H
#define ATTACKER_H

#include"settings.h"
#include"trace.h"
#include"animation.h"
#include"skill.h"
#include"collision.h"

namespace Floekr2T
{
	class skill;

	class attacker:public Floekr2T::collision
	{
	public:
		attacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation);

		//判定与技能群的位置关系 返回存活信息
		bool update(vector<Floekr2T::skill>& skills);

		void draw();

		//保护成员变量
		float getHP();

		int getWidth();

		int getHeight();

	//private:
		//是否存活着
		bool live;
		//是否完成行进
		bool completeWalk;

		//行进的路径
		Floekr2T::trace trace;
		//当前行进到的点
		int currentPoint;

		//攻击者的位置信息
		f2Point position;

		//运动速率
		int velocity;
		
		//血量
		float HP;

		//运动方向
		f2Point direction;
		//帧动画
		Floekr2T::animation animation;
	};
}

#endif