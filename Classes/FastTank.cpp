#include "FastTank.h"

// ��д init ��ʼ��
bool FastTank::init(){
	if (!BaseEnemyRole::init("enemy2.png", FAST_HP, FAST_SPEED))
	{
		return false;
	}

	return true;
}
