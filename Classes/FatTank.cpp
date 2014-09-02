#include "FatTank.h"

// ÷ÿ–¥ init ≥ı ºªØ
bool FatTank::init(){
	if (!BaseEnemyRole::init("enemy3.png", FAT_HP, FAT_SPEED))
	{
		return false;
	}

	return true;
}
