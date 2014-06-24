#include"animation.h"

namespace Floekr2T
{
	animation::animation()
	{
		currentFrame = 0;
		sumFrames = 0;
		
		//清空向量集
		pictures.clear();
	}

	void animation::loadFrames(string folderName, string suffixFormat, int sumNumber)
	{
		int sumWidth=0, sumHeight=0;

		f2Image temp;
		string current;
		char convert[5];

		//循环添加完整个文件夹
		for(int i=1; i<=sumNumber; i++)
		{
			//将int型i转换为char*之后再转换为string
			sprintf(convert, "%d", i);
			current = convert;
			//文件夹/folderName-x.suffix
			if(!temp.loadImage(folderName + "/" + folderName + "-" + current + "." + suffixFormat))
			{
				printf("无法从指定文件夹中读取帧动画相关图片");
				continue;
			}

			sumWidth += temp.width;
			sumHeight += temp.height;

			addFrame(temp);
		}

		//初始化帧动画的平均宽高
		width = sumWidth/sumNumber;
		height = sumHeight/sumNumber;
	}

	void animation::addFrame(f2Image& image)
	{
		//在尾部插入新图片/帧
		pictures.push_back(image);

		sumFrames++;
	}

	void animation::drawCurrentFrame(f2Point& position)
	{
		//若当前动画没有帧则直接跳过
		if(sumFrames == 0)
			return;

		//头尾循环更新当前帧位置指向
		currentFrame = (currentFrame+1) % sumFrames;

		//在指定位置直接绘制出给定图片长宽的帧动画
		pictures[currentFrame].draw(position.x, position.y, position.z);
	}
}