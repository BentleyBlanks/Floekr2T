#ifndef ATTACKER_MANAGER_H
#define ATTACKER_MANAGER_H

#include"manager.h"
#include"attacker.h"

namespace Floekr2T
{
	class attackerManager:public Floekr2T::manager
	{
	public:
		attackerManager();

		//创建一个Attacker
		Floekr2T::attacker& createAttacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation);

		//添加攻击者
		void addAttacker(Floekr2T::attacker& attacker);

		void addAttacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation);

		//继承-统一接口
		void update(vector<Floekr2T::skill>& skills);

		void draw();

		//存储所有预定义动画的存储位置
		vector<Floekr2T::attacker> attackers;
	};
}

#endif