#include "SpaceshipShooterDefault.h"
#include "GunFactory.h"

SpaceshipShooterDefault::SpaceshipShooterDefault(std::string name) : SpaceObject(name)
{
	width = 40;
	height = 40;
	maxSpeed = 6;
	speedAcceleration = 0.2;
	gun = GunFactory::createObject("double_gun");
}

std::vector<SpaceObject*> SpaceshipShooterDefault::getShootBullets() {
	gun->orientationX = orientationX;
	gun->isEnemy = isEnemy;
	return gun->getShootBullets(posX, posY);
}
