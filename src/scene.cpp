#include"scene.h"

namespace Floekr2T
{
	scene::scene()
	{

	}

	void scene::setup(Floekr2T::animationManager& animationManager, Floekr2T::attackerManager& attackerManager, Floekr2T::defendorManager& 
		defendorManager, Floekr2T::guiManager& guiManager, Floekr2T::skillManager& skillManager)
	{
		//����һϵ�й���������ʼ������
		addAnimationManager(animationManager);
		addAttackerManager(attackerManager);
		addDefendorManager(defendorManager);
		addGUIManager(guiManager);
		addSkillManager(skillManager);
	}

	bool scene::load(string xmlPath)
	{
		//ֱ�Ӵ�·���м���Xml�ļ�
		if(XML.load(xmlPath))
		{
			cout<<"loaded XML!"<<endl;
		}
		else
		{
			cout<<"bad load!"<<endl;
			return false;
		}

		if(XML.exists("defendor"))
		{
			//��ʱ����
			//defendor���
			int type;
			float range;
			ofPoint position;
			string animFolder, animSuffix;
			int animSum;
			//�������
			float skillDamage;
			string skillAnimFolder, skillAnimSuffix;
			int skillAnimSum;
			float skillOffsetX, skillOffsetY, skillWidth, skillHeight;

			//��ʼ�����ߵ���Ϣ��ʼ��
			XML.setTo("defendor");

			if(XML.exists("d"))
			{
				if(XML.getName() == "defendor" && XML.setTo("d[0]"))
				{
					//������һ��d
					do
					{
						//���ֻ��һ��������setTo()
						if(XML.exists("type"))
							//����������
							type = XML.getValue<int>("type");

						if(XML.exists("range"))
							//������Χ
								range = XML.getValue<float>("range");

						if(XML.exists("position"))
						{
							XML.setTo("position");
							position.x = XML.getValue<float>("x");
							position.y = XML.getValue<float>("y");

							//������һ�ڵ�
							XML.setToParent();
						}

						if(XML.exists("animation"))
						{
							XML.setTo("animation");

							//֡���� �ļ����� ��׺�� ֡��(���ٵ���֡�����ļ�)
							animFolder = XML.getValue<string>("folder");
							animSuffix = XML.getValue<string>("suffix");
							animSum = XML.getValue<int>("sum");

							//������һ�ڵ�
							XML.setToParent();
						}

						if(XML.exists("skill"))
						{
							XML.setTo("skill");

							//skill�е�animation�ڵ�
							if(XML.exists("animation"))
							{
								XML.setTo("animation");
								skillAnimFolder = XML.getValue<string>("folder");
								skillAnimSuffix = XML.getValue<string>("suffix");
								skillAnimSum = XML.getValue<int>("sum");

								//������һ�ڵ㼴animation
								XML.setToParent();
							}

							if(XML.exists("AABB"))
							{
								XML.setTo("AABB");

								skillOffsetX = XML.getValue<float>("offsetX");
								skillOffsetY = XML.getValue<float>("offsetY");
								skillWidth = XML.getValue<float>("width");
								skillHeight = XML.getValue<float>("height");

								XML.setToParent();
							}

							//�����˺�
							skillDamage = XML.getValue<float>("damage");

							XML.setToParent();
						}

						//ֱ������һdefendor
						Floekr2T::defendor defendor = defendorManager.createDefendor(type, range, skillDamage, position, 
							animationManager.createAnimation(animFolder, animSuffix, animSum), 
							animationManager.createAnimation(skillAnimFolder, skillAnimSuffix, skillAnimSum));
						
						defendor.setSkillAABB(skillOffsetX, skillOffsetY, skillWidth, skillHeight);
						//��ӽ���defendor����
						defendorManager.addDefendor(defendor);

					}while( XML.setToSibling());

					XML.setToParent();
				}
			}
			XML.setToParent();
		}

		if(XML.exists("attacker"))
		{
			//trace���
			f2Point traceStart;

			//attacker��������
			int mode;
			float distance, velocity, HP;
			string attackerAnimFolder, attackerAnimSuffix;
			float attakcerAnimSum;

			//AABB
			float offsetX, offsetY, width, height;

			//��ʼ�����ߵ���Ϣ��ʼ��
			XML.setTo("attacker");

			if(XML.exists("a"))
			{
				if(XML.getName() == "attacker" && XML.setTo("a[0]"))
				{
					do
					{
						//����traceֻ���ṩ����һ��attackerʹ��
						Floekr2T::trace tra;
						if(XML.exists("trace"))
						{
							XML.setTo("trace");

							//�ҵ�����ʼ����趨
							if(XML.exists("start"))
							{
								XML.setTo("start");

								traceStart.x = XML.getValue<float>("x");
								traceStart.y = XML.getValue<float>("y");
								//��·���������ʼ��
								tra.setStartup(traceStart);

								XML.setToParent();
							}

							//��ʼ·��ת��
							if(XML.exists("t"))
							{
								//������Ѱת������
								if(XML.setTo("t[0]"))
								{
									do
									{
										mode = XML.getValue<int>("mode");
										distance = XML.getValue<float>("distance");

										//���ݷ�λת����λ
										switch (mode)
										{
										case 0:
											tra.turnLeft(distance);
											break;
										case 1:
											tra.turnRight(distance);
											break;
										case 2:
											tra.goStraight(distance);
											break;
										case 3:
											tra.goBack(distance);
											break;
										}

									}while(XML.setToSibling());

									XML.setToParent();
								}
							}

							XML.setToParent();
						}

						if(XML.exists("velocity"))
						{
							//��ȡ�ƶ��ٶ�ֵ
							velocity = XML.getValue<float>("velocity");
						}

						if(XML.exists("HP"))
						{
							//��ȡ�ƶ��ٶ�ֵ
							HP = XML.getValue<float>("HP");
						}

						if(XML.exists("animation"))
						{
							XML.setTo("animation");

							//֡���� �ļ����� ��׺�� ֡��(���ٵ���֡�����ļ�)
							attackerAnimFolder = XML.getValue<string>("folder");
							attackerAnimSuffix = XML.getValue<string>("suffix");
							attakcerAnimSum = XML.getValue<float>("sum");

							//������һ�ڵ�
							XML.setToParent();
						}

						if(XML.exists("AABB"))
						{
							XML.setTo("AABB");

							offsetX = XML.getValue<float>("offsetX");
							offsetY = XML.getValue<float>("offsetY");
							width = XML.getValue<float>("width");
							height = XML.getValue<float>("height");

							XML.setToParent();
						}

						//ֱ������һattacker
						Floekr2T::attacker attacker = attackerManager.createAttacker(tra, velocity, HP, 
							animationManager.createAnimation(attackerAnimFolder, attackerAnimSuffix, attakcerAnimSum));

						attacker.setAABB(offsetX, offsetY, width, height);
						//����attacker����
						attackerManager.addAttacker(attacker);

					}while( XML.setToSibling());
				}
				XML.setToParent();
			}
			XML.setToParent();
		}

		//���ز���ȡ�ɹ�
		return true;
	}

	//��ʼ������
	void scene::addAnimationManager(Floekr2T::animationManager& animationManager)
	{
		this->animationManager = animationManager;
	}

	void scene::addAttackerManager(Floekr2T::attackerManager& attackerManager)
	{
		this->attackerManager = attackerManager;
	}

	void scene::addDefendorManager(Floekr2T::defendorManager& 
		defendorManager)
	{
		this->defendorManager = defendorManager;
	}

	void scene::addGUIManager(Floekr2T::guiManager& guiManager)
	{
		this->guiManager = guiManager;
	}

	void scene::addSkillManager(Floekr2T::skillManager& skillManager)
	{
		this->skillManager = skillManager;
	}

	void scene::update()
	{
		//����ȫ������
		skillManager.update();

		attackerManager.update(skillManager.skills);

		defendorManager.update(attackerManager.attackers, skillManager);
	}

	void scene::draw()
	{
		//����ȫ������
		skillManager.draw();

		attackerManager.draw();

		defendorManager.draw();
	}
}