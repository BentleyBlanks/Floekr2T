#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include"manager.h"
#include"scene.h"

namespace Floekr2T
{
	class sceneManager:public Floekr2T::manager
	{
	public:
		sceneManager();

		//添加场景
		void add();

		//继承-统一接口
		void update();
		void draw();

		//存储所有预定义动画的存储位置
		vector<Floekr2T::scene> scenes;
	};
}

#endif