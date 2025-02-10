#include "SpaceObject.h"

SpaceObject::SpaceObject(int posX, int posY) {
	this->posX = (float)posX;
	this->posY = (float)posY;
	shape = new Rectangle(width, height);
	shape->setPosition(posX, posY);
}
bool SpaceObject::isAlive()
{
	if (life <= 0) {
		return false;
	}
	return true;
}
void SpaceObject::move()
{
	double vectorLength = sqrt(pow(moveVector[0], 2) + pow(moveVector[1], 2));
	double scaleFactor = speed / vectorLength;
	posX -= moveVector[0] * scaleFactor;
	posY -= moveVector[1] * scaleFactor;

	if (posX + width - speed < 0) {
		life = 0;
	}

	shape->setPosition(posX, posY);
}
bool SpaceObject::hasCollision(Spaceship* ship)
{
	return shape->hasCollision(ship->shape);
}
void SpaceObject::onCollision(Spaceship* ship)
{
	life = 0;
	ship->makeDamage(collisionDamage);
}
bool SpaceObject::canShoot()
{
	return false;
}
SpaceObject* SpaceObject::getBulllet()
{
	return NULL;
}
bool SpaceObject::isSpaceship()
{
	return true;
}
void SpaceObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape shape({ (float)width, (float)height });
	shape.setPosition({ posX, posY });
	target.draw(shape);
}