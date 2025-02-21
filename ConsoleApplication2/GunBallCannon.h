#pragma once
#include "GunDefault.h"

class GunBallCannon : public GunDefault
{
public:
	GunBallCannon(std::string name = "");
	std::vector<SpaceObject*> createBullets(int x, int y);
	std::string bulletType = "ball_bullet";
};
