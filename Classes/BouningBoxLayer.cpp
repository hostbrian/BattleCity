//
//  BouningBoxLayer.cpp
//  BattleCity
//
//  Created by 袁文龙 on 14-9-1.
//
//

#include "BouningBoxLayer.h"
#include "BulletLayer.h"
#include "RoleControl.h"
#include "BaseMap.h"

BouningBoxLayer * BouningBoxLayer::instance=0;
bool BouningBoxLayer::init(){
    if(!Layer::init()){
        return false;
    }
    
    this->scheduleUpdate();
    return true;
}

BouningBoxLayer* BouningBoxLayer::getInstanse(){
    if(!instance)
	{
        instance = new BouningBoxLayer();
        instance->init();
        instance->autorelease();
	}
	return instance;
}

void BouningBoxLayer::update(float t){
    
    Vector<BaseBullet *> enemyBulletVector = BulletLayer::getInstance()->getEnemyBulletVector();
    Vector<BaseBullet *> playerBulletVector = BulletLayer::getInstance()->getPlayerBulletVector();
    
    Vector<BaseRole *> enemyVector = RoleControl::getInstance()->getEnemyVector();
    Vector<BaseRole *> playerVector = RoleControl::getInstance()->getPlayerVector();
    
    //敌人子弹碰撞
    for (auto &enemyBullet:enemyBulletVector) {
        
        auto _break = false;
        
        //与主角子弹
        for (auto &playerBullet:playerBulletVector) {
            if ( enemyBullet->getBoundingBox().intersectsRect(playerBullet->getBoundingBox()) ) {
                BulletLayer::getInstance()->removeBullet(enemyBullet, "enemy");
                BulletLayer::getInstance()->removeBullet(playerBullet, "player");
                enemyBulletVector.eraseObject(enemyBullet);
                
                _break = true;
                break;
            }
        }
        
        if (_break) {
            break;
        }

        //与主角
        for (auto &player:playerVector) {
            if (enemyBullet->getBoundingBox().intersectsRect(player->getBoundingBox())) {
                BulletLayer::getInstance()->removeBullet(enemyBullet, "enemy");
                player->hurt(1);
                
                _break = true;
                break;
            }
        }
        
        if (_break) {
            break;
        }

        //与建筑物
        int getFace = enemyBullet->getPlayer()->getFace();
        Rect _BulletRect;
        if(getFace==0 && getFace==1  ){
             _BulletRect = Rect(enemyBullet->getPositionX() ,enemyBullet->getPositionY(),
                                    32,16
                                    );
        }else{
            _BulletRect = Rect(enemyBullet->getPositionX() ,enemyBullet->getPositionY(),
                                    16,32
                                    );
        }
        int titleType = BaseMap::getInstance()->getTypeForRect(_BulletRect);
        if (titleType == 1) {
            BaseMap::getInstance()->removeObjectForRect(_BulletRect);
            BulletLayer::getInstance()->removeBullet(enemyBullet, "enemy");
        }else if (titleType == 2){
            BulletLayer::getInstance()->removeBullet(enemyBullet, "enemy");
        }
        
    }
    
    //玩家子弹
    for (auto &playerBullet:playerBulletVector) {
        auto _break = false;

        //与敌人
        for (auto &enemy:enemyVector) {
            if (!enemy->getDie() && enemy->getBoundingBox().intersectsRect(playerBullet->getBoundingBox())  ) {
                enemy->hurt(1);
                BulletLayer::getInstance()->removeBullet(playerBullet, "player");
                playerBulletVector.eraseObject(playerBullet);
                
                _break = true;
                break;
            }
        }
        
        if (_break) {
            break;
        }
        
        //与建筑物
        int titleType = BaseMap::getInstance()->getTypeForRect(playerBullet->getBoundingBox());
        if (titleType == 1) {
            BaseMap::getInstance()->removeObjectForRect(playerBullet->getBoundingBox());
            BulletLayer::getInstance()->removeBullet(playerBullet, "player");
        }else if (titleType == 2){
            BulletLayer::getInstance()->removeBullet(playerBullet, "player");
        }
    }
    
}

