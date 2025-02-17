#pragma once

#include "SpaceObject.h"
#include <string>

class SpaceshipMeteor : public SpaceObject
{
public:
	SpaceshipMeteor(std::string name = "Meteor");
	~SpaceshipMeteor() = default;
	void onCollision(SpaceObject* obj);
};
