#pragma once
#include "SpaceObject.h"
#include "BulletFactory.h"
#include <string>

class GunDefault
{
public:
	GunDefault(std::string name = "");
	std::vector<SpaceObject*> getShootBullets(int x, int y);
	void setBulletType(std::string bulletType);
	bool isEnemy = true;
	int orientationX = -1;
	std::string bulletType = "simple_bullet";
	float cooldown = 2;
protected:
	Timer* shootTimer;
	SpaceObject* createBullet(int x, int y);
	virtual std::vector<SpaceObject*> createBullets(int x, int y);
};
