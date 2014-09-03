//
//  BouningBoxLayer.h
//  BattleCity
//
//  Created by 袁文龙 on 14-9-1.
//
//

#ifndef __BattleCity__BouningBoxLayer__
#define __BattleCity__BouningBoxLayer__

#include <iostream>
#include <cocos2d.h>
using namespace cocos2d;

class BouningBoxLayer: public Layer{
private:
    virtual void update(float t);
    
    static BouningBoxLayer * instance;
    CREATE_FUNC(BouningBoxLayer);
public:
    static BouningBoxLayer* getInstanse();
    virtual bool init();
};

#endif /* defined(__BattleCity__BouningBoxLayer__) */
