#include"scene.h"

namespace Floekr2T
{
	scene::scene()
	{

	}

	void scene::setup(Floekr2T::animationManager& animationManager, Floekr2T::attackerManager& attackerManager, Floekr2T::defendorManager& 
		defendorManager, Floekr2T::guiManager& guiManager, Floekr2T::skillManager& skillManager)
	{
		//给定一系列管理者来初始化场景
		addAnimationManager(animationManager);
		addAttackerManager(attackerManager);
		addDefendorManager(defendorManager);
		addGUIManager(guiManager);
		addSkillManager(skillManager);
	}

	bool scene::load(string xmlPath)
	{
		//直接从路径中加载Xml文件
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
			//临时变量
			//defendor相关
			int type;
			float range;
			ofPoint position;
			string animFolder, animSuffix;
			int animSum;
			//技能相关
			float skillDamage;
			string skillAnimFolder, skillAnimSuffix;
			int skillAnimSum;
			float skillOffsetX, skillOffsetY, skillWidth, skillHeight;

			//开始抵御者的信息初始化
			XML.setTo("defendor");

			if(XML.exists("d"))
			{
				if(XML.getName() == "defendor" && XML.setTo("d[0]"))
				{
					//进入下一个d
					do
					{
						//如果只有一层则无需setTo()
						if(XML.exists("type"))
							//抵御者类型
							type = XML.getValue<int>("type");

						if(XML.exists("range"))
							//作用域范围
								range = XML.getValue<float>("range");

						if(XML.exists("position"))
						{
							XML.setTo("position");
							position.x = XML.getValue<float>("x");
							position.y = XML.getValue<float>("y");

							//返回上一节点
							XML.setToParent();
						}

						if(XML.exists("animation"))
						{
							XML.setTo("animation");

							//帧动画 文件夹名 后缀名 帧数(快速导入帧动画文件)
							animFolder = XML.getValue<string>("folder");
							animSuffix = XML.getValue<string>("suffix");
							animSum = XML.getValue<int>("sum");

							//返回上一节点
							XML.setToParent();
						}

						if(XML.exists("skill"))
						{
							XML.setTo("skill");

							//skill中的animation节点
							if(XML.exists("animation"))
							{
								XML.setTo("animation");
								skillAnimFolder = XML.getValue<string>("folder");
								skillAnimSuffix = XML.getValue<string>("suffix");
								skillAnimSum = XML.getValue<int>("sum");

								//返回上一节点即animation
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

							//技能伤害
							skillDamage = XML.getValue<float>("damage");

							XML.setToParent();
						}

						//直接新增一defendor
						Floekr2T::defendor defendor = defendorManager.createDefendor(type, range, skillDamage, position, 
							animationManager.createAnimation(animFolder, animSuffix, animSum), 
							animationManager.createAnimation(skillAnimFolder, skillAnimSuffix, skillAnimSum));
						
						defendor.setSkillAABB(skillOffsetX, skillOffsetY, skillWidth, skillHeight);
						//添加进入defendor工厂
						defendorManager.addDefendor(defendor);

					}while( XML.setToSibling());

					XML.setToParent();
				}
			}
			XML.setToParent();
		}

		if(XML.exists("attacker"))
		{
			//trace相关
			f2Point traceStart;

			//attacker自身属性
			int mode;
			float distance, velocity, HP;
			string attackerAnimFolder, attackerAnimSuffix;
			float attakcerAnimSum;

			//AABB
			float offsetX, offsetY, width, height;

			//开始抵御者的信息初始化
			XML.setTo("attacker");

			if(XML.exists("a"))
			{
				if(XML.getName() == "attacker" && XML.setTo("a[0]"))
				{
					do
					{
						//单个trace只能提供给单一的attacker使用
						Floekr2T::trace tra;
						if(XML.exists("trace"))
						{
							XML.setTo("trace");

							//找到了起始点的设定
							if(XML.exists("start"))
							{
								XML.setTo("start");

								traceStart.x = XML.getValue<float>("x");
								traceStart.y = XML.getValue<float>("y");
								//在路径上添加起始点
								tra.setStartup(traceStart);

								XML.setToParent();
							}

							//开始路径转向
							if(XML.exists("t"))
							{
								//不断找寻转动方向
								if(XML.setTo("t[0]"))
								{
									do
									{
										mode = XML.getValue<int>("mode");
										distance = XML.getValue<float>("distance");

										//根据方位转动方位
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
							//获取移动速度值
							velocity = XML.getValue<float>("velocity");
						}

						if(XML.exists("HP"))
						{
							//获取移动速度值
							HP = XML.getValue<float>("HP");
						}

						if(XML.exists("animation"))
						{
							XML.setTo("animation");

							//帧动画 文件夹名 后缀名 帧数(快速导入帧动画文件)
							attackerAnimFolder = XML.getValue<string>("folder");
							attackerAnimSuffix = XML.getValue<string>("suffix");
							attakcerAnimSum = XML.getValue<float>("sum");

							//返回上一节点
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

						//直接新增一attacker
						Floekr2T::attacker attacker = attackerManager.createAttacker(tra, velocity, HP, 
							animationManager.createAnimation(attackerAnimFolder, attackerAnimSuffix, attakcerAnimSum));

						attacker.setAABB(offsetX, offsetY, width, height);
						//加入attacker工厂
						attackerManager.addAttacker(attacker);

					}while( XML.setToSibling());
				}
				XML.setToParent();
			}
			XML.setToParent();
		}

		//加载并读取成功
		return true;
	}

	//初始化场景
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
		//更新全部内容
		skillManager.update();

		attackerManager.update(skillManager.skills);

		defendorManager.update(attackerManager.attackers, skillManager);
	}

	void scene::draw()
	{
		//绘制全部内容
		skillManager.draw();

		attackerManager.draw();

		defendorManager.draw();
	}
}