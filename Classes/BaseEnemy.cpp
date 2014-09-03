#include "BaseEnemy.h"
#include "BulletLayer.h"

bool BaseEnemyRole::init(std::string fileName, int hp, int speed){
	if (!BaseRole::initWithSpriteFrameName(fileName))
	{
		return false;
	}
    
    this->setRoleType("enemy");
    
	this->HP = hp;
	this->speed = speed;
	this->tankSize = Size(32.0, 32.0f);
	this->dis = DIS;
	this->moveV = Vec2(0.0f, 0.0f);

	return true;
}

// onEnter
void BaseEnemyRole::onEnter(){
	BaseRole::onEnter();
    
    addFire();
    
    
	//this->schedule(schedule_selector(BaseEnemyRole::addFire),0.15);
	this->beginMove();
}

void BaseEnemyRole::addFire(){
    BulletLayer::getInstance()->createEnemyBullet(this);
    
}

//void BaseEnemyRole::getHurt(int attackPower){
//	propAdd = true;
//	if (ispropTank)
//	{
//        
//	}
//}

void BaseEnemyRole::beginMove(){
	// face direction rate
    unsigned int i;
    srand(i);
	int dirRate = random() % 9 +1;
	// face down
	if (dirRate <= 4) {this->face = DOWN;	this->setRotation(180.0f); }
	// face left 
	if (dirRate > 4 && dirRate <=7 ) {this->face = LEFT;	this->setRotation(-90.0f);}
	// face right
	if (dirRate > 7) {this->face = RIGHT;	this->setRotation(90.0f);}

	// �ƶ���ʼ
	this->move();
}

void BaseEnemyRole::setFace(){
    unsigned int i;
    srand(i);
	int dirRate = random() % 9 +1;
	// face down
	if (dirRate <= 2) {this->face = DOWN;	this->setRotation(180.0f); }
	// face up
	if (dirRate > 2 && dirRate <=4) {this->face = DOWN;	this->setRotation(0.0f); }
	// face left 
	if (dirRate > 4 && dirRate <=7 ) {this->face = LEFT;	this->setRotation(-90.0f);}
	// face right
	if (dirRate > 7) {this->face = RIGHT;	this->setRotation(90.0f);}
}

void BaseEnemyRole::move(){
	if (this->canMoveInMap()){
		switch (this->face)
		{
		case LEFT:	
			this->moveLeft();
			break;
		case RIGHT:
			this->moveRight();
			break;
		case UP:
			this->moveUp();
			break;
		case DOWN:
			this->moveDown();
			break;
		default:
			break;
		}
	}else{
        
        auto _delayTime = DelayTime::create(1);
        
        auto _callFun = CallFunc::create([=](){
            this->setFace();
            this->move();
        });
        
		this->runAction(
                        Sequence::create(_delayTime,_callFun, NULL)
        );
	}
}



void BaseEnemyRole::moveLeft(){
	this->stopAllActions();
	moveV.y = 0;
	moveV.x -= DIS;
	auto moveBy = MoveBy::create( DIS/speed *2, moveV);	
	auto func = CallFuncN::create([=](Node*node){
		this->move();
	});
	this->runAction(Sequence::create(moveBy,func,NULL));
}

void BaseEnemyRole::moveRight(){

	this->stopAllActions();
	moveV = Vec2(+DIS, 0);
	auto moveBy = MoveBy::create( DIS/speed, moveV);
	auto func = CallFuncN::create([=](Node*node){
		this->move();
	});
	this->runAction(Sequence::create(moveBy,func,NULL));

}

void BaseEnemyRole::moveUp(){
	this->stopAllActions();
	moveV.x = 0;
	moveV.y += DIS;
	auto moveBy = MoveBy::create( DIS/speed , moveV);
	auto func = CallFuncN::create([=](Node*node){
		this->move();
	});
	this->runAction(Sequence::create(moveBy,func,NULL));
}

void BaseEnemyRole::moveDown(){
	this->stopAllActions();
	moveV.x = 0;
	moveV.y -= DIS;
	auto moveBy = MoveBy::create( DIS/speed , moveV);
	auto func = CallFuncN::create([=](Node*node){
		this->move();
	});
	this->runAction(Sequence::create(moveBy,func,NULL));
}


//void BaseEnemyRole::die(){
//
//}

void BaseEnemyRole::setState(ROLE_STATE state){

}