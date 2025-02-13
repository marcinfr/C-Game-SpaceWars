#pragma once

#include <SFML/Graphics.hpp>
#include "Helpers.h"
#include "SpaceObject.h"
#include "MeteorEnemy.h"
#include "GunShipEnemy.h"

class Enemies : public sf::Drawable
{
public:
	Enemies(int windowX, int windowY);
	~Enemies() = default;

	void generateEnemy()
	{
		int enemyType = RandomHelper::getInteger(0, 100);
		int randomPosY = RandomHelper::getInteger(0, this->windowY);

		SpaceObject* enemy = new SpaceObject(this->windowX, randomPosY);
		if (enemyType < 30) {
			enemy = new GunShipEnemy(this->windowX, randomPosY);
		} else if (enemyType < 60) {
			enemy = new MeteorEnemy(this->windowX, randomPosY);
		}
		enemy->init();
		enemies.push_back(enemy);
	}
	void setPlayerSpaceship(Spaceship* spaceship)
	{
		playerSpacehip = spaceship;
	}
	void move()
	{
		if (timer->hasElapsed()) {
			timer->setTime(10);
			maxEnemyQty++;
		}

		std::vector<SpaceObject*> currentenemies;

		int currrentEnemiesSpacehipQty = 0;

		for (auto& enemy : enemies) {
			currentenemies.push_back(enemy);
			if (enemy->isSpaceship()) {
				currrentEnemiesSpacehipQty++;
			}
		}

		if (currrentEnemiesSpacehipQty < maxEnemyQty) {
			generateEnemy();
		}

		for (auto& enemy : currentenemies) {
			enemy->move();

			if (enemy->hasCollision(playerSpacehip)) {
				enemy->onCollision(playerSpacehip);
			}

			if (enemy->canShoot()) {
				SpaceObject* bullet = enemy->getBulllet();
				enemies.push_back(bullet);
			}
		}
		
		enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](SpaceObject* enemy) {
			return !enemy->isAlive();
			}), enemies.end());

		for (auto& enemy : enemies) {
			if (!enemy->isAlive()) {
				delete& enemy;
			}
		}
	}
private:
	std::vector<SpaceObject*> enemies;
	int windowX;
	int windowY;
	Timer* timer;
	int maxEnemyQty = 0;
	Spaceship* playerSpacehip;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		for (const auto& enemy : enemies) {
			target.draw(*enemy);
		}
	}
};

