#pragma once

#include "SpaceObject.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

class BulletFactory
{
public:
	static SpaceObject* createObject(const std::string& bulletType);
};

