#include "MeteorEnemy.h"

MeteorEnemy::MeteorEnemy(int posX, int posY) : SpaceObject(posX, posY)
{
	width = 20;
	height = 20;
	speed = 5;
}
