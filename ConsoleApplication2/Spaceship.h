#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Spaceship : public sf::Drawable
{

public:
	Spaceship();
	~Spaceship() = default;

	float posX = 0;
	float posY = 0;
	int width = 80;
	int height = 80;
	int life = 100;

	int getCenterX()
	{
		return (int) (posX + (width / 2));
	}
	int getCenterY()
	{
		return (int) (posY + (height / 2));
	}
	void move()
	{
		posX = posX + currentSpeedX;
		posY = posY + currentSpeedY;

		if (posX < 0) {
			posX = 0;
		}

		if (currentSpeedX < speedX) {
			currentSpeedX += speedStep;
		}

		if (currentSpeedX > speedX) {
			currentSpeedX -= speedStep;
		}

		if (currentSpeedY < speedY) {
			currentSpeedY += speedStep;
		}

		if (currentSpeedY > speedY) {
			currentSpeedY -= speedStep;
		}

		if (abs(currentSpeedX) < speedStep) {
			currentSpeedX = 0;
		}

		if (abs(currentSpeedY) < speedStep) {
			currentSpeedY = 0;
		}
	}

	void moveDown()
	{
		speedY = 10;
	}

	void moveUp()
	{
		speedY = -10;
	}

	void moveForward()
	{
		speedX = 10;
	}

	void moveBackward()
	{
		speedX = -10;
	}

	void resetSpeedX()
	{
		speedX = 0;
	}

	void resetSpeedY()
	{
		speedY = 0;
	}

	void makeDamage(int damage)
	{
		life -= damage;
	}

private:
	float speedX = 0;
	float speedY = 0;

	float currentSpeedX = 0;
	float currentSpeedY = 0;

	float speedStep = 0.4f;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		sf::RectangleShape shape({(float)width, (float)height});
		shape.setPosition({posX, posY});
		target.draw(shape);
	}
};

