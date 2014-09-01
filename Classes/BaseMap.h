//
//  BaseMap.h
//  BattleCity
//
//  Created by 袁文龙 on 14-8-30.
//
//

#ifndef __BattleCity__BaseMap__
#define __BattleCity__BaseMap__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class BaseMap : public Layer{
private:
    TMXTiledMap *tileMap;
    static BaseMap * _baseMap;
    CC_SYNTHESIZE(Sprite *, _jidi, JIDI);
public:
    /**
     以16的N次方,行走和攻击
     获得坐标点的元素
     @return int 
      1:砖头 
      2:铁
      3:草
      4:水
      5:基地
      6:破烂的基地
      0:可以行走的地点
     
     1     普通子弹可以消除
     1和2  特殊子弹可以消除
     5     任何子弹攻击游戏失败
     
     0和3  可行走点
     */
    int getTypeForPoint(Vec2 _vec2);
    void removeObject(Vec2 _vec2)
    static BaseMap * getInstance();
    virtual bool init();
    static Scene * createScene();
    CREATE_FUNC(BaseMap);
};

#endif /* defined(__BattleCity__BaseMap__) */
