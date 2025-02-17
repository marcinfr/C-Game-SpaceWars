#include "SpaceshipShooterDefault.h"
#include "GunFactory.h"

SpaceshipShooterDefault::SpaceshipShooterDefault(std::string name) : SpaceObject(name)
{
	width = 77;
	height = 66;
	maxSpeed = 6;
	speedAcceleration = 0.2;
	spritePath = "assets/spaceship01_77.png";
	gun = GunFactory::createObject("double_gun");
}

std::vector<SpaceObject*> SpaceshipShooterDefault::getShootBullets() {
	gun->orientationX = orientationX;
	gun->isEnemy = isEnemy;
	return gun->getShootBullets(posX, posY);
}
