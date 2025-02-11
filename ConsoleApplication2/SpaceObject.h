#pragma once

#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include<array>
#include <iostream>
#include "Helpers.h"

class SpaceObject : public sf::Drawable
{
public:
	SpaceObject(int posX, int posY);
	~SpaceObject() = default;
	int width = 60;
	int height = 60;
	int moveVector[2] = {1,0};
	Rectangle* shape = NULL;

	bool isAlive();
	virtual void move();
	bool hasCollision(Spaceship* ship);
	void onCollision(Spaceship* ship);
	virtual bool canShoot();
	virtual SpaceObject* getBulllet();
	virtual bool isSpaceship();
	void init();
protected:
	float posX = 0;
	float posY = 0;
	int life = 1;
	int speed = 1;
	int collisionDamage = 10;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

