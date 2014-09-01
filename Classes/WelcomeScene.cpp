//
//  WelcomeScene.cpp
//  BattleCity
//
//  Created by 袁文龙 on 14-8-30.
//
//

#include "WelcomeScene.h"
#include "Config.inc.h"
#include "VisibleRect.h"
#include "GameScene.h"

void WelcomeScene::onEnter(){
    Layer::onEnter();
    
    auto bg = Sprite::createWithSpriteFrameName("BattleCity.png");
    bg->setPosition(VisibleRect::bottom());
    bg->setScale(2);
    this->addChild(bg);
    
    
    auto item1 = MenuItemFont::create("进入游戏", [=](Ref*ref){
        auto _scene = GameScene::createScene();
        Director::getInstance()->replaceScene(_scene);
    });
    item1->setPosition(VisibleRect::center());
    item1->setPositionY(item1->getPositionY()-100);
    auto _menu = Menu::create(item1,NULL);
    _menu->setPosition(0,0);
    _menu->setVisible(false);
    this->addChild(_menu);
    
    auto _moveBy = MoveBy::create(1, Vec2(0, 400));
    auto _callFunc = CallFuncN::create([=](Ref*ref){
            _menu->setVisible(true);
    });
    bg->runAction(Sequence::create(_moveBy,_callFunc, NULL));
    
    
    
    
}
void WelcomeScene::onMenuTouch(Ref*ref){
    
}
bool WelcomeScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    //加载素材
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("tankedazhan.plist");
    
    MUSIC_CONFIG mc;
    //加载音乐缓存
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(mc.GAME_START.c_str() );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(mc.ADDLIFE.c_str() );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(mc.BLAST.c_str() );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(mc.BULLET.c_str() );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(mc.GAMEOVER.c_str() );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(mc.MOVE.c_str() );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(mc.BOMB.c_str() );
    
    return true;
}


Scene * WelcomeScene::createScene(){
    auto _scene = Scene::create();
    auto _layer = WelcomeScene::create();
    _scene->addChild(_layer);
    return _scene;
}

