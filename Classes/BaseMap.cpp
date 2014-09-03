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

Vec2 fixVec2(Vec2 _vec2){
    if (_vec2.y >= 640 -16) {
        _vec2.y = 640 -16;
    }
    if (_vec2.y <=1 ) {
        _vec2.y = 16;
    }
    if (_vec2.x >= 960-16) {
        _vec2.x = 960 - 16;
    }
    if (_vec2.x <= 16) {
        _vec2.x =16;
    }
    return _vec2;
}

int BaseMap::getTypeForPoint(Vec2 _vec2){
    auto tileLayer = tileMap->getLayer("BG");
    
    
    _vec2 = fixVec2(_vec2);
    
    
    _vec2 = Director::getInstance()->convertToUI(_vec2) / 16;
    
    _vec2 = Vec2((int)_vec2.x,(int)_vec2.y);
    if(_vec2.x < 0 || _vec2.y < 0){
        return -1;
    }
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

int BaseMap::getTypeForRect(Rect _rect){
    int justReturn1and2 = -1;
    for (float x = _rect.getMinX(); x <= _rect.getMaxX(); x += 15 ) {
        for (float y = _rect.getMinY(); y<= _rect.getMaxY(); y+=15 ) {
            Vec2 _vec2 = Vec2(x,y);
            int type = getTypeForPoint(_vec2);
            if (type == 1 || type==2) {
                justReturn1and2 = type;
                break;
            }
        }
        if (justReturn1and2  != -1) {
            break;
        }
    }
    return justReturn1and2;
}

void BaseMap::removeObjectForPoint(Vec2 _vec2){
    auto tileLayer = tileMap->getLayer("BG");
    
    
    _vec2 = fixVec2(_vec2);
    
    int type = getTypeForPoint(_vec2);
    if( type != 1 && type !=2 ){
        return;
    }
    
    _vec2 = Director::getInstance()->convertToUI(_vec2) / 16;
    
    _vec2 = Vec2((int)_vec2.x,(int)_vec2.y);
    
    auto _sprite = (Sprite *)tileLayer->getTileAt(_vec2);
    
    if(_sprite){
        tileLayer->removeChild(_sprite, true);
    }
}

void BaseMap::removeObjectForRect(Rect _rect){
    
    for (float x = _rect.getMinX(); x <= _rect.getMaxX(); x += 15 ) {
        for (float y = _rect.getMinY(); y<= _rect.getMaxY(); y+=15 ) {
            Vec2 _vec2 = Vec2(x,y);
            removeObjectForPoint(_vec2);
        }
    }

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

