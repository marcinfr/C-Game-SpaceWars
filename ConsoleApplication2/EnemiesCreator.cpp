#include "EnemiesCreator.h"
#include "Helpers.h"
#include "MeteorEnemy.h"
#include "GunShipEnemy.h"

EnemiesCreator::EnemiesCreator(sf::RenderWindow* window, SpaceObjectsManager* spaceObjectManager)
{
	this->window = window;
	this->spaceObjectManager = spaceObjectManager;
}

void EnemiesCreator::create()
{
	if (canCreate()) {
		this->spaceObjectManager->addObject(getNewRandomEnemy());
	}
}

bool EnemiesCreator::canCreate()
{
	if (RandomHelper::getInteger(0, 100) == 1) {
		return true;
	}
	return false;
}

SpaceObject* EnemiesCreator::getNewRandomEnemy()
{
	int posX = window->getSize().x;
	int posY = RandomHelper::getInteger(0, window->getSize().y);
	int enemyType = RandomHelper::getInteger(0, 100);
	SpaceObject* enemy = NULL;
	if (enemyType < 30) {
		enemy = new GunShipEnemy(posX, posY);
	}
	else if (enemyType < 1000) {
		enemy = new MeteorEnemy(posX, posY);
	}
	else {
		enemy = new SpaceObject(posX, posY);
	}
	enemy->init();
	enemy->setMaxSpeed();
	enemy->isAutoShooting = true;
	return enemy;
}
