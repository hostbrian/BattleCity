#ifndef _PROP_H_
#define _PROP_H_
#include "cocos2d.h"
using namespace cocos2d;
//enum class PROP_TYPE{
//	
//	STOP,
//	BOMB,
//	LIFE,
//	START
//};

class Prop:public Sprite
{
private:
	//CC_SYNTHESIZE(PROP_TYPE,_type,TYPE);
public:
	CC_SYNTHESIZE_READONLY(int, type,Type);

	//
	virtual bool init();

	static Prop* create();
	

};
#endif