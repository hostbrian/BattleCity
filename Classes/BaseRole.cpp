#include "BaseRole.h"
//#include "Config.inc.h"
#include "BaseMap.h"
#include "RoleControl.h"

//#include "BulletLayer.h" 需要添加子弹类


void BaseRole::onEnter(){
    Sprite::onEnter();
    
    this->setDie(false);
    
    this->setAnchorPoint(Vec2(1,1));
    
    this->setContentSize(Size(32,32));
    
    this->setScale(0.7);
}

bool BaseRole::hurt(int hp) {
	this->HP -= hp;

	if(this->HP <= 0) {
		this->setDie(true);
		this->die();
		return true;
	}
	return false;
}

void BaseRole::die(){
    RoleControl::getInstance()->removeRole(this, this->getRoleType());
}

int BaseRole::getFace(){
    return face;
}

//受伤动画
ActionInterval * BaseRole::hitAnimate(){
    return RotateBy::create(0, 0);
}

bool BaseRole::getTypeForRectReturnBoll(Rect _rect){
    int type = BaseMap::getInstance()->getTypeForRect(_rect);
    if (type ==0 || type==3 || type==-1) {
        return true;
    }
    return false;
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

// 坦克移动总判断
bool BaseRole::canMoveInMap(){
	switch (this->face)
	{
	case LEFT:	
		return this->canLeftMoveInMap();
		break;
	case RIGHT:
		return this->canRightMoveInMap();
		break;
	case UP:
		return this->canUpMoveInMap();
		break;
	case DOWN:
		return this->canDownMoveInMap();
		break;
	default:
		return false;
	}
}

// 坦克左行 与 地图测试
bool BaseRole::canLeftMoveInMap(){
	auto MAP = BaseMap::getInstance();
	float originX = this->getBoundingBox().origin.x;
	float originY = this->getBoundingBox().origin.y;
	int pass = 0;		// 设置开关
	for (int i = 0; i < 2; i++){
		if (originX - 8.0f - i*16 <0){
			break; 
		}
//		log("%d",pass);
//		log("============================");
		for (int j = 0; j < 4; j++){
			if (originY+ tankSize.height/8 + j*(tankSize.height/4) >640.0f){
				break;
			}
			int type = MAP->getTypeForPoint(Vec2(originX - 8.0f - i*16 , originY+ tankSize.height/8 + j*(tankSize.height/4)));
			if (type ==0 || type == 3){
				pass++;
			}
		}
	}
	if (pass == 8 && this->getPositionX()>= DIS*2 /*与地图边界移动测试*/){
		return true;
	}else{
//		log("false");
		return false;
	}
}

// 坦克右行 与 地图测试
bool BaseRole::canRightMoveInMap(){
	auto MAP = BaseMap::getInstance();
	float maxX = this->getBoundingBox().getMaxX();
	float originY = this->getBoundingBox().origin.y;
	int pass = 0;
	for (int i = 0; i < 2; i++){
		if (maxX + 8.0f + i*16 >= 960.0f){
			break;
		}
		for (int j = 0; j < 4; j++){
			if (originY+ tankSize.height/8 + j*(tankSize.height/4) >640.0f){
				break;
			}
			int type = MAP->getTypeForPoint(Vec2(maxX + 8.0f + i*16 , originY+ tankSize.height/8 + j*(tankSize.height/4)));
			if (type ==0 || type == 3){
				pass++;
			}
		}
	}
	if (pass == 8 && this->getPositionX()<= (960 - DIS*2)){
		return true;
	}else{
		return false;
	}
}

// 坦克前行 与 地图测试
bool BaseRole::canUpMoveInMap(){
	auto MAP = BaseMap::getInstance();
	float originX = this->getBoundingBox().origin.x;
	float maxY = this->getBoundingBox().getMaxY();
	int pass = 0;
	for (int i = 0; i < 2; i++){
		if (maxY+ 8.0f + i*16 > 640.0f){
			break;
		}
		for (int j = 0; j < 4; j++){
			if (originX + tankSize.width/8 + j*(tankSize.width/4) >960.0f){
				break;
			}
			int type = MAP->getTypeForPoint(Vec2(originX + tankSize.width/8 + j*(tankSize.width/4) , maxY+ 8.0f + i*16));
			if (type ==0 || type == 3){
				pass++;
			}
		}
	}
	if (pass == 8 && this->getPositionY()<= (960 - DIS*2)){
		return true;
	}else{
		return false;
	}
}

// 坦克下行 与 地图测试
bool BaseRole::canDownMoveInMap(){
	auto MAP = BaseMap::getInstance();
	float originX = this->getBoundingBox().origin.x;
	float originY = this->getBoundingBox().origin.y;
	int pass = 0;
	for (int i = 0; i < 2; i++){
		if (originY- 8.0f - i*16 <0.0f){
			break;
		}
		for (int j = 0; j < 4; j++){
			if (originX + tankSize.width/8 + j*(tankSize.width/4) >960.0f){
				break;
			}
//			log("%.2f",originX);
//			log("%.2f",originY);
			int type = MAP->getTypeForPoint(Vec2(originX + tankSize.width/8 + j*(tankSize.width/4) , originY- 8.0f - i*16));
			if (type ==0 || type == 3){
				pass++;
			}
//			log("%d",pass);
//			log("==========================");
		}
	}
	if (pass == 8 && this->getPositionY() >= DIS*2 /* tankSize.height/2*/){
		return true;
	}else{
		return false;
	}
}

