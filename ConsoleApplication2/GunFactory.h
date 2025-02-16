#pragma once

#include "GunDefault.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

class GunFactory
{
public:
	static GunDefault* createObject(const std::string& gunType);
};

