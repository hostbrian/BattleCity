//
//  Config.inc.h
//  BattleCity
//
//  Created by 袁文龙 on 14-8-30.
//
//

#ifndef BattleCity_Config_inc_h
#define BattleCity_Config_inc_h

#include <iostream>

/**音乐类型*/
struct MUSIC_CONFIG{
    /**游戏开始*/
    std::string GAME_START = "02 start.aif";
    /**增长生命*/
    std::string ADDLIFE = "addlife.aif";
    /**基地爆炸*/
    std::string BLAST = "blast.aif";
    
    /**发射子弹声音*/
    std::string BULLET = "bullet.aif";
    /**游戏结束*/
    std::string GAMEOVER = "gameover.aif";
    /**移动*/
    std::string MOVE = "move.aif";
    /**坦克爆炸*/
    std::string BOMB = "tankbomb.aif";
};


/**子弹类型*/
struct BULLET_TYPE{
    /**子弹1,攻击力,默认1*/
    int BULLET1_ACT=1;
    /**子弹1,速度*/
    float BULLET1_SPEED=100;
    /**子弹1,穿墙能力*/
    bool BULLET1_SUPERBULLER = false;
    /**子弹1,素材文件名*/
    std::string BULLET1_FILENAME="bullet.png";
    
    
    /**子弹2,攻击力,默认1*/
    int BULLET2_ACT=1;
    /**子弹2,速度*/
    float BULLET2_SPEED=200;
    /**子弹2,穿墙能力*/
    bool BULLET2_SUPERBULLER = false;
    /**子弹2,素材文件名*/
    std::string BULLET2_FILENAME="bullet.png";
    
    
    /**子弹3,攻击力,默认1*/
    int BULLET3_ACT=1;
    /**子弹3,速度*/
    float BULLET3_SPEED=200;
    /**子弹3,穿墙能力*/
    bool BULLET3_SUPERBULLER = true;
    /**子弹3,素材文件名*/
    std::string BULLET3_FILENAME="bullet.png";
};

#endif
