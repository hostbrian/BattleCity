#include "PlayerRole.h"
#include "BaseBullet.h"
#include "BulletLayer.h"

bool PlayerRole::init(){
	if (!Sprite::initWithFile("p1-a-cell.png")){
		return false;
	}

    this->setContentSize(Size(64,64));
	
    this->setBullType(1);
    
	return true;
}

void PlayerRole::fire(float t){
    BulletLayer::getInstance()->createPlayerBullet(this);
}

void PlayerRole::onEnter(){
	Sprite::onEnter();
    
    
    this->schedule(schedule_selector(PlayerRole::fire), 1);
    
    
	auto blink = Blink::create(3,7);
    
	this->runAction(blink);
    
	this->fire(0.0f);
}