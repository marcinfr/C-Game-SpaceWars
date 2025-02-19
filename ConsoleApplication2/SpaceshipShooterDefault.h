#pragma once

#include "SpaceObject.h"
#include "GunDefault.h"
#include "BulletDefault.h"
#include <iostream>
#include "Helpers.h"
#include <string>
#include <map>

using namespace std;

class SpaceshipShooterDefault : public SpaceObject
{
public:
	SpaceshipShooterDefault(std::string name = "Gunship");
	~SpaceshipShooterDefault() = default;
	std::vector<SpaceObject*> getShootBullets();
	void addGun(std::string gunCode);
	void setActiveGun(std::string gunCode);
	std::map<std::string, GunDefault*> guns;	
};

