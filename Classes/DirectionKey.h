#ifndef __DIRECTIONKEY_H_
#define __DIRECTIONKEY_H_
#include "cocos2d.h"
#include <string>
using namespace std;
USING_NS_CC;

class DirectionKey:public Menu
{
public:
	virtual bool init();
	CREATE_FUNC(DirectionKey);
	CC_SYNTHESIZE(function <void ()>,up,Up);
	CC_SYNTHESIZE(function <void ()>,down,Down);
	CC_SYNTHESIZE(function <void ()>,left,Left);
	CC_SYNTHESIZE(function <void ()>,right,Right);
protected:
	void createDir();
};



#endif