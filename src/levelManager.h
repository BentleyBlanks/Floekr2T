#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include"manager.h"
#include"skill.h"

namespace Floekr2T
{
	//����ģʽ
	class levelManager:public Floekr2T::manager
	{
	public:
		levelManager();

		//��ӹؿ�
		void add();

		//�̳�-ͳһ�ӿ�
		void update();
		void draw();

		//�洢����Ԥ���嶯���Ĵ洢λ��
		vector<Floekr2T::skill> skills;
	};
}

#endif