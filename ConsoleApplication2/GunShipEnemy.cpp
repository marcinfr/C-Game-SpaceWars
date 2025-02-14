#include "GunShipEnemy.h"

GunShipEnemy::GunShipEnemy(int posX, int posY, std::string name) : SpaceObject(posX, posY, name)
{
	width = 30;
	height = 30;
	maxSpeed = 4;
	speedAcceleration = 0.1;
	shootTimer = new Timer();
}

bool GunShipEnemy::canShoot()
{
	if (shootTimer->hasElapsed()) {
		shootTimer->setTime(2);
		return true;
	}

	return false;
}
SpaceObject* GunShipEnemy::getBulllet()
{
	SpaceObject* bullet = new BulletEnemy((int)posX, (int)(posY + (height / 2)));
	bullet->init();
	bullet->setMaxSpeed();
	bullet->moveDirectionX = moveDirectionX;
	return bullet;
}