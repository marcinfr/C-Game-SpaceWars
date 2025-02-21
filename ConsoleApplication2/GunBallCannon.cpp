#include "GunBallCannon.h"

GunBallCannon::GunBallCannon(std::string name) : GunDefault(name)
{
	setBulletType("ball_bullet");
}

std::vector<SpaceObject*> GunBallCannon::createBullets(int x, int y)
{
	std::vector<SpaceObject*> bullets;

	SpaceObject* bullet1 = createBullet(x, y);
	bullet1->moveVector[0] = 8;
	bullet1->moveVector[1] = -1;
	bullets.push_back(bullet1);

	SpaceObject* bullet2 = createBullet(x, y);
	bullet2->moveVector[0] = 8;
	bullet2->moveVector[1] = 1;
	bullets.push_back(bullet2);

	bullets.push_back(createBullet(x, y));
	return bullets;
}
