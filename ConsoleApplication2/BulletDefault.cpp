#include "BulletDefault.h"

BulletDefault::BulletDefault(std::string name) : SpaceObject(name)
{
	width = 30;
	height = 3;
	maxSpeed = 25;
	collisionDamage = 5;
}