#include "BulletBall.h"
#include "Helpers.h"

BulletBall::BulletBall(std::string name) : BulletDefault(name)
{
	width = 3;
	height = 3;
	maxSpeed = 20;
	collisionDamage = 7;
}

void BulletBall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape bullet(width);
	bullet.setPosition({ posX - width, posY - width });
	bullet.setFillColor(sf::Color(255, 0, 0));
	target.draw(bullet);
}