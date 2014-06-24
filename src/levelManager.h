#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include"manager.h"
#include"skill.h"

namespace Floekr2T
{
	//单例模式
	class levelManager:public Floekr2T::manager
	{
	public:
		levelManager();

		//添加关卡
		void add();

		//继承-统一接口
		void update();
		void draw();

		//存储所有预定义动画的存储位置
		vector<Floekr2T::skill> skills;
	};
}

#endif