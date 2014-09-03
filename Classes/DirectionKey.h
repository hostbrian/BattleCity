#ifndef __DIRECTIONKEY_H_
#define __DIRECTIONKEY_H_
#include "cocos2d.h"
#include <string>
#include "PlayerRole.h"

using namespace std;
USING_NS_CC;

class DirectionKey:public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(DirectionKey);
    
    PlayerRole * role;
    
	CC_SYNTHESIZE(function <void ()>,up,Up);
	CC_SYNTHESIZE(function <void ()>,down,Down);
	CC_SYNTHESIZE(function <void ()>,left,Left);
	CC_SYNTHESIZE(function <void ()>,right,Right);
    
    CC_SYNTHESIZE(function <void ()>,fire,Fire);
protected:
    void checkKeyToMove(Vec2 b);
	void createDir();
};



#endif