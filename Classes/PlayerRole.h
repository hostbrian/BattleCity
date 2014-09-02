#ifndef __MAINROLE_H_
#define __MAINROLE_H_
#include "cocos2d.h"
#inlcude "BaseRole.h"

USING_NS_CC;

enum class stateEnum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class PlayerRole:public BaseRole
{

public:
    CC_SYNTHESIZE_PASS_BY_REF(int, bullType, BullType);
public:
	virtual bool init();
	CREATE_FUNC(PlayerRole);
	void fire(float t);
	void onEnter();
protected:
	CC_SYNTHESIZE(stateEnum,direction,Direction);
	
};


#endif