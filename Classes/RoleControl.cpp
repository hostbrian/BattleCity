//
//  RoleControl.cpp
//  BattleCity
//
//  Created by 袁文龙 on 14-9-2.
//
//

#include "RoleControl.h"
#include "FastTank.h"
#include "FatTank.h"
#include "NormalTank.h"
#include "PlayerRole.h"
#include "ControlLayer.h"

RoleControl* RoleControl::instance = nullptr;

void RoleControl::onEnter(){
    Layer::onEnter();
    
    auto _control = ControlLayer::create();
    this->addChild(_control,10);
    
    
    createEnemyRole(Vec2(64, 640-32));
//    createEnemyRole(Vec2(264, 640-32));
//    createEnemyRole(Vec2(564, 640-32));
}

void RoleControl::createEnemyRole(const Vec2 &_vec2){
    auto _enemy = NormalTank::create();
    _enemy->setPosition(_vec2);
    this->addChild(_enemy);
    enemyVector.pushBack((BaseRole*)_enemy);
}

void RoleControl::createPlayerRole(const Vec2 &_vec2){
    auto _player = PlayerRole::create();
    _player->setPosition(Vec2(300,0));
    this->addChild(_player);
    playerVector.pushBack((BaseRole*)_player);
}

void RoleControl::removeRole(BaseRole* role,std::string type){
    if (type=="enemy") {
        role->removeAllChildrenWithCleanup(true);
        enemyVector.eraseObject(role);
    }else if (type=="player"){
        role->removeAllChildrenWithCleanup(true);
        playerVector.eraseObject(role);
        
        //发送游戏获胜信息
        
    }
}

RoleControl * RoleControl::getInstance(){
    if(!instance)
	{
        instance = new RoleControl();
        instance->init();
        instance->autorelease();
	}
	return instance;
}

bool RoleControl::init(){
    if (!Layer::init()) {
        return false;
    }
    return true;
}
