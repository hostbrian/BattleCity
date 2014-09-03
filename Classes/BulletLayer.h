//
//  BulletLayer.h
//  BattleCity
//
//  Created by 袁文龙 on 14-9-2.
//
//

#ifndef __BattleCity__BulletLayer__
#define __BattleCity__BulletLayer__

#include <iostream>
#include "cocos2d.h"
#include "BaseBullet.h"

class BaseEnemyRole;
class PlayerRole;
using namespace cocos2d;

class BulletLayer:public Layer{
private:
    static BulletLayer * instance;

    virtual void onEnter();
    virtual bool init();

	/**MainPlayer 敌机类**/
    CC_SYNTHESIZE(Vector<BaseBullet *>, enemyBullVector,EnemyBulletVector);
    /**MainPlayer 主角类**/
    CC_SYNTHESIZE(Vector<BaseBullet *>, playerBullVector, PlayerBulletVector);
public:
    static BulletLayer * getInstance();
    
    void createEnemyBullet(BaseRole *player);
    void createPlayerBullet(BaseRole *player);
    void removeBullet(BaseBullet* _bullet,std::string type);
};

#endif /* defined(__BattleCity__BulletLayer__) */
