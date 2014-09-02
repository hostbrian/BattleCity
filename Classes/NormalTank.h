#ifndef __NORMAL_TANK_H__
#define __NORMAL_TANK_H__

#include "cocos2d.h"
USING_NS_CC;
#include "BaseEnemy.h"

#define NORMAL_SPEED 32.0f
#define NORMAL_HP 100

class NormalTank : public BaseEnemyRole
{
public:
	// create ����
	CREATE_FUNC(NormalTank);

	// ��д init ��ʼ��
	virtual bool init();
};

#endif // __NORMAL_TANK_H__