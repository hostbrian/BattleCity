#include "NormalTank.h"

// ��д init ��ʼ��
bool NormalTank::init(){
	if (!BaseEnemyRole::init("enemy1.png", NORMAL_HP, NORMAL_SPEED))
	{
		return false;
	}

	return true;
}