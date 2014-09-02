#include "BaseEnemy.h"
#include "BaseMap.h"
#include "BulletLayer.h"

// init 初始化
bool BaseEnemyRole::init(std::string fileName, int hp, int speed){
	if (!Sprite::initWithSpriteFrameName(fileName))
	{
		return false;
	}

	// 成员变量赋初值
	this->HP = hp;
	this->speed = speed;
	this->enemySize = Size(64.0, 64.0f);
	this->dis = DIS;
	this->moveV = Vec2(0.0f, 0.0f);
    
    
	return true;
}

// onEnter
void BaseEnemyRole::onEnter(){
	Sprite::onEnter();

	//设置回调，发射子弹
	this->schedule(schedule_selector(BaseEnemyRole::addFire),0.15);
	// 敌机移动
	this->beginMove();
}

// 敌机攻击
void BaseEnemyRole::addFire(float t){
	//创建子弹自动发射
    
    BulletLayer::getInstance()->createEnemyBullet(this);
    
}

// 受到伤害
void BaseEnemyRole::getHurt(int attackPower){
	propAdd = true;
	if (ispropTank)
	{
		// 产生道具
	}
}

// 坦克初始化后开始移动
void BaseEnemyRole::beginMove(){
	//********** 设置初始化方向
	// face direction rate 正面朝向的概率==============设计有待斟酌 和 改正========
	int dirRate = rand() % 9 +1;
	// face down
	if (dirRate <= 4) {this->face = DOWN;	this->setRotation(180.0f); }
	// face left 
	if (dirRate > 4 && dirRate <=7 ) {this->face = LEFT;	this->setRotation(-90.0f);}
	// face right
	if (dirRate > 7) {this->face = RIGHT;	this->setRotation(90.0f);}

	// 移动开始
	this->move();
}

// 设置移动方向
void BaseEnemyRole::setFace(){
	int dirRate = rand() % 9 +1;
	// face down
	if (dirRate <= 2) {this->face = DOWN;	this->setRotation(180.0f); }
	// face up
	if (dirRate > 2 && dirRate <=4) {this->face = UP;	this->setRotation(0.0f); }
	// face left 
	if (dirRate > 4 && dirRate <=7 ) {this->face = LEFT;	this->setRotation(-90.0f);}
	// face right
	if (dirRate > 7) {this->face = RIGHT;	this->setRotation(90.0f);}
}

// 坦克移动 
void BaseEnemyRole::move(){
//    log("根据方向判断能否移动");
    this->stopAllActions();
    
	// 根据方向判断能否移动
	if (this->canMoveInMap()){
		switch (this->face)
		{
		case LEFT:
			this->moveLeft();
			//this->move();
			break;
		case RIGHT:
			this->moveRight();
			//this->move();
			break;
		case UP:
			this->moveUp();
			//this->move();
			break;
		case DOWN:
			this->moveDown();
			//this->move();
			break;
		default:
			break;
		}
	}else{

		// 重新选择方向
		this->setFace();
		this->move();
	}
}

// 坦克移动总判断
bool BaseEnemyRole::canMoveInMap(){
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

// 坦克左行
void BaseEnemyRole::moveLeft(){
    this->stopAllActions();
    
    moveV = Vec2(-DIS, 0);

	auto moveBy = MoveBy::create( DIS/speed, moveV);
	auto func =CallFunc::create( CC_CALLBACK_0(BaseEnemyRole::move,this) );
    
	this->runAction(Sequence::create(moveBy,func,NULL));
}

// 坦克右行
void BaseEnemyRole::moveRight(){
    this->stopAllActions();
    
    moveV = Vec2(+DIS, 0);

	auto moveBy = MoveBy::create( DIS/speed, moveV);
	auto func = CallFuncN::create([=](Node*node){
		this->move();
	});
	this->runAction(Sequence::create(moveBy,func,NULL));

}

// 坦克前行
void BaseEnemyRole::moveUp(){
    this->stopAllActions();
    
    moveV = Vec2(0, +DIS);

	auto moveBy = MoveBy::create( DIS/speed, moveV);
	auto func = CallFuncN::create([=](Node*node){
		this->move();
	});
	this->runAction(Sequence::create(moveBy,func,NULL));

}

// 坦克下行
void BaseEnemyRole::moveDown(){
    this->stopAllActions();
    
    moveV = Vec2(0, -DIS);

	auto moveBy = MoveBy::create( DIS/speed , moveV);
	auto func = CallFuncN::create([=](Node*node){
		this->move();
	});
	this->runAction(Sequence::create(moveBy,func,NULL));

}

// 坦克左行 与 地图测试
bool BaseEnemyRole::canLeftMoveInMap(){
	auto MAP = BaseMap::getInstance();
	float originX = this->getBoundingBox().origin.x;
	float originY = this->getBoundingBox().origin.y;
	int pass = 0;		// 设置开关
	for (int i = 0; i < 2; i++){
		if (originX - 8.0f - i*16 <0){
			break; 
		}
//		log("canLeftMoveInMap:%d",pass);
//		log("============================");
		for (int j = 0; j < 4; j++){
			if (originY+ enemySize.height/8 + j*(enemySize.height/4) >640.0f){
				break;
			}
			int type = MAP->getTypeForPoint(Vec2(originX - 8.0f - i*16 , originY+ enemySize.height/8 + j*(enemySize.height/4)));
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
bool BaseEnemyRole::canRightMoveInMap(){
	auto MAP = BaseMap::getInstance();
	float maxX = this->getBoundingBox().getMaxX();
	float originY = this->getBoundingBox().origin.y;
	int pass = 0;
	for (int i = 0; i < 2; i++){
		if (maxX + 8.0f + i*16 >= 960.0f){
			break;
		}
		for (int j = 0; j < 4; j++){
			if (originY+ enemySize.height/8 + j*(enemySize.height/4) >640.0f){
				break;
			}
			int type = MAP->getTypeForPoint(Vec2(maxX + 8.0f + i*16 , originY+ enemySize.height/8 + j*(enemySize.height/4)));
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
bool BaseEnemyRole::canUpMoveInMap(){
	auto MAP = BaseMap::getInstance();
	float originX = this->getBoundingBox().origin.x;
	float maxY = this->getBoundingBox().getMaxY();
	int pass = 0;
	for (int i = 0; i < 2; i++){
		if (maxY+ 8.0f + i*16 > 640.0f){
			break;
		}
		for (int j = 0; j < 4; j++){
			if (originX + enemySize.width/8 + j*(enemySize.width/4) >960.0f){
				break;
			}
			int type = MAP->getTypeForPoint(Vec2(originX + enemySize.width/8 + j*(enemySize.width/4) , maxY+ 8.0f + i*16));
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
bool BaseEnemyRole::canDownMoveInMap(){
	auto MAP = BaseMap::getInstance();
	float originX = this->getBoundingBox().origin.x;
	float originY = this->getBoundingBox().origin.y;
	int pass = 0;
	for (int i = 0; i < 2; i++){
		if (originY- 8.0f - i*16 <0.0f){
			break;
		}
		for (int j = 0; j < 4; j++){
			if (originX + enemySize.width/8 + j*(enemySize.width/4) >960.0f){
				break;
			}
//			log("%.2f",originX);
//			log("%.2f",originY);
			int type = MAP->getTypeForPoint(Vec2(originX + enemySize.width/8 + j*(enemySize.width/4) , originY- 8.0f - i*16));
			if (type ==0 || type == 3){
				pass++;
			}
//			log("%d",pass);
//			log("==========================");
		}
	}
	if (pass == 8 && this->getPositionY() >= DIS*2 /* enemySize.height/2*/){
		return true;
	}else{
		return false;
	}
}


