#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include"manager.h"
#include"animation.h"

namespace Floekr2T
{
	class animationManager:public Floekr2T::manager
	{
	public:
		animationManager();

		//对应于一整个帧动画文件夹添加帧动画animation
		Floekr2T::animation& createAnimation(string folderName, string suffixFormat, int sumNumber);

		//直接添加一现成动画
		//void add(Floekr2T::animation& animation);

		////继承-统一接口
		//void update();
		//void draw();

		//存储所有预定义动画的存储位置
		//vector<Floekr2T::animation> animations;
	};
}

#endif