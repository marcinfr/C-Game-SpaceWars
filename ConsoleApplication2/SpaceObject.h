#pragma once

#include <SFML/Graphics.hpp>
#include<array>
#include <iostream>
#include <string>
#include "Helpers.h"

class SpaceObject : public sf::Drawable
{
public:
	SpaceObject(std::string name = "");
	~SpaceObject() = default;
	int moveVector[2] = {-2,0};
	Rectangle* shape = NULL;
	std::string name;

	float posX = 0;
	float posY = 0;
	int orientationX = -1;

	bool isAlive();
	virtual void move(sf::RenderWindow* window);
	void setSpeed(float speed);
	void setMaxSpeed();
	bool hasCollision(SpaceObject* obj);
	virtual void onCollision(SpaceObject* obj);
	void shoot();
	void init();
	bool isEnemy = true;
	bool isAutoShooting = false;
	bool isShooting = false;
	int life = 1;
	virtual std::vector<SpaceObject*> getShootBullets();
	std::string spritePath = "";
	int width = 60;
	int height = 60;
protected:
	int maxSpeed = 10;
	float speedAcceleration = 1;
	int collisionDamage = 10;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	float speed = 0;
	float currentSpeed = 0;
	float currentSpeedX = 0;
	float currentSpeedY = 0;
	float canShoot = false;
};

