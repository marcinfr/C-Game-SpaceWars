#include "SpaceObjectsManager.h"

SpaceObjectsManager::SpaceObjectsManager(sf::RenderWindow* window)
{
	this->window = window;
}

void SpaceObjectsManager::addObject(SpaceObject* spaceObject)
{
	spaceObjects.push_back(spaceObject);
}

void SpaceObjectsManager::move()
{
	std::vector<SpaceObject*> shootingObjects;

	for (auto& obj : spaceObjects) {
		obj->move();

		//if (obj->hasCollision(playerSpacehip)) {
		//	obj->onCollision(playerSpacehip);
		//}

		if (obj->canShoot()) {
			shootingObjects.push_back(obj);
		}
	}

	for (auto& obj : shootingObjects) {
		SpaceObject* bullet = obj->getBulllet();
		spaceObjects.push_back(bullet);
	}

	spaceObjects.erase(std::remove_if(spaceObjects.begin(), spaceObjects.end(), [](SpaceObject* obj) {
		return !obj->isAlive();
		}), spaceObjects.end());

	for (auto& obj : spaceObjects) {
		if (!obj->isAlive()) {
			delete& obj;
		}
	}

	for (const auto& obj : spaceObjects) {
		window->draw(*obj);
	}
}
