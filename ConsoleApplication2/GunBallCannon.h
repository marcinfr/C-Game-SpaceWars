#pragma once
#include "GunDefault.h"

class GunBallCannon : public GunDefault
{
public:
	GunBallCannon(std::string name = "");
protected:
	std::vector<SpaceObject*> createBullets(int x, int y);
};
