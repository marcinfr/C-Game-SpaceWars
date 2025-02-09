#pragma once

#include "Enemy.h"

class MeteorEnemy : public Enemy
{
public:
	MeteorEnemy(int posX, int posY);
	~MeteorEnemy() = default;
};
