#include "GunShipEnemy.h"

GunShipEnemy::GunShipEnemy(int posX, int posY, std::string name) : SpaceObject(posX, posY, name)
{
	width = 40;
	height = 40;
	maxSpeed = 6;
	speedAcceleration = 0.2;
	gun = new GunDefault();
}

std::vector<SpaceObject*> GunShipEnemy::getShootBullets() {
	gun->moveDirectionX = moveDirectionX;
	gun->isEnemy = isEnemy;
	int x = (int)posX;
	if (moveDirectionX > 0) {
		x += width;
	}
	return gun->getShootBullets(x, (int) posY + (height / 2));
}
