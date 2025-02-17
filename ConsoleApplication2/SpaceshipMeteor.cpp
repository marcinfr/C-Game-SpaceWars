#include "SpaceshipMeteor.h"

SpaceshipMeteor::SpaceshipMeteor(std::string name) : SpaceObject(name)
{
	width = 184;
	height = 159;
	maxSpeed = 2;
	spritePath = "assets/meteor_184.png";
}

void SpaceshipMeteor::onCollision(SpaceObject* obj)
{
	obj->life = 0;
}
