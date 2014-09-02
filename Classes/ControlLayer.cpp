#include "ControlLayer.h"
#include "DirectionKey.h"
#include "PlayerRole.h"
#include "BaseMap.h"

bool ControlLayer::init(){
	if (!Layer::init())
	{
		return false;
	}

	//加载地图

	vsize = Director::getInstance()->getVisibleSize();
	//创建坦克
	tank = PlayerRole::create();
	this->addChild(tank);
	tank->setPosition(440,20);
	//设置当前坦克状态为向上
	tank->setDirection(stateEnum::UP);

	//向控制层上添加方向键
	auto dirKey = DirectionKey::create();
	dirKey->setName("tank");
	dirKey->setPosition(920,150);
	//移动距离及方向的设置
	this->addChild(dirKey,10);
	
	tankMove();
	
	this->setName("ControlLayer");
	return true;
}
//坦克移动
void ControlLayer::tankMove(){
	
	auto dirKey = dynamic_cast<DirectionKey *>(this->getChildByName("tank"));
	
	dirKey->setUp([&](){
		Point movePoint = tank->getPosition();
		if (movePoint.y >=this->getBoundingBox().getMaxY() - tank->getContentSize().height/2)
		{
			//movePoint.y = vsize.height - tank->getContentSize().height/2;
		}else
		{
			tank->setPositionY(tank->getPositionY() + 3);
		}
		tank->setRotation(0);
		tank->setDirection(stateEnum::UP);
			
		
		//tank->setPosition(movePoint);
	});

	dirKey->setDown([&](){
		Point movePoint = tank->getPosition();
		if (movePoint.y <=tank->getContentSize().height/2)
		{
			//movePoint.y = vsize.height - tank->getContentSize().height/2;
		}else{
			tank->setPositionY(tank->getPositionY() - 3);	
		}
		tank->setRotation(180);
		tank->setDirection(stateEnum::DOWN);
		
	});

	dirKey->setLeft([&](){	
		Point movePoint = tank->getPosition();
		if (movePoint.x <=tank->getContentSize().width/2)
		{
		}else
		{
			tank->setPositionX(tank->getPositionX() - 3);
		}

		tank->setRotation(270);
		tank->setDirection(stateEnum::LEFT);
		
	});

	dirKey->setRight([&](){
		Point movePoint = tank->getPosition();
		if (movePoint.x >= vsize.width -tank->getContentSize().width/2)
		{
		}else
		{
			tank->setPositionX(tank->getPositionX() + 3);
		}
		tank->setRotation(90);
		tank->setDirection(stateEnum::RIGHT);
		
	});

	
}
Layer * ControlLayer::getControlLayer(){
	auto layer = dynamic_cast<Layer *>(this->getChildByName("ControlLayer"));
	return layer;
}