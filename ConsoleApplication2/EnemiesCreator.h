#pragma once

#include <SFML/Graphics.hpp>
#include "SpaceObjectsManager.h"

class EnemiesCreator
{
public:
	EnemiesCreator(sf::RenderWindow* window, SpaceObjectsManager* spaceObjectManager);
	void create();
	int stage = 0;
private:
	sf::RenderWindow* window;
	SpaceObjectsManager* spaceObjectManager;
	SpaceObject* getNewRandomEnemy();
	bool canCreate();
};

