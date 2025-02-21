#include "BulletBall.h"

BulletBall::BulletBall(std::string name) : BulletDefault(name)
{
	width = 5;
	maxSpeed = 13;
	collisionDamage = 7;
}

void BulletBall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape bullet(width);
	bullet.setPosition({ posX - width, posY - width });
	bullet.setFillColor(sf::Color(255, 0, 0));
	target.draw(bullet);
}