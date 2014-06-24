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

		//����һXML�����ļ�����ֱ�Ӽ���һ����
		bool load(string xmlPath);

		void setup(Floekr2T::animationManager& animationManager, Floekr2T::attackerManager& attackerManager, Floekr2T::defendorManager& 
defendorManager, Floekr2T::guiManager& guiManager, Floekr2T::skillManager& skillManager);
		
		//�ⲿ���ø��ºͻ���
		void update();

		void draw();

	private:
		//add����
		void addAnimationManager(Floekr2T::animationManager& animationManager);

		void addAttackerManager(Floekr2T::attackerManager& attackerManager);

		void addDefendorManager(Floekr2T::defendorManager& 
defendorManager);

		void addGUIManager(Floekr2T::guiManager& guiManager);

		void addSkillManager(Floekr2T::skillManager& skillManager);

		//���� ������ ������ GUI ���ܹ���Ա
		Floekr2T::animationManager animationManager;

		Floekr2T::attackerManager attackerManager;

		Floekr2T::defendorManager defendorManager;

		Floekr2T::guiManager guiManager;

		Floekr2T::skillManager skillManager;

		f2Xml XML;
	};
}

#endif