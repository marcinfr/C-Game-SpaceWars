#pragma once

#include "SpaceObject.h"

class BulletDefault : public SpaceObject
{
public:
	BulletDefault(std::string name = "");
	~BulletDefault() = default;
};
