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
	virtual void move(sf::RenderWindow* window);
	void addGun(std::string gunCode);
	void setActiveGun(std::string gunCode);
	std::unordered_map<std::string, GunDefault*> guns;	
};

