#ifndef __FAST_TANK_H__
#define __FAST_TANK_H__

#include "cocos2d.h"
USING_NS_CC;
#include "BaseEnemy.h"

#define FAST_SPEED 48.0f
#define FAST_HP 96

class FastTank : public BaseEnemyRole
{
public:
	//
	CREATE_FUNC(FastTank);

	//
	virtual bool init();
};

#endif // __FAST_TANK_H__