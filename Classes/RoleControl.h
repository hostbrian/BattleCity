//
//  RoleControl.h
//  BattleCity
//
//  Created by 袁文龙 on 14-9-2.
//
//

#ifndef __BattleCity__RoleControl__
#define __BattleCity__RoleControl__

#include <iostream>
#include "cocos2d.h"
#include "BaseRole.h"
#include  "BaseEnemy.h"
#include  "PlayerRole.h"

using namespace cocos2d;

class RoleControl:public Layer{
private:
    virtual void onEnter();
    virtual bool init();
protected:
    static RoleControl * instance;
	/**MainPlayer 敌机类**/
    CC_SYNTHESIZE_PASS_BY_REF(Vector<BaseRole *>, enemyVector,EnemyVector);
    /**MainPlayer 主角类**/
    CC_SYNTHESIZE_PASS_BY_REF(Vector<BaseRole *>, playerVector, PlayerVector);
public:
    static RoleControl * getInstance();
    
    void createEnemyRole(const Vec2 &_vec2);
    void createPlayerRole(const Vec2 &_vec2);
    void removeRole(BaseRole* role,std::string type);
};

#endif /* defined(__BattleCity__RoleControl__) */
