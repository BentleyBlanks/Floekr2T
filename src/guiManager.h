#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include"manager.h"
#include"guiComponent.h"

namespace Floekr2T
{
	class guiManager:public Floekr2T::manager
	{
	public:
		guiManager();

		//添加ui组件
		void add();

		//继承-统一接口
		void update();
		void draw();

		//存储所有预定义动画的存储位置
		vector<Floekr2T::guiComponent> guiComponents;
	};
}

#endif