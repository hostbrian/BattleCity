#ifndef __NORMAL_TANK_H__
#define __NORMAL_TANK_H__

#include "cocos2d.h"
USING_NS_CC;
#include "BaseEnemy.h"

#define NORMAL_SPEED 64.0f
#define NORMAL_HP 1

class NormalTank : public BaseEnemyRole
{
public:
    CREATE_FUNC(NormalTank);
    virtual bool init();
};

#endif // __NORMAL_TANK_H__