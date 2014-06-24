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

		//����ֱ���ù�����Component������������function������״̬/����
		virtual void update(){};

		virtual void draw(){};

		//�������������
		int width, height;
		//���Ͻ�λ��
		f2Point position;

		//gui�����ʾ˳��
		int zOrder;
	};
}

#endif