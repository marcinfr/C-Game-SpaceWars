#include "GunMachineGun.h"

GunMachineGun::GunMachineGun(std::string name) : GunDefault(name)
{
	setBulletType("small_bullet");
	setCooldown(4);
	seriesTimer = new Timer();
}

std::vector<SpaceObject*> GunMachineGun::createBullets(int x, int y)
{
	std::vector<SpaceObject*> bullets;
	bullets.push_back(createBullet(x, y));
	return bullets;
}

std::vector<SpaceObject*> GunMachineGun::getShootBullets(int x, int y)
{
	bool shootNextBullet = false;

	if (seriesTimer->hasElapsed() && isShooting) {
		if (usedBulletsInSeries >= bulletsQtyInSeries) {
			isShooting = 0;
			usedBulletsInSeries = 0;
		} else {
			usedBulletsInSeries += 1;
			shootNextBullet = true;
			seriesTimer->setTime(0.1);
		}
	}

	std::vector<SpaceObject*> bullets;

	if (shootTimer->hasElapsed()) {
		isShooting = true;
	}

	if (isShooting && shootNextBullet) {
		bullets = createBullets(x, y);
		shootTimer->setTime(cooldown);
	}

	return bullets;
}