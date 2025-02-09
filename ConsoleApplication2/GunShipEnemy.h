#pragma once

#include "Enemy.h"
#include "BulletEnemy.h"
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
	bool canShoot() override
	{
		if (((int) posX) % 100 == 0) {
			if (!isShooting) {
				isShooting = true;
				return true;
			}
		} else {
			isShooting = false;
		}
		return false;
	}
	Enemy* getBulllet() override
	{
		Enemy* bullet = new BulletEnemy((int)posX, (int)(posY + (height / 2)));
		return bullet;
	}
private: 
	bool isShooting = false;
};


