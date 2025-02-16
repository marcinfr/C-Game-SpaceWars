#include "SpaceObject.h"

SpaceObject::SpaceObject(std::string name) {
	this->posX = (float)posX;
	this->posY = (float)posY;
	this->name = name;
}
void SpaceObject::init()
{
	shape = new Rectangle(width, height);
	shape->setPosition(posX + (width / 2), posY + (height / 2));
}
bool SpaceObject::isAlive()
{
	if (life <= 0) {
		return false;
	}
	return true;
}
void SpaceObject::move(sf::RenderWindow* window)
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
	if (vectorLength != 0) {
		double scaleFactor = currentSpeed / vectorLength;
		speedX = moveVector[0] * scaleFactor;
		speedY = moveVector[1] * scaleFactor;
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

	posX += currentSpeedX;
	posY += currentSpeedY;

	if (posX + width < 0
		|| posX - width > window->getSize().x) 
	{
		life = 0;
	}

	shape->setPosition(posX - (width / 2), posY - (height / 2));
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
	currentSpeed = speed;
}
void SpaceObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape shape({ (float)width, (float)height });
	shape.setPosition({ posX - (width / 2), posY - (height / 2)});
	shape.setFillColor(sf::Color(0, 155, 0));
	target.draw(shape);

	sf::VertexArray border(sf::PrimitiveType::Lines, 8);
	border[0].position = sf::Vector2f(this->shape->getX1(), this->shape->getY1());
	border[1].position = sf::Vector2f(this->shape->getX2(), this->shape->getY1());
	border[2].position = sf::Vector2f(this->shape->getX2(), this->shape->getY1());
	border[3].position = sf::Vector2f(this->shape->getX2(), this->shape->getY2());
	border[4].position = sf::Vector2f(this->shape->getX1(), this->shape->getY2());
	border[5].position = sf::Vector2f(this->shape->getX2(), this->shape->getY2());
	border[6].position = sf::Vector2f(this->shape->getX1(), this->shape->getY1());
	border[7].position = sf::Vector2f(this->shape->getX1(), this->shape->getY2());

	target.draw(border);

	sf::CircleShape center(4);
	center.setPosition({ posX - 2, posY -2 });
	center.setFillColor(sf::Color(255, 0, 0));
	target.draw(center);


}
std::vector<SpaceObject*> SpaceObject::getShootBullets() {
	std::vector<SpaceObject*> bullets;
	return bullets;
}
void SpaceObject::shoot()
{
	this->isShooting = true;
}