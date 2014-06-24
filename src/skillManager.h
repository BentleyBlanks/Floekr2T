#ifndef SKILL_MANAGER_H
#define SKILL_MANAGER_H

#include"manager.h"
#include"skill.h"

namespace Floekr2T
{
	class attacker;
	class skill;

	class skillManager:public Floekr2T::manager
	{
	public:
		skillManager();

		Floekr2T::skill& createSkill(int type, float velocity, float damage, f2Point& position, Floekr2T::attacker* target, Floekr2T::animation& animation);

		//��Ӽ���
		void addSkill(int type, float velocity, float damage, f2Point& position, Floekr2T::attacker* target, Floekr2T::animation& animation);

		void addSkill(Floekr2T::skill& skill);

		//�̳�-ͳһ�ӿ�
		void update();

		void draw();

		//�洢����Ԥ���嶯���Ĵ洢λ��
		vector<Floekr2T::skill> skills;
	};
}

#endif