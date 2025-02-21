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

	if (posY - (height / 2) <= 0) {
		moveVector[1] = abs(moveVector[1]);
	}
	if (posY + (height / 2) >= window->getSize().y) {
		moveVector[1] = (-1) * abs(moveVector[1]);
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
	} else if (currentSpeedX < speedX) {
		currentSpeedX += speedAcceleration;
	}

	if (currentSpeedY > speedY) {
		currentSpeedY -= speedAcceleration;
	} else if (currentSpeedY < speedY) {
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
	if (spritePath != "") {
		sf::Texture texture;
		texture.loadFromFile(spritePath);
		sf::Sprite image(texture);
		if (orientationX == 1) {
			image.setPosition({ posX - (width / 2), posY - (height / 2) });
		} else {
			image.setPosition({ posX + (width / 2), posY + (height / 2) });
			image.rotate(sf::degrees(180));
		}
		target.draw(image);
	} else {
		sf::RectangleShape shape({ (float)width, (float)height });
		shape.setPosition({ posX - (width / 2), posY - (height / 2)});
		shape.setFillColor(sf::Color(0, 155, 0));
		target.draw(shape);
	}

	/*
	target.draw(Graphic::getBorder(this->shape->getX1(), this->shape->getY1(), this->shape->getX2(), this->shape->getY2()));

	sf::CircleShape center(4);
	center.setPosition({ posX - 2, posY -2 });
	center.setFillColor(sf::Color(255, 0, 0));
	target.draw(center);
	*/
}
std::vector<SpaceObject*> SpaceObject::getShootBullets() {
	std::vector<SpaceObject*> bullets;
	return bullets;
}
void SpaceObject::shoot()
{
	this->isShooting = true;
}

void SpaceObject::addGun(std::string gunCode)
{
	return;
}

void SpaceObject::setActiveGun(std::string gunCode)
{
	return;
}