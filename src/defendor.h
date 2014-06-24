#ifndef DEFENDOR_H
#define DEFENDOR_H

#include"attacker.h"
#include"settings.h"
#include"animation.h"
#include"skill.h"
#include"skillManager.h"

//�������ͷż����������� (׷�� �Զ����� ��Χ)
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

		//������״̬����
		void update(vector<Floekr2T::attacker>& attackers, vector<Floekr2T::skill>& skills);
		void update(vector<Floekr2T::attacker>& attackers, Floekr2T::skillManager& skillManager);
		//���Ƶ�ǰ��Ӧ֡����
		void draw();
		
		//�趨������ײAABB
		void setSkillAABB(int offsetX, int offsetY, int width, int height);

	private:

		//�ͷż�������
		int type;
		//�ͷż��ܵ��˺�
		float damage;
		//�ͷż��ܵ�AABBƫ����
		int offsetX, offsetY;
		//�ͷż��ܵĿ�߷�Χ
		int skillWidth, skillHeight;

		//���Χ(�뾶)
		float range;
		//�뾶ƽ��
		float rangeSquared;

		//λ������
		f2Point position;
		//׷��Ŀ��
		Floekr2T::attacker* target;

		//�����ߺ��ͷż��ܵ�֡����
		Floekr2T::animation animation;
		Floekr2T::animation skillAnimation;
	};
}

#endif