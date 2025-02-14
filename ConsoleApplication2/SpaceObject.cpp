#include "SpaceObject.h"

SpaceObject::SpaceObject(int posX, int posY, std::string name) {
	this->posX = (float)posX;
	this->posY = (float)posY;
	this->name = name;
}
void SpaceObject::init()
{
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
	if (speed > currentSpeed) {
		currentSpeed += speedAcceleration;
	}
	if (currentSpeed > maxSpeed) {
		currentSpeed = maxSpeed;
	}

	if (speed < currentSpeed) {
		currentSpeed -= speedAcceleration;
	}
	if (currentSpeed < 0) {
		currentSpeed = 0;
	}

	float speedX = 0;
	float speedY = 0;

	double vectorLength = sqrt(pow(moveVector[0], 2) + pow(moveVector[1], 2));
	if (vectorLength > 0) {
		double scaleFactor = currentSpeed / vectorLength;
		speedX =  moveVector[0] * scaleFactor;
		speedY += moveVector[1] * scaleFactor;
	}

	if (currentSpeedX > speedX) {
		currentSpeedX -= speedAcceleration;
	}

	if (currentSpeedX < speedX) {
		currentSpeedX += speedAcceleration;
	}

	if (currentSpeedY > speedY) {
		currentSpeedY -= speedAcceleration;
	}

	if (currentSpeedY < speedY) {
		currentSpeedY += speedAcceleration;
	}

	posX += currentSpeedX * moveDirectionX;
	posY += currentSpeedY;

	if (posX + width - currentSpeed < 0) {
		life = 0;
	}

	shape->setPosition(posX, posY);
}
bool SpaceObject::hasCollision(SpaceObject* obj)
{
	return shape->hasCollision(obj->shape);
}
void SpaceObject::onCollision(SpaceObject* obj)
{
	life = 0;
	obj->life -= collisionDamage;
}
bool SpaceObject::canShoot()
{
	return false;
}
SpaceObject* SpaceObject::getBulllet()
{
	return NULL;
}
void SpaceObject::setSpeed(float speed) 
{
	if (speed > maxSpeed) {
		speed = maxSpeed;
	}
	if (speed < 0) {
		speed = 0;
	}
	this->speed = speed;
}
void SpaceObject::setMaxSpeed()
{
	speed = maxSpeed;
}
void SpaceObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape shape({ (float)width, (float)height });
	shape.setPosition({ posX, posY });
	target.draw(shape);
}
