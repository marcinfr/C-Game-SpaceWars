#include "Player.h"
#include "SpaceshipShooterDefault.h"
#include "PlayerController.h"

Player::Player(sf::RenderWindow* window)
{
	spaceship = new SpaceshipShooterDefault("Player");
	spaceship->posY = window->getSize().y / 2;
	spaceship->moveVector[0] = 0;
	spaceship->moveVector[1] = 0;
	spaceship->orientationX = 1;
	spaceship->life = 100;
	spaceship->isEnemy = false;
	spaceship->addGun("default_gun");
	spaceship->addGun("double_gun");
	spaceship->activeGun = "default_gun";
	spaceship->init();
}

void Player::controlSpaceship()
{
	if (xMoveDirection == 0 && isRightButtonPressed) {
		xMoveDirection = 1;
	}

	if (xMoveDirection == 0 && isLeftButtonPressed) {
		xMoveDirection = -1;
	}

	if (yMoveDirection == 0 && isUpButtonPressed) {
		yMoveDirection = -1;
	}

	if (yMoveDirection == 0 && isDownButtonPressed) {
		yMoveDirection = 1;
	}

	if (isRightButtonPressed || isLeftButtonPressed || isUpButtonPressed || isDownButtonPressed) {
		spaceship->setMaxSpeed();
	}
	else {
		spaceship->setSpeed(0);
	}

	spaceship->moveVector[0] = xMoveDirection;
	spaceship->moveVector[1] = yMoveDirection;
}

void Player::onKeyPressed(sf::Keyboard::Scancode key)
{
	switch (key) {
		case sf::Keyboard::Scancode::Right:
			isRightButtonPressed = true;
			xMoveDirection = 1;
			break;
		case sf::Keyboard::Scancode::Left:
			isLeftButtonPressed = true;
			xMoveDirection = -1;
			break;
		case sf::Keyboard::Scancode::Up:
			isUpButtonPressed = true;
			yMoveDirection = -1;
			break;
		case sf::Keyboard::Scancode::Down:
			isDownButtonPressed = true;
			yMoveDirection = 1;
			break;
		case sf::Keyboard::Scancode::Space:
			spaceship->shoot();
			break;
		case sf::Keyboard::Scancode::Num1:
			spaceship->setActiveGun("default_gun");
			break;
		case sf::Keyboard::Scancode::Num2:
			spaceship->setActiveGun("double_gun");
			break;
	}
	controlSpaceship();
}

void Player::onKeyReleased(sf::Keyboard::Scancode key)
{
	switch (key) {
	case sf::Keyboard::Scancode::Right:
		isRightButtonPressed = false;
		xMoveDirection = 0;
		break;
	case sf::Keyboard::Scancode::Left:
		isLeftButtonPressed = false;
		xMoveDirection = 0;
		break;
	case sf::Keyboard::Scancode::Up:
		isUpButtonPressed = false;
		yMoveDirection = 0;
		break;
	case sf::Keyboard::Scancode::Down:
		isDownButtonPressed = false;
		yMoveDirection = 0;
		break;
	}
	controlSpaceship();
}
