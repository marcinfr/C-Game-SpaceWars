#include "GunDefault.h"

GunDefault::GunDefault(std::string name)
{
	shootTimer = new Timer();
}

void GunDefault::setBulletType(std::string bulletType)
{
	this->bulletType = bulletType;
}

std::vector<SpaceObject*> GunDefault::getShootBullets(int x, int y)
{
	std::vector<SpaceObject*> bullets;

	if (shootTimer->hasElapsed()) {
		bullets = createBullets(x, y);
		shootTimer->setTime(cooldown);
	}

	return bullets;
}

std::vector<SpaceObject*> GunDefault::createBullets(int x, int y)
{
	std::vector<SpaceObject*> bullets;
	bullets.push_back(createBullet(x, y));
	return bullets;
}

SpaceObject* GunDefault::createBullet(int x, int y)
{
	SpaceObject* bullet = BulletFactory::createObject(bulletType);
	bullet->posX = x;
	bullet->posY = y;
	bullet->init();
	bullet->setMaxSpeed();
	bullet->isEnemy = isEnemy;
	bullet->moveVector[0] = orientationX;
	bullet->orientationX = orientationX;
	return bullet;
}
