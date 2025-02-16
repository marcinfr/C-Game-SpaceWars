#include "EnemiesCreator.h"
#include "Helpers.h"
#include "SpaceshipMeteor.h"
#include "SpaceshipShooterDefault.h"

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
	if (enemyType < 50) {
		enemy = new SpaceshipShooterDefault();
	}
	else {
		enemy = new SpaceshipMeteor();
	}
	enemy->posX = posX;
	enemy->posY = posY;
	enemy->init();
	enemy->setMaxSpeed();
	enemy->isAutoShooting = true;
	return enemy;
}
