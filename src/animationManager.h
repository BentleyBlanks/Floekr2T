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

		//��Ӧ��һ����֡�����ļ������֡����animation
		Floekr2T::animation& createAnimation(string folderName, string suffixFormat, int sumNumber);

		//ֱ�����һ�ֳɶ���
		//void add(Floekr2T::animation& animation);

		////�̳�-ͳһ�ӿ�
		//void update();
		//void draw();

		//�洢����Ԥ���嶯���Ĵ洢λ��
		//vector<Floekr2T::animation> animations;
	};
}

#endif