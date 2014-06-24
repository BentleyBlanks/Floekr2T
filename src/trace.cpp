#include"trace.h"

namespace Floekr2T
{
	//trace::trace()
	//{
	//	//currentPoint = 0;
	//	sumPoints = -1;
	//	direction.zero();
	//}

	trace::trace()
	{
		//currentPoint = 0;
		//-1代表此向量集为空
		sumPoints = 0;

		//初始化方向
		direction.x = 0;
		direction.y = 1;
		direction.z = 0;
	}

	void trace::setStartup(f2Point& start)
	{
		//在队开头添加开始点 
		//或points[0]=start
		points.push_back(start);
		currentPoint = start;
		sumPoints++;
	}

	f2Point& trace::getStartup()
	{
		if(points.size()>0)
			return points[0];
	}

	f2Point& trace::getNextPoint(int num)
	{
		//不做错误检查
		return points[num];
	}

	int trace::getSumPoint()
	{
		return sumPoints;
	}

	//添加关键帧点
	void trace::addTurningPoint(f2Point& point)
	{
		//在尾部插入新的拐点
		points.push_back(point);
		
		sumPoints ++;
		////若是起始点之后第一个添加进来的额外拐点
		//if(sumPoints == 1)
		//	direction = point - start;

		//更新行径方向
		direction = points[sumPoints-1] - points[sumPoints - 2];
	}

	//四方位行径
	void trace::turnLeft(int distance)
	{
		//根据Z轴旋转90度 即在2D平面内旋转
		direction.rotate(-90, f2Point(0, 0, 1));
		direction.normalize();
		direction *= distance;

		//方向不变 等倍缩放
		//同时当前添加到的点也自动的更新为新增加的拐点
		currentPoint += direction;

		points.push_back(currentPoint);
		sumPoints ++;
	}

	void trace::turnRight(int distance)
	{
		//根据Z轴旋转-90度 即在2D平面内旋转
		direction.rotate(90, f2Point(0, 0, 1));
		direction.normalize();
		direction *= distance;

		//方向不变 等倍缩放
		//同时当前添加到的点也自动的更新为新增加的拐点
		currentPoint += direction;

		points.push_back(currentPoint);
		sumPoints ++;
	}

	//按照原方向
	void trace::goStraight(int distance)
	{
		//f2Point* point = &points[sumPoints-1];

		direction.normalize();
		direction *= distance;

		//方向不变 等倍缩放
		//同时当前添加到的点也自动的更新为新增加的拐点
		currentPoint += direction;

		points.push_back(currentPoint);
		sumPoints ++;

		////及时释放
		//delete(point);
	}

	//旋转180度
	void trace::goBack(int distance)
	{
		//根据Z轴旋转180度 即在2D平面内旋转
		direction.rotate(180, f2Point(0, 0, 1));
		direction.normalize();
		direction *= distance;

		//方向不变 等倍缩放
		//同时当前添加到的点也自动的更新为新增加的拐点
		currentPoint += direction;

		points.push_back(currentPoint);
		sumPoints ++;
	}
}