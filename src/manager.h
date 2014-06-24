#ifndef MANAGER_H
#define MANAGER_H

namespace Floekr2T
{
	class manager
	{
	public:
		//统一接口
		void update(){};
		void draw(){};

		//管理的成员个数
		int sum;
	};
}

#endif