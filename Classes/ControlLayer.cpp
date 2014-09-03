#include "ControlLayer.h"
#include "DirectionKey.h"
#include "PlayerRole.h"
#include "BaseMap.h"

#define MOVESTEP 32

bool ControlLayer::init(){
	if (!Layer::init())
	{
		return false;
	}

	vsize = Director::getInstance()->getVisibleSize();
    
    
	//创建玩家坦克
	tank = PlayerRole::create();
    tank->setAnchorPoint(Vec2(0.5,0.5));
	this->addChild(tank);
    
	tank->setPosition(320,32);
    
	//设置当前坦克状态为向上
	tank->setDirection(stateEnum::UP);
    
    
    
	//向控制层上添加方向键
	auto dirKey = DirectionKey::create();
    
    dirKey->setFire([=](){
        tank->addFire();
    });
    
    dirKey->role = tank;
    
    
	dirKey->setName("tank");
	
    dirKey->setPosition(120,150);
    
    
	//移动距离及方向的设置
	this->addChild(dirKey,10);
	
    
	tankMove();
	
	this->setName("ControlLayer");
	return true;
}

//坦克移动
void ControlLayer::tankMove(){
	
	auto dirKey = dynamic_cast<DirectionKey *>(this->getChildByName("tank"));
	
    Rect tankRect = tank->getBoundingBox();
    
	dirKey->setUp([=](){
		Point movePoint =  tank->getPosition();
        
        tank->setOpacity(255);

        tank->setRotation(0);
		tank->setDirection(stateEnum::UP);
        
        Rect tankRect = tank->getBoundingBox();
        
        Rect moveTargetRect = Rect(tankRect.origin.x, tankRect.origin.y+MOVESTEP,
                              tankRect.size.width, tankRect.size.height);
        if(!tank->getTypeForRectReturnBoll(moveTargetRect)){
            return;
        }
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.aif");
        
		if (movePoint.y >= 960 - tank->getContentSize().height/2){
			//movePoint.y = vsize.height - tank->getContentSize().height/2;
		}else{
            auto _moveBy = MoveBy::create(0.2, Vec2(0, MOVESTEP ) );
            auto _callfunc = CallFunc::create([=](){
                std::function<void ()> up = dirKey->getUp();
                up();
            });
            
            tank->runAction(Sequence::create(_moveBy,_callfunc, NULL));
        }

	});

	dirKey->setDown([=](){
		Point movePoint = tank->getPosition();
        
        tank->setOpacity(255);
        
        tank->setRotation(180);
		tank->setDirection(stateEnum::DOWN);
        
        Rect tankRect = tank->getBoundingBox();
        
        Rect moveTargetRect = Rect(tankRect.origin.x, tankRect.origin.y-MOVESTEP,
                                   tankRect.size.width, tankRect.size.height);
        if(!tank->getTypeForRectReturnBoll(moveTargetRect)){
            return;
        }
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.aif");
        
		if (movePoint.y <=tank->getContentSize().height/2)
		{
			//movePoint.y = vsize.height - tank->getContentSize().height/2;
		}else{
            auto _moveBy = MoveBy::create(0.2, Vec2(0, -MOVESTEP ) );
            auto _callfunc = CallFunc::create([=](){
                std::function<void ()> down = dirKey->getDown();
                down();
            });
            
            tank->runAction(Sequence::create(_moveBy,_callfunc, NULL));
		}

	});

	dirKey->setLeft([=](){
		Point movePoint = tank->getPosition();
        
        tank->setOpacity(255);
        
        tank->setRotation(270);
		tank->setDirection(stateEnum::LEFT);
        
        Rect tankRect = tank->getBoundingBox();
        
        Rect moveTargetRect = Rect(tankRect.origin.x-MOVESTEP, tankRect.origin.y,
                                   tankRect.size.width, tankRect.size.height);
        if(!tank->getTypeForRectReturnBoll(moveTargetRect)){
            return;
        }
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.aif");
        
		if (movePoint.x <=tank->getContentSize().width/2){
		}else{
            auto _moveBy = MoveBy::create(0.2, Vec2(-MOVESTEP, 0 ) );
            auto _callfunc = CallFunc::create([=](){
                std::function<void ()> left = dirKey->getLeft();
                left();
            });
            
            tank->runAction(Sequence::create(_moveBy,_callfunc, NULL));
		}

	});

	dirKey->setRight([=](){
		Point movePoint = tank->getPosition();
        
        tank->setOpacity(255);
        
        tank->setRotation(90);
		tank->setDirection(stateEnum::RIGHT);
        
        Rect tankRect = tank->getBoundingBox();
        
        Rect moveTargetRect = Rect(tankRect.origin.x+ MOVESTEP, tankRect.origin.y,
                                   tankRect.size.width, tankRect.size.height);
        if(!tank->getTypeForRectReturnBoll(moveTargetRect)){
            return;
        }
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.aif");
        
		if (movePoint.x >= 960 -tank->getContentSize().width){
		}else{
            auto _moveBy = MoveBy::create(0.2, Vec2(MOVESTEP, 0 ) );
            auto _callfunc = CallFunc::create([=](){
                std::function<void ()> right = dirKey->getRight();
                right();
            });
            
            tank->runAction(Sequence::create(_moveBy,_callfunc, NULL));
		}
        
	});
}

Layer * ControlLayer::getControlLayer(){
	auto layer = dynamic_cast<Layer *>(this->getChildByName("ControlLayer"));
	return layer;
}

