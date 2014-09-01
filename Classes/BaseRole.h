#ifndef _BaseRole_H_
#define _BaseRole_H_

#include "cocos2d.h"
using namespace cocos2d;

/**角色状态*/
enum class ROLE_STATE{
    /**正常*/
    NORMAL,
    
    /**暂停*/
    STOP=0,
    
    /**保护,无敌状态*/
    PROTECTED
    
};

class BaseRole:public Sprite{
protected:
	/**血量*/
	int  HP;
	
    /**速度*/
	int Speed;
    
	/*表示主角坦克身上的状态 , 正常,暂停,无敌*/
	ROLE_STATE state;
    
    /**判断角色类型  1. enemy  2. player */
    CC_SYNTHESIZE(std::string,_roleType,RoleType);
    
    /**获取是否已经死亡*/
    CC_SYNTHESIZE(bool, isDie,Die);
protected:
    
public:
	 virtual bool initWithSpriteFrameName(std::string fileName,int HP,int Speed,int count,int state);
    
    /**受到攻击*/
    virtual bool hurt(int hp);
    /**判定死亡*/
	virtual void die() = 0;
    
    
	/**状态设置，只有主角坦克有*/
	virtual void setState(ROLE_STATE state) = 0;
    
    /**发送子弹*/
    void addFire(float t);
    
	/**受伤害动画*/
    virtual ActionInterval * hitAnimate() ;
    
	/**死亡动画*/
    virtual void dieAnimation(const char * fileName,int count) = 0;

	/**移除*/
	virtual void remove();

//    virtual void onEnter();
};
#endif