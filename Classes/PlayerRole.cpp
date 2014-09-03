#include "PlayerRole.h"
#include "BaseBullet.h"
#include "BulletLayer.h"

bool PlayerRole::init(){
	if (!BaseRole::initWithSpriteFrameName("p1tank.png")){
		return false;
	}
    
    this->speed = 300;
    
    this->setRoleType("player");
    
	
    this->setBullType(1);
    
	return true;
}

int PlayerRole::getFace(){
    return (int)direction;
}

void PlayerRole::die(){
    ;
}

void PlayerRole::setState(ROLE_STATE state){
    
}

void PlayerRole::addFire(){
    addFire(0.0f);
}

void PlayerRole::addFire(float t){
    BulletLayer::getInstance()->createPlayerBullet(this);
}

void PlayerRole::onEnter(){
	BaseRole::onEnter();
    
//	auto blink = Blink::create(3,7);
//    
//	this->runAction(blink);
    
}