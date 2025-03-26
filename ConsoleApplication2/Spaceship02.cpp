#include "Spaceship02.h"

Spaceship02::Spaceship02(std::string name) : SpaceshipShooterDefault(name)
{
	width = 200;
	height = 121;
	maxSpeed = 3;
	speedAcceleration = 0.1;
	spritePath = "assets/spaceship02_200.png";
}