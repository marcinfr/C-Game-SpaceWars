#pragma once

#include "GunDefault.h"

class GunMachineGun : public GunDefault
{
public:
	GunMachineGun(std::string name = "");
	std::vector<SpaceObject*> getShootBullets(int x, int y);
protected:
	std::vector<SpaceObject*> createBullets(int x, int y);
	int bulletsQtyInSeries = 5;
	int usedBulletsInSeries = 0;
	Timer* seriesTimer;
};

