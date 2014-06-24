#ifndef SCENE_H
#define SCENE_H

#include"settings.h"
#include"animationManager.h"
#include"skillManager.h"
#include"attackerManager.h"
#include"defendorManager.h"
#include"guiManager.h"

namespace Floekr2T
{
	class scene
	{
	public:
		scene();

		//加载一XML配置文件用以直接加载一场景
		bool load(string xmlPath);

		void setup(Floekr2T::animationManager& animationManager, Floekr2T::attackerManager& attackerManager, Floekr2T::defendorManager& 
defendorManager, Floekr2T::guiManager& guiManager, Floekr2T::skillManager& skillManager);
		
		//外部调用更新和绘制
		void update();

		void draw();

	private:
		//add方法
		void addAnimationManager(Floekr2T::animationManager& animationManager);

		void addAttackerManager(Floekr2T::attackerManager& attackerManager);

		void addDefendorManager(Floekr2T::defendorManager& 
defendorManager);

		void addGUIManager(Floekr2T::guiManager& guiManager);

		void addSkillManager(Floekr2T::skillManager& skillManager);

		//动画 攻击者 抵御者 GUI 技能管理员
		Floekr2T::animationManager animationManager;

		Floekr2T::attackerManager attackerManager;

		Floekr2T::defendorManager defendorManager;

		Floekr2T::guiManager guiManager;

		Floekr2T::skillManager skillManager;

		f2Xml XML;
	};
}

#endif