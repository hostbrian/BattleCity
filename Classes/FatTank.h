#ifndef __FAT_TANK_H__
#define __FAT_TANK_H__

#include "cocos2d.h"
USING_NS_CC;
#include "BaseEnemy.h"

#define FAT_SPEED 16.0f
#define FAT_HP 300


class FatTank : public BaseEnemyRole
{
public:
	// create 方法
	CREATE_FUNC(FatTank);

	// 重写 init 初始化
	virtual bool init();
};

#endif // __FAT_TANK_H__