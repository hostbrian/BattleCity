//
//  GameScene.cpp
//  BattleCity
//
//  Created by 袁文龙 on 14-8-30.
//
//

#include "GameScene.h"
#include "BaseMap.h"
#include "BulletLayer.h"
//#include "Config.inc.h"
#include "BouningBoxLayer.h"

void GameScene::onEnter(){
    Layer::onEnter();
    
    
}

bool GameScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    //加载背景色
    auto bg = LayerColor::create(Color4B(177, 177, 177, 255));
    this->addChild(bg,-1);
    
    //加载地图
    TITLEMAP = BaseMap::getInstance();
    this->addChild(TITLEMAP,0);
    
    //加载角色控制层
    auto _roleControl = RoleControl::getInstance();
    this->addChild(_roleControl);
    
    //加载子弹控制层
    auto _bullControl = BulletLayer::getInstance();
    this->addChild(_bullControl);
    
    //加载碰撞层
    auto _bouningBox = BouningBoxLayer::getInstanse();
    this->addChild(_bouningBox);
    
    //加载声音
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("02 start.aif");
    
    return true;
}


Scene * GameScene::createScene(){
    auto _scene = Scene::create();
    auto _layer = GameScene::create();
    _scene->addChild(_layer);
    return _scene;
}
