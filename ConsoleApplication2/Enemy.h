#pragma once

#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include<array>
#include <iostream>
#include "Helpers.h"

class Enemy : public sf::Drawable
{
public:

	Enemy(int posX, int posY) {
		this->posX = (float)posX;
		this->posY = (float)posY;
		this->shape = new Rectangle(width, height);
	}
	~Enemy() = default;
	int width = 60;
	int height = 60;
	Rectangle* shape = NULL;

	bool isAlive()
	{
		if (live <= 0) {
			return false;
		}
		return true;
	}
	virtual void move()
	{
		posX -= speed;
		if (posX + width - speed < 0) {
			live = 0;
		}
		shape->setPosition(posX, posY);
	}
	bool hasCollision(Spaceship* ship)
	{
		return this->shape->hasCollision(ship->shape);
	}
	void onCollision(Spaceship* ship)
	{
		live = 0;
		ship->makeDamage(collisionDamage);
	}
	virtual bool canShoot()
	{
		return false;
	}
	virtual Enemy* getBulllet()
	{
		return NULL;
	}
	virtual bool isSpaceship()
	{
		return true;
	}
protected:
	float posX = 0;
	float posY = 0;
	int live = 1;
	int speed = 1;
	int collisionDamage = 10;
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		sf::RectangleShape shape({ (float) width, (float) height });
		shape.setPosition({ posX, posY });
		target.draw(shape);
	}
};

