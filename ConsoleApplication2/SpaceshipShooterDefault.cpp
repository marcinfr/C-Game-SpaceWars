#include "SpaceshipShooterDefault.h"
#include "GunFactory.h"

SpaceshipShooterDefault::SpaceshipShooterDefault(std::string name) : SpaceObject(name)
{
	width = 77;
	height = 66;
	maxSpeed = 6;
	speedAcceleration = 0.2;
	spritePath = "assets/spaceship01_77.png";
}

std::vector<SpaceObject*> SpaceshipShooterDefault::getShootBullets() {
	if (guns.find(activeGun) != guns.end()) {
		return guns[activeGun]->getShootBullets(posX, posY);
	}
	return SpaceObject::getShootBullets();
}

void SpaceshipShooterDefault::addGun(std::string gunCode)
{
	if (guns.find(gunCode) != guns.end()) {
		return; // gun already exists
	}

	activeGun = gunCode;
	GunDefault* newGun = GunFactory::createObject(gunCode);
	newGun->orientationX = orientationX;
	newGun->isEnemy = isEnemy;
	guns[gunCode] = newGun;
}

void SpaceshipShooterDefault::setActiveGun(std::string gunCode)
{
	if (guns.find(gunCode) != guns.end()) {
		activeGun = gunCode;
	}
}