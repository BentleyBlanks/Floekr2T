#ifndef ANIMATION_H
#define ANIMATION_H

#include"settings.h"

namespace Floekr2T
{
	class animation
	{
	public:
		animation();

		//ֱ�Ӷ���һ����XXX�ļ��е�֡����ͼƬ(�ļ���λ��of���̵�bin/data��) ��-1��ʼֱ��-sumΪֹ
		//��Ҫ������ʽΪ"XXX-1.png/bmp..."�ȵ�
		//�ļ����� ��׺��(�����ļ��ĸ�ʽ����ҪͳһΪͬһ��ʽ) ֡��(�ļ�����)
		void loadFrames(string folderName, string suffixFormat, int sumNumber);

		//���֡����ͼ
		void addFrame(f2Image& image);

		//��ָ��λ�û��Ƶ�ǰ֡
		void drawCurrentFrame(f2Point& position);

		//֡����ͳһ���
		int width, height;

		//��ǰ֡
		int currentFrame;
		//��֡��
		int sumFrames;
		//֡������
		vector<f2Image> pictures;

	};
}

#endif