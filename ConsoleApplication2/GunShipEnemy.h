#pragma once

#include "SpaceObject.h"
#include "BulletEnemy.h"
#include <iostream>
#include "Helpers.h"
#include <string>

using namespace std;

class GunShipEnemy : public SpaceObject
{
public:
	GunShipEnemy(int posX, int posY, std::string name = "Gunship");
	~GunShipEnemy() = default;
	bool canShoot() override;
	SpaceObject* getBulllet();
	bool isShooting = false;
private:
	Timer* shootTimer;
};

