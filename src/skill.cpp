#include"skill.h"
namespace Floekr2T
{
	skill::skill(int type, float velocity, float damage, f2Point& position, Floekr2T::attacker* target, Floekr2T::animation& animation)
		:type(type), velocity(velocity), damage(damage), position(position), target(target), animation(animation)
	{
		//��targetĿ������ʼ��λ�ú��˶�����
		direction = target->aabb.min - position;
		direction.normalize();

		live = true;

		////Ĭ�Ͽ��Ϊ��һ����ʼ֡�������
		//width = animation.pictures[0].width;
		//height = animation.pictures[0].height;
		////Ĭ��AABB
		//aabb.min = position;
		//aabb.max.x = position.x + width;
		//aabb.max.y = position.y + height;

		//Ĭ�Ͽ��Ϊ��һ����ʼ֡�������
		//Ĭ��û��ƫ��
		setAABB(0, 0, animation.pictures[0].width, animation.pictures[0].height);
	}

	void skill::update()
	{
		//���ݼ�������������λ����Ϣ
		switch (type)
		{
		case TRACK:
			//׷��Ŀ��
			//ʵʱ����Ŀ�������˶�����
			direction = target->aabb.min - position;
			direction.normalize();

			//�Ŵ���Ϊ����
			direction *= velocity;

			//����λ��
			position += direction;
			break;

		case PATH:
			//��Track��ͬ���� Path�ļ���ֻ�����������˶������ж� ���������targetʱʱ�仯 targetֻ�����ڳ�ʼ���ͷŷ���
			direction.normalize();
			direction *= velocity;

			//����λ��
			position += direction;
			break;

		case SCOPE:
			//ֱ�Ӷ�range��Χ�ڵĵط��ܵ�һ���̶ȵ��˺�
			//���ڴ˼�������ֻ�������߼��� ���Բ�����Ҫ���и��¡�����Ϊ�������ᴴ��
			break;
		}
		updateAABB(position);
	}

	void skill::draw()
	{
		animation.drawCurrentFrame(position);
	}

	int skill::getWidth()
	{
		return width;
	}

	int skill::getHeight()
	{
		return height;
	}
}
