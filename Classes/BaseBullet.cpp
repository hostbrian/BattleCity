#include "BaseBullet.h"
#include "ControlLayer.h"
#include "BulletLayer.h"


void BaseBullet::onEnter(){
    Sprite::onEnter();
    
    this->setContentSize(Size(32,32));
}

bool BaseBullet::init(int speed,int bulletState,const string fileName, BaseRole * player){
    
	if (!Sprite::initWithSpriteFrameName(fileName)){
		return false;
	}
    
    speed = 300;
    
    int roleDirection = 0;
    Vec2 position = player->getPosition();
	Size vsize = Director::getInstance()->getVisibleSize();
    vsize.width = 960;
    
    this->setPlayer(player);
    this->type = player->getRoleType();
    
    
    this->setContentSize(Size(32,32));
    
    
	//设置子弹的位置
	this->setPosition(player->getPositionX(),
                      player->getPositionY()
                      );
    
    roleDirection = this->player->getFace();

    if (player->getRoleType() == "enemy") {
    }else if (player->getRoleType() == "player"){
        roleDirection = this->player->getFace();
    }
    
	//0,1,2,3分别为上，下，左，右
    Vec2 v2;
	float dis;
    
	if (roleDirection == 0)
	{//上
		dis = vsize.height-position.y;
        v2= Vec2(player->getPositionX(), vsize.height);
	}else if (roleDirection == 1)
    {//下
        this->setRotation(180);
		dis = position.y;
		v2 = Vec2(player->getPositionX(),0);
	}else if (roleDirection == 2)
	{//左
        this->setRotation(270);
		dis = position.x;
		v2 = Vec2(0,player->getPositionY());
	}else if (roleDirection == 3)
	{//右
        this->setRotation(90);
		dis = vsize.width - position.x;
		v2 = Vec2(vsize.width,player->getPositionY());
	}
    
    float _time = dis/speed;
    if (_time <=0) {
        _time = 0.1f;
    }
//    log("_time:%.2f,dis:%.2f,speed:%d",_time,dis,speed);
    auto _moveTo = MoveTo::create(_time,v2);
    auto _callfun = CallFunc::create([=](){
        
        BulletLayer::getInstance()->removeBullet(this, this->type);
        
    });
    
    auto _delayTime = DelayTime::create(_time);

    this->runAction(
          Sequence::create(_moveTo,_callfun, NULL)
    );
    
    this->runAction(Sequence::create(_delayTime,_callfun, NULL));
    
	return true;
}

BaseBullet * BaseBullet::create(BaseRole * _player,std::string type){
    
    //子弹的声音
    //CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bullet.aif");

    auto bullet = BaseBullet::create(300,1,"bullet.png",_player);
    return bullet;
}

BaseBullet * BaseBullet::create(int speed,int bulletState,const string fileName,BaseRole * _player){
	auto bullet = new BaseBullet();
	if (bullet && bullet->init(speed,bulletState,fileName,_player))
	{
		bullet->autorelease();
		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return nullptr;
}