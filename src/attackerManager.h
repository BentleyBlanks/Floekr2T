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

		//����һ��Attacker
		Floekr2T::attacker& createAttacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation);

		//��ӹ�����
		void addAttacker(Floekr2T::attacker& attacker);

		void addAttacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation);

		//�̳�-ͳһ�ӿ�
		void update(vector<Floekr2T::skill>& skills);

		void draw();

		//�洢����Ԥ���嶯���Ĵ洢λ��
		vector<Floekr2T::attacker> attackers;
	};
}

#endif