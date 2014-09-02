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
#include "Config.inc.h"

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
    
//    auto _listen = EventListenerTouchOneByOne::create();
//    _listen->onTouchBegan = [=](Touch *_touch,Event *_event)->bool{
//        //auto i =
////        BaseMap::getInstance()->removeObject(_touch->getLocation());
//        //log("%d",i);
//        return true;
//    };
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listen, this);
//    
    
    //加载声音
    MUSIC_CONFIG mc;
    //加载声音
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(mc.GAME_START.c_str());
    
    return true;
}


Scene * GameScene::createScene(){
    auto _scene = Scene::create();
    auto _layer = GameScene::create();
    _scene->addChild(_layer);
    return _scene;
}
