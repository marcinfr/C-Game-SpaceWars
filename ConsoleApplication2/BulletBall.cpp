#include "BulletBall.h"

BulletBall::BulletBall(std::string name) : BulletDefault(name)
{
	width = 5;
	height = 5;
	maxSpeed = 13;
	collisionDamage = 7;
}

void BulletBall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::cout << "bullet ball";
}