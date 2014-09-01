//
//  WelcomeScene.h
//  BattleCity
//
//  Created by 袁文龙 on 14-8-30.
//
//

#ifndef __BattleCity__WelcomeScene__
#define __BattleCity__WelcomeScene__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class WelcomeScene : public Layer{
private:
    Layer * _layer;
    virtual void onEnter();
    void onMenuTouch(Ref*ref);
public:
    virtual bool init();
    static Scene * createScene();
    CREATE_FUNC(WelcomeScene);
};
#endif /* defined(__BattleCity__WelcomeScene__) */
