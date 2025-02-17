#include "GunDouble.h"

GunDouble::GunDouble(std::string name) : GunDefault(name)
{
}

std::vector<SpaceObject*> GunDouble::createBullets(int x, int y)
{
	std::vector<SpaceObject*> bullets;
	bullets.push_back(createBullet(x, y - 25));
	bullets.push_back(createBullet(x, y + 25));
	return bullets;
}
