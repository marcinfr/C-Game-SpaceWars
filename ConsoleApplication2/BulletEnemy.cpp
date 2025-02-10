#include "BulletEnemy.h"

BulletEnemy::BulletEnemy(int posX, int posY) : SpaceObject(posX, posY)
{
	width = 30;
	height = 3;
	speed = 15;
	collisionDamage = 5;
}
