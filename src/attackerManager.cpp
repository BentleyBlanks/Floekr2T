#include"attackerManager.h"

namespace Floekr2T
{
	attackerManager::attackerManager()
	{
		sum = 0;
	}

	Floekr2T::attacker& attackerManager::createAttacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation)
	{
		Floekr2T::attacker *temp = new Floekr2T::attacker(trace, velocity, HP, animation);

		return *temp;
	}

	void attackerManager::addAttacker(Floekr2T::attacker& attacker)
	{
		attackers.push_back(attacker);

		sum++;
	}

	void attackerManager::addAttacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation)
	{
		Floekr2T::attacker temp(trace, velocity, HP, animation);

		attackers.push_back(temp);

		sum++;
	}

	//继承-统一接口
	void attackerManager::update(vector<Floekr2T::skill>& skills)
	{
		bool live = true;
		for(int i=0; i<attackers.size(); i++)
		{
			live = attackers[i].update(skills);

			if(live == false)
			{
				int j = 0;
				//迭代找到元素并删除
				for(vector<Floekr2T::attacker>::iterator it=attackers.begin(); it!=attackers.end(); )
				{
					if(j == i)
					{
						it = attackers.erase(it);
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
	}

	void attackerManager::draw()
	{
		for(int i=0; i<attackers.size(); i++)
		{
			attackers[i].draw();
		}
	}
}