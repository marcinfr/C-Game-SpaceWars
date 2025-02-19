#pragma once

#include "SpaceshipShooterDefault.h"

class Player
{
public:
	Player(sf::RenderWindow* window);
	SpaceshipShooterDefault* spaceship;
	void onKeyPressed(sf::Keyboard::Scancode key);
	void onKeyReleased(sf::Keyboard::Scancode key);
private:
	bool isRightButtonPressed = false;
	bool isLeftButtonPressed = false;
	bool isUpButtonPressed = false;
	bool isDownButtonPressed = false;
	short xMoveDirection = 0;
	short yMoveDirection = 0;
	void controlSpaceship();
};

