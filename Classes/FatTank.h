#ifndef __FAT_TANK_H__
#define __FAT_TANK_H__

#include "cocos2d.h"
USING_NS_CC;
#include "BaseEnemy.h"

#define FAT_SPEED 32.0f
#define FAT_HP 4


class FatTank : public BaseEnemyRole
{
public:
	CREATE_FUNC(FatTank);

	virtual bool init();
};

#endif // __FAT_TANK_H__