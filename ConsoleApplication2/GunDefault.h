#pragma once
#include "SpaceObject.h"

class GunDefault
{
public:
	GunDefault();
	std::vector<SpaceObject*> getShootBullets(int x, int y);
	bool isEnemy = true;
	int moveDirectionX = -1;
private:
	Timer* shootTimer;
};
