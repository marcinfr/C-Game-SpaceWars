#pragma once

#include "Enemy.h"

class BulletEnemy : public Enemy
{
public:
	BulletEnemy(int posX, int posY);
	~BulletEnemy() = default;
	bool isSpaceship() override
	{
		return false;
	}
};
