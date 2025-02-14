#pragma once

#include "SpaceObject.h"

class BulletEnemy : public SpaceObject
{
public:
	BulletEnemy(int posX, int posY);
	~BulletEnemy() = default;
};
