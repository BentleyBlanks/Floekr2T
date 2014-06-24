#include"defendorManager.h"

namespace Floekr2T
{
	defendorManager::defendorManager()
	{
		sum = 0;
	}

	Floekr2T::defendor& defendorManager::createDefendor(int type, float range, float damage, f2Point& position, Floekr2T::animation& animation, Floekr2T::animation& skillAnimation)
	{
		Floekr2T::defendor *temp = new Floekr2T::defendor(type, range, damage, position, animation, skillAnimation);

		return *temp;
	}

	void defendorManager::addDefendor(int type, float range, float damage, f2Point& position, Floekr2T::animation& animation, Floekr2T::animation& skillAnimation)
	{
		//直接创建一指定对象并添加
		Floekr2T::defendor temp(type, range, damage, position, animation, skillAnimation);

		defendors.push_back(temp);

		sum++;
	}

	void defendorManager::addDefendor(Floekr2T::defendor& defendor)
	{
		defendors.push_back(defendor);

		sum++;
	}

	void defendorManager::update(vector<Floekr2T::attacker>& attackers, vector<Floekr2T::skill>& skills)
	{
		for(int i=0; i<sum; i++)
		{
			defendors[i].update(attackers, skills);
		}
	}

	void defendorManager::update(vector<Floekr2T::attacker>& attackers, Floekr2T::skillManager& skillManager)
	{
		for(int i=0; i<sum; i++)
		{
			defendors[i].update(attackers, skillManager);
		}
	}

	void defendorManager::draw()
	{
		for(int i=0; i<defendors.size(); i++)
		{
			defendors[i].draw();
		}
	}
}