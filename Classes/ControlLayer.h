#ifndef __CONTROLLAYER_H_
#define __CONTROLLAYER_H_

#include "cocos2d.h"
USING_NS_CC;

class PlayerRole;
class DirectionKey;

class ControlLayer:public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(ControlLayer);
	Layer * getControlLayer();
protected:
	void tankMove();
	PlayerRole * tank;
//	DirectionKey *dirKey;
	Size vsize;
	
};

#endif