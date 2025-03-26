#include "BulletSmall.h"
#include "Helpers.h"

BulletSmall::BulletSmall(std::string name) : BulletDefault(name)
{
	width = 6;
	height = 4;
	maxSpeed = 25;
	collisionDamage = 2;
	color = sf::Color(200, 0, 0);
}
