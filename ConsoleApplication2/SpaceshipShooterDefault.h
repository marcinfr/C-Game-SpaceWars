#pragma once

#include "SpaceObject.h"
#include "GunDefault.h"
#include "BulletDefault.h"
#include <iostream>
#include "Helpers.h"
#include <string>

using namespace std;

class SpaceshipShooterDefault : public SpaceObject
{
public:
	SpaceshipShooterDefault(std::string name = "Gunship");
	~SpaceshipShooterDefault() = default;
	std::vector<SpaceObject*> getShootBullets();
private:
	GunDefault* gun;
};

