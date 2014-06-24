#include"animationManager.h"

namespace Floekr2T
{
	animationManager::animationManager()
	{
	}

	Floekr2T::animation& animationManager::createAnimation(string folderName, string suffixFormat, int sumNumber)
	{
		Floekr2T::animation *anim = new Floekr2T::animation();

		anim->loadFrames(folderName, suffixFormat, sumNumber);

		return *anim;
	}

	//void animationManager::add(Floekr2T::animation& animation)
	//{
	//	animations.push_back(animation);

	//	sum++;
	//}

	//void animationManager::update()
	//{
	//	
	//}

	//void animationManager::draw()
	//{
	//}
}