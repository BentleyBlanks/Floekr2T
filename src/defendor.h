#ifndef DEFENDOR_H
#define DEFENDOR_H

#include"attacker.h"
#include"settings.h"
#include"animation.h"
#include"skill.h"
#include"skillManager.h"

//抵御者释放技能属性类型 (追踪 自定义轨道 范围)
#define TRACK 0
#define PATH 1
#define SCOPE 2

namespace Floekr2T
{
	class attacker;
	class skill;
	class animation;
	class skillManager;
	class defendor
	{
	public:
		defendor(int type, float range, float damage, f2Point& position, Floekr2T::animation& animation, Floekr2T::animation& skillAnimation);

		//抵御者状态更新
		void update(vector<Floekr2T::attacker>& attackers, vector<Floekr2T::skill>& skills);
		void update(vector<Floekr2T::attacker>& attackers, Floekr2T::skillManager& skillManager);
		//绘制当前对应帧动画
		void draw();
		
		//设定技能碰撞AABB
		void setSkillAABB(int offsetX, int offsetY, int width, int height);

	private:

		//释放技能类型
		int type;
		//释放技能的伤害
		float damage;
		//释放技能的AABB偏移量
		int offsetX, offsetY;
		//释放技能的宽高范围
		int skillWidth, skillHeight;

		//激活范围(半径)
		float range;
		//半径平方
		float rangeSquared;

		//位置属性
		f2Point position;
		//追踪目标
		Floekr2T::attacker* target;

		//抵御者和释放技能的帧动画
		Floekr2T::animation animation;
		Floekr2T::animation skillAnimation;
	};
}

#endif