#ifndef __BASEBULLET_H_
#define __BASEBULLET_H_
#include "cocos2d.h"
#include <string>
#include "PlayerRole.h"
#include "BaseRole.h"

using namespace std;
USING_NS_CC;

class BaseBullet:public Sprite
{
    
public:
	//传入子弹速度，状态，图片，位置,坦克方向
	virtual bool init(int speed,int bulletState,const string fileName,Vec2 position,int bulletDir);
    
    
    static BaseBullet * create(Sprite * player,std::string type);
	static BaseBullet * create(int speed,int bulletState,const string fileName,Vec2 position,int bulletDir);
    
    CC_SYNTHESIZE(BaseRole *, player, Player);
    
protected:
	int speed;
	int bulletState;


private:
    virtual void onEnter();
};


#endif