#pragma once

#include "SpaceObject.h"
#include <string>

class MeteorEnemy : public SpaceObject
{
public:
	MeteorEnemy(int posX, int posY, std::string name = "Meteor");
	~MeteorEnemy() = default;
};
