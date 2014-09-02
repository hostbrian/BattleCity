//
//  GameScene.h
//  BattleCity
//
//  Created by 袁文龙 on 14-8-30.
//
//

#ifndef __BattleCity__GameScene__
#define __BattleCity__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "RoleControl.h"
using namespace cocos2d;

class GameScene : public Layer{
private:
    virtual void onEnter();
private:
    Layer * TITLEMAP;
public:
    virtual bool init();
    static Scene * createScene();
    CREATE_FUNC(GameScene);
};

#endif /* defined(__BattleCity__GameScene__) */
