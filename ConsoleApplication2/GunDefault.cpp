#include "GunDefault.h"
#include "BulletFactory.h"

GunDefault::GunDefault(std::string name)
{
	shootTimer = new Timer();
}

std::vector<SpaceObject*> GunDefault::getShootBullets(int x, int y) {
	std::vector<SpaceObject*> bullets;

	if (shootTimer->hasElapsed()) {
		SpaceObject* bullet = BulletFactory::createObject(bulletType);
		bullet->posX = x;
		bullet->posY = y;
		bullet->init();
		bullet->setMaxSpeed();
		bullet->isEnemy = isEnemy;
		bullet->moveVector[0] = orientationX;
		bullet->orientationX = orientationX;
		bullets.push_back(bullet);
		shootTimer->setTime(cooldown);
	}

	return bullets;
}

