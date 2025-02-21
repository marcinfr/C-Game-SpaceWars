#pragma once
#include "GunDefault.h"

class GunDouble : public GunDefault
{
public:
	GunDouble(std::string name = "");
	std::vector<SpaceObject*> createBullets(int x, int y);
	std::string bulletType = "ball_bullet";
};
