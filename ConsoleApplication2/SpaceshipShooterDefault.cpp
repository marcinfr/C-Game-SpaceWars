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
		GunDefault* gun = guns[activeGun];
		std::vector<SpaceObject*> bullets = gun->getShootBullets(posX, posY);
		if (!gun->isShooting) {
			stopShooting();
		}
		return bullets;
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
	gunsOrder.push_back(gunCode);
	guns[gunCode] = newGun;
}

void SpaceshipShooterDefault::setActiveGun(std::string gunCode)
{
	if (guns.find(gunCode) != guns.end()) {
		activeGun = gunCode;
	}
}

void SpaceshipShooterDefault::move(sf::RenderWindow* window)
{
	if (posY - (height / 2) <= 0) {
		moveVector[1] = abs(moveVector[1]);
	}
	else if (posY + (height / 2) >= window->getSize().y) {
		moveVector[1] = (-1) * abs(moveVector[1]);
	}

	return SpaceObject::move(window);
}