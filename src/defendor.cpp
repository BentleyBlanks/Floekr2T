#include"defendor.h"

namespace Floekr2T
{
	defendor::defendor(int type, float range, float damage, f2Point& position, Floekr2T::animation& animation, Floekr2T::animation& skillAnimation)
		:type(type), range(range), damage(damage), position(position), animation(animation), skillAnimation(skillAnimation)
	{
		rangeSquared = range * range;

		//默认释放的技能AABB并无偏移
		offsetX = 0;
		offsetY = 0;
		skillWidth = skillAnimation.pictures[0].width;
		skillHeight = skillAnimation.pictures[0].height;
	}

	//抵御者状态更新
	void defendor::update(vector<Floekr2T::attacker>& attackers, vector<Floekr2T::skill>& skills)
	{
		//临时申请一敌方
		Floekr2T::attacker *temp;
		Floekr2T::skill *newSkill;
		static float time, oldTime;

		//遍历attacker根据其位置判断是否释放技能
		for(int i=0; i<attackers.size(); i++)
		{
			//取得当前遍历对象指针
			temp = &attackers[i];

			//是否在技能释放范围内
			if(rangeSquared < (position-temp->aabb.min).lengthSquared())
				//超出施技范围
				continue;

			//根据不同类型来释放不同的技能
			switch (type)
			{
			case TRACK:
				//设置目标为当前遍历到的对象
				target = temp;
				
				//计时
				time = f2GetElapsedTime();
				if(time - oldTime > 1.5f)
				{
					oldTime = time;
				}
				else
					break;

				//初始化技能的速度 属性 初始位置 追踪目标
				newSkill = new Floekr2T::skill(TRACK, 1.1, damage, position, target, skillAnimation);
				newSkill->setAABB(offsetX, offsetY, skillWidth, skillHeight);
				skills.push_back(*newSkill);
				break;

			case PATH:
				//与Track不同的是 Path的技能只会根据自身的运动方向行动 而不会根据target时时变化 target只是用于初始化释放方向
				//设置目标为当前遍历到的对象
				target = temp;

				//计时
				time = f2GetElapsedTime();
				if(time - oldTime > 1.5f)
				{
					oldTime = time;
				}
				else
					break;

				//初始化技能的速度 属性 初始位置 追踪目标
				newSkill = new Floekr2T::skill(PATH, 1.1, damage, position, target, skillAnimation);
				newSkill->setAABB(offsetX, offsetY, skillWidth, skillHeight);
				skills.push_back(*newSkill);
				break;

			case SCOPE:
				//直接对range范围内的地方受到一定程度的伤害
				temp->HP -= damage;
				break;
			}
		}
	}

		//抵御者状态更新
	void defendor::update(vector<Floekr2T::attacker>& attackers, Floekr2T::skillManager& skillManager)
	{
		//临时申请一敌方
		Floekr2T::attacker *temp;
		Floekr2T::skill *newSkill;
		static float time, oldTime;

		//遍历attacker根据其位置判断是否释放技能
		for(int i=0; i<attackers.size(); i++)
		{
			//取得当前遍历对象指针
			temp = &attackers[i];

			//是否在技能释放范围内
			if(rangeSquared < (position-temp->aabb.min).lengthSquared())
				//超出施技范围
				continue;

			//根据不同类型来释放不同的技能
			switch (type)
			{
			case TRACK:
				//设置目标为当前遍历到的对象
				target = temp;
				
				//计时
				time = f2GetElapsedTime();
				if(time - oldTime > 1.5f)
				{
					oldTime = time;
				}
				else
					break;

				//初始化技能的速度 属性 初始位置 追踪目标
				newSkill = new Floekr2T::skill(TRACK, 1.1, damage, position, target, skillAnimation);
				newSkill->setAABB(offsetX, offsetY, skillWidth, skillHeight);
				skillManager.addSkill(*newSkill);
				break;

			case PATH:
				//与Track不同的是 Path的技能只会根据自身的运动方向行动 而不会根据target时时变化 target只是用于初始化释放方向
				//设置目标为当前遍历到的对象
				target = temp;

				//计时
				time = f2GetElapsedTime();
				if(time - oldTime > 1.5f)
				{
					oldTime = time;
				}
				else
					break;

				//初始化技能的速度 属性 初始位置 追踪目标
				newSkill = new Floekr2T::skill(PATH, 1.1, damage, position, target, skillAnimation);
				newSkill->setAABB(offsetX, offsetY, skillWidth, skillHeight);
				skillManager.addSkill(*newSkill);
				break;

			case SCOPE:
				//直接对range范围内的地方受到一定程度的伤害
				temp->HP -= damage;
				break;
			}
		}
	}

	//绘制当前对应帧动画
	void defendor::draw()
	{
		//直接绘制当前帧
		animation.drawCurrentFrame(position);
		//绘制作用域
		f2DrawCircle(position, range);
	}

	void defendor::setSkillAABB(int offsetX, int offsetY, int width, int height)
	{
		this->offsetX = offsetX;
		this->offsetY = offsetY;

		skillWidth = width;
		skillHeight = height;
	}
}