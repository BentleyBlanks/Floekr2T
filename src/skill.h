#ifndef SKILL_H
#define SKILL_H

#include"settings.h"
#include"defendor.h"
#include"attacker.h"
#include"animation.h"
#include"collision.h"

namespace Floekr2T
{
	class defendor;
	class attacker;

	class skill:public Floekr2T::collision
	{
	public:
		skill(int type, float velocity, float damage, f2Point& position, Floekr2T::attacker* target, Floekr2T::animation& animation);

		void update();

		void draw();

		//������Ա����
		int getWidth();

		int getHeight();

	//private:
		//�ͷŵļ�������
		int type;
		//�ͷż��ܵ��˺�
		float damage;
		//�Ƿ�����
		bool live;

		//������������
		float velocity;
		//��ǰ�н���λ��
		f2Point position;

		//����׷�ٵĵз�Ŀ��
		Floekr2T::attacker* target;
		//�����ͷŷ��� ��targetĿ������ʼ��
		f2Point direction;

		//��ǰ��������Ҫ���ŵ�֡����
		Floekr2T::animation animation;

	};
}

#endif