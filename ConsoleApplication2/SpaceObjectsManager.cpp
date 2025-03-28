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
	std::vector<SpaceObject*> enemiesObjects;

	for (auto& obj : spaceObjects) {
		if (obj->isEnemy) {
			enemiesObjects.push_back(obj);
		}
	}

	for (auto& obj : spaceObjects) {
		obj->move(window);

		if (!obj->isEnemy) {
			for (auto& enemy : enemiesObjects) {
				if (enemy->hasCollision(obj)) {
					enemy->onCollision(obj);
				}
			}
		}

		if (obj->isAutoShooting && obj->posX < window->getSize().x) {
			obj->shoot();
		}

		if (obj->isShooting) {
			shootingObjects.push_back(obj);
		}
	}

	for (auto& obj : shootingObjects) {
		std::vector<SpaceObject*> bullets = obj->getShootBullets();
		for (auto& bullet : bullets) {
			spaceObjects.push_back(bullet);
		}
	}

	spaceObjects.erase(std::remove_if(spaceObjects.begin(), spaceObjects.end(), [](SpaceObject* obj) {
		return !obj->isAlive();
		}), spaceObjects.end());

	for (auto& obj : spaceObjects) {
		if (!obj->isAlive()) {
			delete& obj;
		}
	}
}

void SpaceObjectsManager::draw()
{
	for (const auto& obj : spaceObjects) {
		window->draw(*obj);
	}
}
