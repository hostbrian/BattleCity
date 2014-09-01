#include "Prop.h"

Prop* Prop:: create()
{
   auto t = new Prop();
   if(t && t->init())
   {
	 t->autorelease();
     return t;
   }
   CC_SAFE_DELETE(t);
   return nullptr;
}

bool Prop:: init()
{ 
	srand(time(0));
	//加载图片资源文件
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("tankedazhan.plist");
	
   std::string filename;
   int num =  rand()%5+1;
   type = num;
   //出现道具 
   switch(type)
   {
   case 1:
	   //全屏敌机爆炸道具
	    filename = "bomb.png";
		break;
   case 2:
	   //时间暂停道具
	    filename = "timer.png";
		break;
   case 3:
	   //
	   filename = " star.png";
	   break;
   case 4:
	   //增加生命道具
	   filename = "life.png";
	   break;
   case 5:
	   //隐身道具
	    filename = "safe.png";
		break;
   case 6:
	   //大本营升级防护
	    filename = "shovel.png";
		break;
   default:
	   break;
   }
   if(!Sprite::initWithSpriteFrameName(filename)){
        return false;
    }
   //增加闪烁动画，5秒10次
   auto bl = Blink::create(6,6);
   this->runAction(bl);
   //x 表示道具出现的横坐标，

   //int x = rand()%900+40;   
	  //// this->getContentSize().width/2  + CCRANDOM_0_1() * (834 - this->getContentSize().width);
   //int y =  rand()%600+80;
   //this->setPosition(x,y);

   return true;
}
