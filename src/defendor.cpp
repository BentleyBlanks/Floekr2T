#include"defendor.h"

namespace Floekr2T
{
	defendor::defendor(int type, float range, float damage, f2Point& position, Floekr2T::animation& animation, Floekr2T::animation& skillAnimation)
		:type(type), range(range), damage(damage), position(position), animation(animation), skillAnimation(skillAnimation)
	{
		rangeSquared = range * range;

		//Ĭ���ͷŵļ���AABB����ƫ��
		offsetX = 0;
		offsetY = 0;
		skillWidth = skillAnimation.pictures[0].width;
		skillHeight = skillAnimation.pictures[0].height;
	}

	//������״̬����
	void defendor::update(vector<Floekr2T::attacker>& attackers, vector<Floekr2T::skill>& skills)
	{
		//��ʱ����һ�з�
		Floekr2T::attacker *temp;
		Floekr2T::skill *newSkill;
		static float time, oldTime;

		//����attacker������λ���ж��Ƿ��ͷż���
		for(int i=0; i<attackers.size(); i++)
		{
			//ȡ�õ�ǰ��������ָ��
			temp = &attackers[i];

			//�Ƿ��ڼ����ͷŷ�Χ��
			if(rangeSquared < (position-temp->aabb.min).lengthSquared())
				//����ʩ����Χ
				continue;

			//���ݲ�ͬ�������ͷŲ�ͬ�ļ���
			switch (type)
			{
			case TRACK:
				//����Ŀ��Ϊ��ǰ�������Ķ���
				target = temp;
				
				//��ʱ
				time = f2GetElapsedTime();
				if(time - oldTime > 1.5f)
				{
					oldTime = time;
				}
				else
					break;

				//��ʼ�����ܵ��ٶ� ���� ��ʼλ�� ׷��Ŀ��
				newSkill = new Floekr2T::skill(TRACK, 1.1, damage, position, target, skillAnimation);
				newSkill->setAABB(offsetX, offsetY, skillWidth, skillHeight);
				skills.push_back(*newSkill);
				break;

			case PATH:
				//��Track��ͬ���� Path�ļ���ֻ�����������˶������ж� ���������targetʱʱ�仯 targetֻ�����ڳ�ʼ���ͷŷ���
				//����Ŀ��Ϊ��ǰ�������Ķ���
				target = temp;

				//��ʱ
				time = f2GetElapsedTime();
				if(time - oldTime > 1.5f)
				{
					oldTime = time;
				}
				else
					break;

				//��ʼ�����ܵ��ٶ� ���� ��ʼλ�� ׷��Ŀ��
				newSkill = new Floekr2T::skill(PATH, 1.1, damage, position, target, skillAnimation);
				newSkill->setAABB(offsetX, offsetY, skillWidth, skillHeight);
				skills.push_back(*newSkill);
				break;

			case SCOPE:
				//ֱ�Ӷ�range��Χ�ڵĵط��ܵ�һ���̶ȵ��˺�
				temp->HP -= damage;
				break;
			}
		}
	}

		//������״̬����
	void defendor::update(vector<Floekr2T::attacker>& attackers, Floekr2T::skillManager& skillManager)
	{
		//��ʱ����һ�з�
		Floekr2T::attacker *temp;
		Floekr2T::skill *newSkill;
		static float time, oldTime;

		//����attacker������λ���ж��Ƿ��ͷż���
		for(int i=0; i<attackers.size(); i++)
		{
			//ȡ�õ�ǰ��������ָ��
			temp = &attackers[i];

			//�Ƿ��ڼ����ͷŷ�Χ��
			if(rangeSquared < (position-temp->aabb.min).lengthSquared())
				//����ʩ����Χ
				continue;

			//���ݲ�ͬ�������ͷŲ�ͬ�ļ���
			switch (type)
			{
			case TRACK:
				//����Ŀ��Ϊ��ǰ�������Ķ���
				target = temp;
				
				//��ʱ
				time = f2GetElapsedTime();
				if(time - oldTime > 1.5f)
				{
					oldTime = time;
				}
				else
					break;

				//��ʼ�����ܵ��ٶ� ���� ��ʼλ�� ׷��Ŀ��
				newSkill = new Floekr2T::skill(TRACK, 1.1, damage, position, target, skillAnimation);
				newSkill->setAABB(offsetX, offsetY, skillWidth, skillHeight);
				skillManager.addSkill(*newSkill);
				break;

			case PATH:
				//��Track��ͬ���� Path�ļ���ֻ�����������˶������ж� ���������targetʱʱ�仯 targetֻ�����ڳ�ʼ���ͷŷ���
				//����Ŀ��Ϊ��ǰ�������Ķ���
				target = temp;

				//��ʱ
				time = f2GetElapsedTime();
				if(time - oldTime > 1.5f)
				{
					oldTime = time;
				}
				else
					break;

				//��ʼ�����ܵ��ٶ� ���� ��ʼλ�� ׷��Ŀ��
				newSkill = new Floekr2T::skill(PATH, 1.1, damage, position, target, skillAnimation);
				newSkill->setAABB(offsetX, offsetY, skillWidth, skillHeight);
				skillManager.addSkill(*newSkill);
				break;

			case SCOPE:
				//ֱ�Ӷ�range��Χ�ڵĵط��ܵ�һ���̶ȵ��˺�
				temp->HP -= damage;
				break;
			}
		}
	}

	//���Ƶ�ǰ��Ӧ֡����
	void defendor::draw()
	{
		//ֱ�ӻ��Ƶ�ǰ֡
		animation.drawCurrentFrame(position);
		//����������
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