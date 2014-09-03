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
    
    
    createEnemyRole(Vec2(64 * 1, 640 * 1 ));
    createEnemyRole(Vec2(64 * 1, 640 * 1));
    
    createEnemyRole(Vec2(64 * 6, 640 * 1));
    createEnemyRole(Vec2(64 * 6, 640 * 1));
    
    createEnemyRole(Vec2(64 * 12, 640 * 1));
    createEnemyRole(Vec2(64 * 12, 640 * 1));
}

void RoleControl::createEnemyRole(const Vec2 &_vec2){
    unsigned int i;
    srand(i);
    
    int s = random()%5+1;
    
    BaseEnemyRole * _enemy;
    if (s >= 4) {
        _enemy = NormalTank::create();
    }else if (s >=3 && s<4){
        _enemy = FastTank::create();
    }else if (s <=2){
        _enemy = FatTank::create();
    }
    _enemy->setRoleType("enemy");
    _enemy->setPosition(_vec2);
    this->addChild(_enemy);
    enemyVector.pushBack((BaseRole*)_enemy);
}

void RoleControl::createPlayerRole(const Vec2 &_vec2){
    auto _player = PlayerRole::create();
    _player->setRoleType("player");
    _player->setPosition(Vec2(300,0));
    this->addChild(_player);
    playerVector.pushBack((BaseRole*)_player);
}

void RoleControl::removeRole(BaseRole* role,std::string type){
    
    role->stopAllActions();
    
    auto _animation = Animation::create();
    for (int i=1; i<9; i++) {
        std::string _filename = StringUtils::format("blast%d.png",i);
        auto _sp = SpriteFrameCache::getInstance()->getSpriteFrameByName(_filename);
        _animation->addSpriteFrame(_sp);
    }
    _animation->setDelayPerUnit(0.1);
    _animation->setLoops(1);
    auto _animate =Animate::create(_animation);
    auto _callfunc = CallFunc::create([=](){
        role->removeFromParentAndCleanup(true);
    });

    role->runAction(
          Sequence::create(_animate,_callfunc, NULL)
    );
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("blast.aif");
    
    if (type=="enemy") {
        enemyVector.eraseObject(role);
    }else if (type=="player"){
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
