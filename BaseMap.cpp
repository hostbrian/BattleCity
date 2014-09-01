//
//  BaseMap.cpp
//  BattleCity
//
//  Created by 袁文龙 on 14-8-30.
//
//

#include "BaseMap.h"
#include "VisibleRect.h"

BaseMap * BaseMap::_baseMap=0;
bool BaseMap::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto _bg = LayerColor::create(Color4B(0, 0, 0, 255),960,640);
    _bg->setPosition(VisibleRect::bottom());
    _bg->setPositionX(0);
    this->addChild(_bg,-1);
    
    
    tileMap = TMXTiledMap::create("tiledMap.tmx");
    this->addChild(tileMap,0);
    
    
    return true;
}

int BaseMap::getTypeForPoint(Vec2 _vec2){
    auto tileLayer = tileMap->getLayer("BG");
    
    _vec2 = Director::getInstance()->convertToUI(_vec2) / 16;
    
    _vec2 = Vec2((int)_vec2.x,(int)_vec2.y);
    
    int gid = tileLayer->getTileGIDAt(_vec2,nullptr);
    
    
    int type=0;
    if(gid == 1 || gid ==2 || gid == 15 || gid ==16){
        type=1;
        
    }else if(gid == 3 || gid ==4 || gid == 17 || gid ==18){
        type=2;
        
    }else if(gid == 5 || gid ==6 || gid == 19 || gid ==20){
        type=3;
        
    }else if( (gid >= 7 && gid <=10) || (gid >= 21 && gid <=24) ){
        type=4;
        
    }else if(gid == 11 || gid ==12 || gid == 25 || gid ==26 ){
        type=5;
        
    }else if(gid == 13 || gid ==14 || gid == 27 || gid ==28 ){
        type=6;
        
    }
    
    return type;
}

BaseMap * BaseMap::getInstance(){
    if (!_baseMap) {
        _baseMap = new BaseMap();
        _baseMap->init();
        _baseMap->autorelease();
        
    }
    return _baseMap;
}

Scene * BaseMap::createScene(){
    auto _scene = Scene::create();
    auto _layer = BaseMap::create();
    _scene->addChild(_layer);
    return _scene;
}

