#include "MeteorEnemy.h"

MeteorEnemy::MeteorEnemy(int posX, int posY, std::string name) : SpaceObject(posX, posY, name)
{
	width = 60;
	height = 60;
	maxSpeed = 4;
}
