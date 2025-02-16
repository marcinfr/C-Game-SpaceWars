#pragma once
#include "SpaceObject.h"
#include <string>

class GunDefault
{
public:
	GunDefault(std::string name = "");
	std::vector<SpaceObject*> getShootBullets(int x, int y);
	bool isEnemy = true;
	int orientationX = -1;
	std::string bulletType = "simple_bullet";
	float cooldown = 2;
private:
	Timer* shootTimer;
};
