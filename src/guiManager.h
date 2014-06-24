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

		//���ui���
		void add();

		//�̳�-ͳһ�ӿ�
		void update();
		void draw();

		//�洢����Ԥ���嶯���Ĵ洢λ��
		vector<Floekr2T::guiComponent> guiComponents;
	};
}

#endif