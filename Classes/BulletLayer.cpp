//
//  BulletLayer.cpp
//  BattleCity
//
//  Created by 袁文龙 on 14-9-2.
//
//

#include "BulletLayer.h"
#include "PlayerRole.h"
#include "BaseEnemy.h"

BulletLayer* BulletLayer::instance = nullptr;

void BulletLayer::onEnter(){
    Layer::onEnter();
    
}

void BulletLayer::createEnemyBullet(BaseRole *player){
    auto bullet =  BaseBullet::create(player,"enemy");
    
    enemyBullVector.pushBack(bullet);
    
    this->addChild(bullet);
}

void BulletLayer::createPlayerBullet(BaseRole *player){
    if(playerBullVector.size() < 3){
        auto bullet =  BaseBullet::create(player,"player");
            
        playerBullVector.pushBack(bullet);
        
        this->addChild(bullet);
    }
}

bool overScene(float xx, float yy){
    if (xx > 960 && xx <0) {
        return false;
    }
    
    if (yy >640 && yy < 0) {
        return false;
    }
    return true;
}


bool BulletLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    return true;
}

void BulletLayer::removeBullet(BaseBullet* _bullet,std::string type){
    if (type=="enemy") {
        enemyBullVector.eraseObject(_bullet);
        
        if (!_bullet->getPlayer()->getDie()) {
            BulletLayer::getInstance()->createEnemyBullet(_bullet->getPlayer());
        }
                
    }else if (type =="player"){
        playerBullVector.eraseObject(_bullet);
    }
    _bullet->removeFromParentAndCleanup(true);
}

BulletLayer * BulletLayer::getInstance(){
    if(!instance)
	{
        instance = new BulletLayer();
        instance->init();
        instance->autorelease();
	}
	return instance;
}