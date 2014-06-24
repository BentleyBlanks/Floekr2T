#ifndef GUICOMPONENT_H
#define GUICOMPONENT_H

#include"settings.h"
#include"manager.h"
#include"defendor.h"

namespace Floekr2T
{
	class guiComponent
	{
	public:
		guiComponent();

		//可以直接用过基类Component来调用派生类function来更新状态/绘制
		virtual void update(){};

		virtual void draw(){};

		//组件的作用域宽高
		int width, height;
		//左上角位置
		f2Point position;

		//gui深度显示顺序
		int zOrder;
	};
}

#endif