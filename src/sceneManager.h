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

		//��ӳ���
		void add();

		//�̳�-ͳһ�ӿ�
		void update();
		void draw();

		//�洢����Ԥ���嶯���Ĵ洢λ��
		vector<Floekr2T::scene> scenes;
	};
}

#endif