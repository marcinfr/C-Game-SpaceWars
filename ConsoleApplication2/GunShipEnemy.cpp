#include "GunShipEnemy.h"

GunShipEnemy::GunShipEnemy(int posX, int posY) : SpaceObject(posX, posY)
{
	width = 30;
	height = 30;
	speed = 2;
}

bool GunShipEnemy::canShoot()
{
	if (((int)posX) % 100 == 0) {
		if (!isShooting) {
			isShooting = true;
			return true;
		}
	}
	else {
		isShooting = false;
	}
	return false;
}
SpaceObject* GunShipEnemy::getBulllet()
{
	SpaceObject* bullet = new BulletEnemy((int)posX, (int)(posY + (height / 2)));
	return bullet;
}