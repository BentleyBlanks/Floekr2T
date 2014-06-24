#ifndef TRACE_H
#define TRACE_H

#include"settings.h"

namespace Floekr2T
{
	class trace
	{
	public:
		trace();

		//设置起始点
		void setStartup(f2Point& start);
		f2Point& getStartup();
		f2Point& getNextPoint(int num);
		int getSumPoint();

		//添加关键帧点
		void addTurningPoint(f2Point& point);

		//四方位行径 意味着转向后再行进多少像素距离
		//逆时针旋转90度
		void turnLeft(int distance);
		//顺时针旋转90度
		void turnRight(int distance);
		//按照原方向
		void goStraight(int distance);
		//旋转180度
		void goBack(int distance);

	private:
		//当钱添加到的点
		f2Point currentPoint;
		//拐点总数
		//作用与points.capacity()相当 但是可以减少一次函数调用
		int sumPoints;
		//当前的行进方向
		f2Point direction;

		//路径开始点
		//f2Point start;
		//用于存放拐点 路径开始点为[0]
		vector<f2Point> points;
	};
}

#endif