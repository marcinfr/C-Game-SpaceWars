#pragma once

#include "Enemy.h"
#include <iostream>

using namespace std;

class GunShipEnemy : public Enemy
{
public:
	GunShipEnemy(int posX, int posY);
	~GunShipEnemy() = default;
	void move() override
	{
		Enemy::move();
	}
};
