#ifndef __BASEENEMY_SPRITE_H__
#define __BASEENEMY_SPRITE_H__

#include "cocos2d.h"
#inlcude "BaseRole.h"
USING_NS_CC;

// 敌机每次移动距离, 默认是 32( 半个车身 )
#define DIS 16.0f

enum Face
{
	UP=0,
	DOWN,
	LEFT,
	RIGHT
};

class BaseEnemyRole : public BaseRole
{
// ============= 继承父类Sprite========================
public:
	// init 初始化
	virtual bool init(std::string fileName, int hp, int speed);

// =============== 自定义===========================

protected:
	// 敌机 生命值
	int HP;

	// 敌机速度
	float speed;

	// 敌机每次移动距离, 默认是 32( 半个车身 )
	int dis;

	// 敌机大小
	Size  enemySize;	// 64 x 64

	// 敌机移动 moveBy
	Vec2 moveV;

	// 敌机朝向
	int face;

	// 道具添加
	CC_SYNTHESIZE_READONLY(bool, propAdd, PropAdd);

	// 道具坦克 或是 非道具坦克
	CC_SYNTHESIZE_READONLY(bool, ispropTank, IsPropTank);

public:
	// 敌机攻击
	virtual void addFire(float t);

	// 与 addFire 共同使用
	virtual void onEnter();

	// 受到伤害
	virtual void getHurt(int attackPower);

	// 设置敌机朝向
	void setFace();

	// 坦克初始化后开始移动
	void beginMove();

	// 敌机移动
	void move();

	// 坦克移动总判断
	bool canMoveInMap();

	// 坦克左行 与 地图测试
	bool canLeftMoveInMap();

	// 坦克左行
	void moveLeft();

	// 坦克右行 与 地图测试
	bool canRightMoveInMap();

	// 坦克右行
	void moveRight();

	// 坦克前行 与 地图测试
	bool canUpMoveInMap();

	// 坦克前行
	void moveUp();

	// 坦克下行 与 地图测试
	bool canDownMoveInMap();

	// 坦克下行
	void moveDown();

};

#endif // __BASEENEMY_SPRITE_H__