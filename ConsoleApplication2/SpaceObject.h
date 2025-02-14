#pragma once

#include <SFML/Graphics.hpp>
#include<array>
#include <iostream>
#include <string>
#include "Helpers.h"

class SpaceObject : public sf::Drawable
{
public:
	SpaceObject(int posX, int posY, std::string name = "");
	~SpaceObject() = default;
	int moveVector[2] = {2,0};
	Rectangle* shape = NULL;
	std::string name;
	int moveDirectionX = -1;

	bool isAlive();
	virtual void move();
	void setSpeed(float speed);
	void setMaxSpeed();
	bool hasCollision(SpaceObject* ship);
	void onCollision(SpaceObject* ship);
	virtual bool canShoot();
	virtual SpaceObject* getBulllet();
	void init();
	bool isEnemy = true;
	int life = 1;
protected:
	int width = 60;
	int height = 60;
	int maxSpeed = 10;
	float speedAcceleration = 1;
	int collisionDamage = 10;
	float posX = 0;
	float posY = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	float speed = 0;
	float currentSpeed = 0;
	float currentSpeedX = 0;
	float currentSpeedY = 0;
};

