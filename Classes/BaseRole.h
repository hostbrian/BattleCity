#ifndef _BaseRole_H_
#define _BaseRole_H_

#include "cocos2d.h"
using namespace cocos2d;

/**坦克每次移动距离, 默认是 16( 1/4个车身 )*/
#define DIS 16.0f

/**角色状态*/
//enum ROLE_STATE{
//    /**正常*/
//    NORMAL=0,
//    
//    /**暂停*/
//    STOP,
//    
//    /**保护,无敌状态*/
//    PROTECTED
//    
//};
enum ROLE_STATE
{
	/**正常*/
	NORMAL,
	/**暂停*/
	STOP,
	/**保护，无敌状态*/
	PROTECTED
};


/**角色朝向*/
enum Face
{
	/**朝上*/
	UP=0,

	/**朝下*/
	DOWN,

	/**朝左*/
	LEFT,

	/**朝右*/
	RIGHT

};

class BaseRole:public Sprite{
public:	//======纯虚函数===========

	/**发送子弹*/
	virtual void addFire() =0;

	/**判定死亡*/
	virtual void die();

	/**状态设置，只有主角坦克有*/
	virtual void setState(ROLE_STATE state) = 0;

public:	//=======虚函数============
    /**根据一个RECT返回是否可以移动*/
    bool getTypeForRectReturnBoll(Rect _rect);
    
    virtual int getFace();
    
	/**死亡动画*/
	virtual void dieAnimation(const char * fileName,int count);

    /**受到攻击*/
    virtual bool hurt(int hp);

	/**受伤害动画*/
	virtual ActionInterval * hitAnimate() ;

	/**移除*/
	virtual void remove();

public:	//=======普通函数===========
	/**坦克移动总判断*/
	bool canMoveInMap();

	/**坦克左行 与 地图测试*/
	bool canLeftMoveInMap();

	/**坦克右行 与 地图测试*/
	bool canRightMoveInMap();

	/**坦克上行 与 地图测试*/
	bool canUpMoveInMap();

	/**坦克下行 与 地图测试*/
	bool canDownMoveInMap();

    virtual void onEnter();
protected:
	/**坦克生命值*/
	int  HP;
	
    /**坦克速度*/
	float speed;
    
	/**坦克朝向*/
	int face;
    
	/**坦克大小*/
	Size  tankSize;	// 64 x 64
    
	/**表示主角坦克身上的状态 , 正常,暂停,无敌*/
	ROLE_STATE state;
    
    /**判断角色类型  1. enemy  2. player */
    CC_SYNTHESIZE(std::string,_roleType,RoleType);
    
    /**获取是否已经死亡*/
    CC_SYNTHESIZE(bool, isDie,Die);
};
#endif	//!_BaseRole_H_