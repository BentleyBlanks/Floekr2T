#include"attacker.h"

namespace Floekr2T
{
	attacker::attacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation)
		:trace(trace), velocity(velocity), HP(HP), animation(animation)
	{
		currentPoint = 0;
		live = true;
		//��ʼλ��Ϊ·����ʼ��
		position = trace.getStartup();

		////Ĭ�Ͽ��Ϊ��һ����ʼ֡�������
		//width = animation.pictures[0].width;
		//height = animation.pictures[0].height;
		////Ĭ��AABB
		//aabb.min = position;
		//aabb.max.x = position.x + width;
		//aabb.max.y = position.y + height;

		//Ĭ��û��ƫ��
		setAABB(0, 0, animation.width, animation.height);
	}

	bool attacker::update(vector<Floekr2T::skill>& skills)
	{
		static Floekr2T::skill *temp;
		static f2Point offset;
		static f2Point point;

		
		if(completeWalk == true)
			return live;

		//��ȡ��һ�յ�
		point = trace.getNextPoint(currentPoint);
		direction = point - position;
		direction.normalize();
		direction *= velocity;

		//����λ����Ϣ
		position += direction;

		updateAABB(position);

		if(position == point)
		{
			//����·��ѭ����
			currentPoint = (currentPoint+1) % trace.getSumPoint();
			//if(++currentPoint == trace.getSumPoint())
				//completeWalk = true;
		}

		//AABB�ж��Ƿ��뼼����ײ
		for(int i=0; i<skills.size(); i++)
		{
			temp = &skills[i];

			////�õ����ܺ͹�����֮���λ��
			//offset = position - temp->position;

			////���ߵ�AABB���������ײ
			//if(abs(offset.x*2) < width + temp->width && 
			//	abs(offset.y*2) < height + temp->height)
			//{
			//	live = false;
			//	//ֱ���������
			//	return live;
			//}

			//�ж���ǰattacker�뵱ǰskill������ײ
			temp->live = !AABBandAABB(temp->aabb);

			//�����빥���߷�����ײ
			if(temp->live == false)
			{
				//�۳��˺�
				HP -= temp->damage;
				if(HP <= 0 && live == true)
					live = false;

				int j=0;
				//�����ҵ�Ԫ�ز�ɾ��
				for(vector<Floekr2T::skill>::iterator it=skills.begin(); it!=skills.end(); )
				{
					if(j == i)
					{
						it = skills.erase(it);
						break;
					}
					else
					{
						++j;
						++it;
					}
				}
			}

			//ֻ���ڷǴ��״̬��ֱ������
			if(!live)
				return live;
		}
		//static f2Point oldDirection;
		////��û���ߵ��յ�
		//if(oldDirection == direction)
		//	return live;

		return live;
	}

	void attacker::draw()
	{
		animation.drawCurrentFrame(position);
		//ofSetColor( 0, 0, 0 );
		//����Ѫ��
		f2DrawRect(f2Point(position.x+width, position.y-height*0.5), f2Point(position.x+width + HP*0.1, position.y-height*0.5+5));
	}

	float attacker::getHP()
	{
		return HP;
	}

	int attacker::getWidth()
	{
		return width;
	}

	int attacker::getHeight()
	{
		return height;
	}
}