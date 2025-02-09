#pragma once

#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include<array>
#include <iostream>

class Enemy : public sf::Drawable
{
public:
	Enemy();
	Enemy(int posX, int posY);
	~Enemy() = default;
	int width = 60;
	int height = 60;
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
	}
	bool hasCollision(Spaceship* ship)
	{
		if (ship->getCenterX() > posX && ship->getCenterX() < posX + width 
			&& ship->getCenterY() > posY && ship->getCenterY() < posY + height
		) {
			return true;
		}
		return false;
	}
	void onCollision(Spaceship* ship)
	{
		live = 0;
		ship->makeDamage(10);
	}
protected:
	float posX;
	float posY;
	int live = 1;
	int speed = 1;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		sf::RectangleShape shape({ (float) width, (float) height });
		shape.setPosition({ posX, posY });
		target.draw(shape);
	}
};

