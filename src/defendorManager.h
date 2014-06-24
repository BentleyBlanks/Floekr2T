#ifndef DEFENDOR_MANAGER_H
#define DEFENDOR_MANAGER_H

#include"manager.h"
#include"defendor.h"

namespace Floekr2T
{
	class defendorManager:public Floekr2T::manager
	{
	public:
		defendorManager();

		Floekr2T::defendor& createDefendor(int type, float range, float damage, f2Point& position, Floekr2T::animation& animation, Floekr2T::animation& skillAnimation);

		//添加抵御者
		void addDefendor(int type, float range, float damage, f2Point& position, Floekr2T::animation& animation, Floekr2T::animation& skillAnimation);

		void addDefendor(Floekr2T::defendor& defendor);

		//继承-统一接口
		void update(vector<Floekr2T::attacker>& attackers, vector<Floekr2T::skill>& skills);
		void update(vector<Floekr2T::attacker>& attackers, Floekr2T::skillManager& skillManager);

		void draw();

		//存储所有预定义动画的存储位置
		vector<Floekr2T::defendor> defendors;
	};
}

#endif