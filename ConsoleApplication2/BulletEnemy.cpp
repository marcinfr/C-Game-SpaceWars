#include "BulletEnemy.h"

BulletEnemy::BulletEnemy(int posX, int posY) : SpaceObject(posX, posY)
{
	width = 30;
	height = 3;
	maxSpeed = 15;
	collisionDamage = 5;
}
