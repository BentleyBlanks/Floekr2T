#include"attacker.h"

namespace Floekr2T
{
	attacker::attacker(Floekr2T::trace& trace, int velocity, int HP, Floekr2T::animation& animation)
		:trace(trace), velocity(velocity), HP(HP), animation(animation)
	{
		currentPoint = 0;
		live = true;
		//起始位置为路径起始点
		position = trace.getStartup();

		////默认宽高为第一张起始帧动画宽高
		//width = animation.pictures[0].width;
		//height = animation.pictures[0].height;
		////默认AABB
		//aabb.min = position;
		//aabb.max.x = position.x + width;
		//aabb.max.y = position.y + height;

		//默认没有偏移
		setAABB(0, 0, animation.width, animation.height);
	}

	bool attacker::update(vector<Floekr2T::skill>& skills)
	{
		static Floekr2T::skill *temp;
		static f2Point offset;
		static f2Point point;

		
		if(completeWalk == true)
			return live;

		//获取下一拐点
		point = trace.getNextPoint(currentPoint);
		direction = point - position;
		direction.normalize();
		direction *= velocity;

		//更新位置信息
		position += direction;

		updateAABB(position);

		if(position == point)
		{
			//按照路径循坏走
			currentPoint = (currentPoint+1) % trace.getSumPoint();
			//if(++currentPoint == trace.getSumPoint())
				//completeWalk = true;
		}

		//AABB判断是否与技能碰撞
		for(int i=0; i<skills.size(); i++)
		{
			temp = &skills[i];

			////得到技能和攻击者之间的位移
			//offset = position - temp->position;

			////两者的AABB区域存在碰撞
			//if(abs(offset.x*2) < width + temp->width && 
			//	abs(offset.y*2) < height + temp->height)
			//{
			//	live = false;
			//	//直接跳出检测
			//	return live;
			//}

			//判定当前attacker与当前skill有无碰撞
			temp->live = !AABBandAABB(temp->aabb);

			//技能与攻击者发生碰撞
			if(temp->live == false)
			{
				//扣除伤害
				HP -= temp->damage;
				if(HP <= 0 && live == true)
					live = false;

				int j=0;
				//迭代找到元素并删除
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

			//只有在非存活状态才直接跳出
			if(!live)
				return live;
		}
		//static f2Point oldDirection;
		////若没有走到拐点
		//if(oldDirection == direction)
		//	return live;

		return live;
	}

	void attacker::draw()
	{
		animation.drawCurrentFrame(position);
		//ofSetColor( 0, 0, 0 );
		//绘制血量
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