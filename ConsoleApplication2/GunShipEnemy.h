#pragma once

#include "SpaceObject.h"
#include "GunDefault.h"
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
	std::vector<SpaceObject*> getShootBullets();
private:
	GunDefault* gun;
};

