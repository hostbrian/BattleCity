#include "DirectionKey.h"

bool DirectionKey::init(){
	if (!Layer::init())
	{
		return false;
	}
	createDir();
	return true;
}

bool checkKey(Rect a, Vec2 b){
    if (a.containsPoint(b)) {
        return true;
    }
    return false;
}

void DirectionKey::checkKeyToMove(Vec2 b){
    
    Rect _up = Rect(79, 190, 80, 80);
    Rect _down = Rect(82, 22, 80, 80);
    Rect _left = Rect(7, 108, 80, 80);
    Rect _right = Rect(162, 113, 80, 80);
    
    Rect _fire = Rect(900,72,100,100);
    
    if ( checkKey(_up, b) ) {
        up();
    }else if ( checkKey(_down, b) ){
        down();
    }else if ( checkKey(_left, b) ){
        left();
    }else if ( checkKey(_right, b) ){
        right();
    }else if ( checkKey(_fire, b) ){
        fire();
    }
}

void DirectionKey::createDir(){
    
    auto _btnSprite = Sprite::create("ui_dpad.png");
    this->addChild(_btnSprite);
    

    auto _listen = EventListenerTouchOneByOne::create();
    _listen->onTouchBegan = [=](Touch *_touch,Event *_event)->bool{
        
        Vec2 b = _touch->getLocation();
        
        role->stopAllActions();
        checkKeyToMove(b);

        return true;
    };
    
    _listen->onTouchMoved = [=](Touch *_touch,Event *_event){
        Vec2 b = _touch->getLocation();
        
        role->stopAllActions();
        checkKeyToMove(b);
    };
    
    _listen->onTouchEnded = [=](Touch *_touch,Event *_event){
        Vec2 b = _touch->getLocation();
        
        role->stopAllActions();
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listen, this);
    
    
    auto _fireSprite = Sprite::create("ui_back_click.png");
    _fireSprite->setPosition(820, 0);
    this->addChild(_fireSprite);
    
    return;
    
}