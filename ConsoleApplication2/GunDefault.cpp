#include "GunDefault.h"
#include "BulletEnemy.h"

GunDefault::GunDefault()
{
	shootTimer = new Timer();
}

std::vector<SpaceObject*> GunDefault::getShootBullets(int x, int y) {
	std::vector<SpaceObject*> bullets;

	if (shootTimer->hasElapsed()) {
		SpaceObject* bullet = new BulletEnemy(x, y);
		bullet->init();
		bullet->setMaxSpeed();
		bullet->isEnemy = isEnemy;
		bullet->moveDirectionX = moveDirectionX;
		bullets.push_back(bullet);
		shootTimer->setTime(2);
	}

	return bullets;
}

