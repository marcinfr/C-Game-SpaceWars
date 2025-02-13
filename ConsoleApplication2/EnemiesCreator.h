#pragma once

#include <SFML/Graphics.hpp>
#include "SpaceObjectsManager.h"

class EnemiesCreator
{
public:
	EnemiesCreator(sf::RenderWindow* window, SpaceObjectsManager* spaceObjectManager);
	void create();
private:
	sf::RenderWindow* window;
	SpaceObjectsManager* spaceObjectManager;
	SpaceObject* getNewRandomEnemy();
	bool canCreate();
};

