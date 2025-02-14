#include "MeteorEnemy.h"

MeteorEnemy::MeteorEnemy(int posX, int posY, std::string name) : SpaceObject(posX, posY, name)
{
	width = 20;
	height = 20;
	maxSpeed = 5;
}
