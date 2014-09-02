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
    
    this->scheduleUpdate();
}

void BulletLayer::createEnemyBullet(BaseEnemyRole *player){
    auto bullet =  BaseBullet::create((Sprite*)player,"enemy");
    
    playerBullVector.pushBack(bullet);
    
    this->addChild(bullet);
}

void BulletLayer::createPlayerBullet(PlayerRole *player){
    auto bullet =  BaseBullet::create(player,"player");
    
    playerBullVector.pushBack(bullet);
    
    this->addChild(bullet);
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

void BulletLayer::update(float t){
//    for (auto &enemyBull : enemyBullVector) {
//        if (overScene(enemyBull->getPositionX(),enemyBull->getPositionY())) {
//            removeRole(enemyBull,"enemy");
//        }
//    }
//    
//    for (auto &playerull : playerBullVector) {
//        if (overScene(playerull->getPositionX(),playerull->getPositionY())) {
//            removeRole(playerull,"player");
//        }
//    }
}

bool BulletLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    return true;
}

void BulletLayer::removeRole(BaseBullet* _bullet,std::string type){
    if (type=="enemy") {
        enemyBullVector.eraseObject(_bullet);
    }else if (type =="player"){
        playerBullVector.eraseObject(_bullet);
    }
    _bullet->removeAllChildrenWithCleanup(true);
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