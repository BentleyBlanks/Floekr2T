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

		//��ӵ�����
		void addDefendor(int type, float range, float damage, f2Point& position, Floekr2T::animation& animation, Floekr2T::animation& skillAnimation);

		void addDefendor(Floekr2T::defendor& defendor);

		//�̳�-ͳһ�ӿ�
		void update(vector<Floekr2T::attacker>& attackers, vector<Floekr2T::skill>& skills);
		void update(vector<Floekr2T::attacker>& attackers, Floekr2T::skillManager& skillManager);

		void draw();

		//�洢����Ԥ���嶯���Ĵ洢λ��
		vector<Floekr2T::defendor> defendors;
	};
}

#endif