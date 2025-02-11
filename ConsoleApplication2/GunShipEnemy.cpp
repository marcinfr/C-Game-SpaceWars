#include "GunShipEnemy.h"
#include "Helpers.h"

GunShipEnemy::GunShipEnemy(int posX, int posY) : SpaceObject(posX, posY)
{
	width = 30;
	height = 30;
	speed = 2;
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
	return bullet;
}