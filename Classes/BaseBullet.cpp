#include "BaseBullet.h"
#include "ControlLayer.h"


void BaseBullet::onEnter(){
    Sprite::onEnter();
    
    
}

bool BaseBullet::init(int speed,int bulletState,const string fileName,Vec2 position,int bulletDir){
	if (!Sprite::initWithFile(fileName)){
		return false;
	}
    
    
	//设置子弹的位置
	this->setPosition(position);
    
	Size vsize = Director::getInstance()->getVisibleSize();
    
	//0,1,2,3分别为上，下，左，右
    Vec2 v2;
	float dis;
	if (bulletDir == 0)
	{
		dis = vsize.height-position.y;
        v2= Vec2(0, dis);
	}
	if (bulletDir == 1)
    {
		dis = position.y;
		v2 = Vec2(0,-position.y-this->getContentSize().height/2);
	}
	if (bulletDir == 2)
	{
		dis = position.x;
		v2 = Vec2(-position.x-this->getContentSize().width/2,0);
	}
	if (bulletDir == 3)
	{
		dis = vsize.width - position.x;
		v2 = Vec2(vsize.width-position.x+this->getContentSize().width/2,0);
	}
    
    
    auto _moveBy = MoveBy::create(dis/speed,v2);
    
    log("v2:{%.2f,%.2f}",v2.x,v2.y);
    log("子弹位置:{%.2f,%.2f},dis:%.2f,bulletDir:%d",this->getPositionX(),this->getPositionY(),dis,bulletDir);
	
    this->runAction(_moveBy);
    
	return true;
}

BaseBullet * BaseBullet::create(PlayerRole * _player,std::string type){
    auto bullet = BaseBullet::create(100,1,"Q3.png",_player->getPosition(),(int)_player->getDirection());
    bullet->setPlayer(_player);
    return bullet;
}

BaseBullet * BaseBullet::create(int speed,int bulletState,const string fileName,Vec2 v,int bulletDir){
	auto bullet = new BaseBullet();
	if (bullet && bullet->init(speed,bulletState,fileName,v,bulletDir))
	{
		bullet->autorelease();
		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return nullptr;
}