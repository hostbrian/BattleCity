#ifndef __MAINROLE_H_
#define __MAINROLE_H_
#include "cocos2d.h"
USING_NS_CC;

#include "BaseRole.h"

enum class stateEnum
{
	UP=0,
	DOWN,
	LEFT,
	RIGHT
};

class PlayerRole : public BaseRole
{
public:
    CC_SYNTHESIZE_PASS_BY_REF(int, bullType, BullType);
public:
    
    int getFace();
    
	virtual void die();
    virtual void addFire();
	virtual void addFire(float t);
    /**状态设置，只有主角坦克有*/
	virtual void setState(ROLE_STATE state);
    
	virtual bool init();
	CREATE_FUNC(PlayerRole);
	void onEnter();
    
protected:
	CC_SYNTHESIZE(stateEnum,direction,Direction);
	
};


#endif