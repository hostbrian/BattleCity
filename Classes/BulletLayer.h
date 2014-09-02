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
    virtual void update(float t);
protected:
	/**MainPlayer 敌机类**/
    CC_SYNTHESIZE_PASS_BY_REF(Vector<BaseBullet *>, enemyBullVector,EnemyBulletVector);
    /**MainPlayer 主角类**/
    CC_SYNTHESIZE_PASS_BY_REF(Vector<BaseBullet *>, playerBullVector, PlayerBulletVector);
public:
    static BulletLayer * getInstance();
    
    void createEnemyBullet(BaseEnemyRole *player);
    void createPlayerBullet(PlayerRole *player);
    void removeRole(BaseBullet* _bullet,std::string type);
};

#endif /* defined(__BattleCity__BulletLayer__) */
