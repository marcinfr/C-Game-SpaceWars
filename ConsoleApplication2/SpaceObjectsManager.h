#pragma once

#include <SFML/Graphics.hpp>
#include "SpaceObject.h"

class SpaceObjectsManager
{
public:
	SpaceObjectsManager(sf::RenderWindow* window);
	void move();
	void addObject(SpaceObject* spaceObject);
private:
	sf::RenderWindow* window;
	std::vector<SpaceObject*> spaceObjects;
};
