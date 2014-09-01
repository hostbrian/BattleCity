#include "BaseRole.h"
#include "Config.inc.h"

//#include "BulletLayer.h" 需要添加子弹类

bool BaseRole::initWithSpriteFrameName(std::string fileName,int HP,int Speed,int count,int state){
    if (!Sprite::initWithSpriteFrameName(fileName)) {
        return false;
    }
    
	//传入血量值
	this->HP = HP;
	//传入速度值
	this->Speed = Speed;
    
	//目前状态，死亡 或者存活
	this->state = ROLE_STATE::NORMAL;
    
	return true;
}

//void BaseRole::onEnter(){
//    Sprite::onEnter();
//    //设置回调发射子弹
//    this->schedule(schedule_selector(BaseRole::addFire),0.2);
//}

void BaseRole::addFire(float t){
    Vec2 v = Vec2(this->getPositionX(), this->getPositionY()+this->getContentSize().height/2);
	//缺少子弹的create，需要通过子弹类创建
}

bool BaseRole::hurt(int hp) {
	this->HP -= hp;
	auto hit = this->hitAnimate();
	this->runAction(hit);
	if(this->HP <= 0) {
        //发送死亡通知
        auto center = __NotificationCenter::getInstance();
        center->postNotification("EnemyDie", this);
        
		this->setDie(true);
		this->die();
		return true;
	}
	return false;
}
//受伤动画
ActionInterval * BaseRole::hitAnimate(){
    return RotateBy::create(0, 0);
}
void BaseRole::dieAnimation(const char * fileName,int count){
    //死亡动画前停止移动动画
    this->stopAllActions();
    //运行死亡动画
    auto ani = Animation::create();
    for (int i = 1 ; i <= count; i++) {
        auto str = StringUtils::format(fileName,i);
        auto sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        ani->addSpriteFrame(sf);
    }
    ani->setDelayPerUnit(0.1);
    ani->setLoops(1);
    //死亡完成,移除对象
    auto cf = CallFunc::create(std::bind(&BaseRole::remove, this));

    
    this->runAction(Sequence::create(Animate::create(ani),cf, NULL));
}

void BaseRole::remove(){
    this->setDie(true);
    this->removeFromParentAndCleanup(true);
}



