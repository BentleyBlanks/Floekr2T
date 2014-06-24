#ifndef ATTACKER_H
#define ATTACKER_H

#include"settings.h"
#include"trace.h"
#include"animation.h"
#include"skill.h"
#include"collision.h"

namespace Floekr2T
{
	class skill;

	class attacker:public Floekr2T::collision
	{
	public:
		attacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation);

		//�ж��뼼��Ⱥ��λ�ù�ϵ ���ش����Ϣ
		bool update(vector<Floekr2T::skill>& skills);

		void draw();

		//������Ա����
		float getHP();

		int getWidth();

		int getHeight();

	//private:
		//�Ƿ�����
		bool live;
		//�Ƿ�����н�
		bool completeWalk;

		//�н���·��
		Floekr2T::trace trace;
		//��ǰ�н����ĵ�
		int currentPoint;

		//�����ߵ�λ����Ϣ
		f2Point position;

		//�˶�����
		int velocity;
		
		//Ѫ��
		float HP;

		//�˶�����
		f2Point direction;
		//֡����
		Floekr2T::animation animation;
	};
}

#endif