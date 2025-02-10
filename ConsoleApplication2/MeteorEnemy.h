#pragma once

#include "SpaceObject.h"

class MeteorEnemy : public SpaceObject
{
public:
	MeteorEnemy(int posX, int posY);
	~MeteorEnemy() = default;
};
