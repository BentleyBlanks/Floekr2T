#include"skillManager.h"

namespace Floekr2T
{
	skillManager::skillManager()
	{
		sum = 0;
	}

	Floekr2T::skill& skillManager::createSkill(int type, float velocity, float damage, f2Point& position, Floekr2T::attacker* target, Floekr2T::animation& animation)
	{
		Floekr2T::skill temp(type, velocity, damage, position, target, animation);

		return temp;
	}

	//添加技能
	void skillManager::addSkill(int type, float velocity, float damage, f2Point& position, Floekr2T::attacker* target, Floekr2T::animation& animation)
	{
		Floekr2T::skill temp(type, velocity, damage, position, target, animation);

		skills.push_back(temp);

		sum++;
	}

	void skillManager::addSkill(Floekr2T::skill& skill)
	{
		skills.push_back(skill);

		sum++;
	}

	//继承-统一接口
	void skillManager::update()
	{
		//只有在技能向量集非空时才更新 当没有技能释放出来的时候向量始终是空的
		for(int i=0; i<skills.size(); i++)
		{
			skills[i].update();

			if(skills[i].live == true)
				continue;

			int j=0;
			//迭代找到元素并删除
			for(vector<Floekr2T::skill>::iterator it=skills.begin(); it!=skills.end(); )
			{
				if(j == i)
				{
					it = skills.erase(it);
					break;
				}
				else
				{
					++j;
					++it;
				}
			}
		}
	}

	void skillManager::draw()
	{
		for(int i=0; i<skills.size(); i++)
		{
			skills[i].draw();
			
			f2DrawRect(skills[i].aabb.min, skills[i].aabb.max);
		}
	}
}