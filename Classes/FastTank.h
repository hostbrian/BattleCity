#ifndef __FAST_TANK_H__
#define __FAST_TANK_H__

#include "cocos2d.h"
USING_NS_CC;

#include "BaseEnemy.h"

#define FAST_SPEED 48.0f
#define FAST_HP 2

class FastTank : public BaseEnemyRole
{
public:
    virtual bool init();
    CREATE_FUNC(FastTank);
};

#endif // __FAST_TANK_H__