#pragma once

#include <SFML/Graphics.hpp>
#include "Helpers.h"
#include "Enemy.h"
#include "MeteorEnemy.h"
#include "GunShipEnemy.h"

class EnemyWrapper
{
public:
	Enemy* enemy;
	EnemyWrapper(Enemy* enemy)
	{
		this->enemy = enemy;
	}
};

class Enemies : public sf::Drawable
{
public:
	Enemies(int windowX, int windowY);
	~Enemies() = default;

	void generateEnemy()
	{
		int enemyType = RandomHelper::getInteger(0, 100);
		int randomPosY = RandomHelper::getInteger(0, this->windowY);

		Enemy* enemy = new Enemy(this->windowX, randomPosY);
		if (enemyType < 30) {
			enemy = new GunShipEnemy(this->windowX, randomPosY);
		} else if (enemyType < 60) {
			enemy = new MeteorEnemy(this->windowX, randomPosY);
		}

		EnemyWrapper EnemyWrapper(enemy);
		enemies.push_back(EnemyWrapper);
	}
	void setPlayerSpaceship(Spaceship* spaceship)
	{
		playerSpacehip = spaceship;
	}
	void move()
	{
		std::vector<EnemyWrapper> currentenemies;

		int currrentEnemiesSpacehipQty = 0;

		for (auto& enemyWrapper : enemies) {
			currentenemies.push_back(enemyWrapper);
			if (enemyWrapper.enemy->isSpaceship()) {
				currrentEnemiesSpacehipQty++;
			}
		}

		if (currrentEnemiesSpacehipQty < maxEnemyQty) {
			generateEnemy();
		}

		for (auto& enemyWrapper : currentenemies) {
			enemyWrapper.enemy->move();

			if (enemyWrapper.enemy->hasCollision(playerSpacehip)) {
				enemyWrapper.enemy->onCollision(playerSpacehip);
			}

			if (enemyWrapper.enemy->canShoot()) {
				Enemy* bullet = enemyWrapper.enemy->getBulllet();
				EnemyWrapper bullerWrapper(bullet);
				enemies.push_back(bullerWrapper);
			}
		}
		
		enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](EnemyWrapper& enemyWrapper) {
			return !enemyWrapper.enemy->isAlive();
			}), enemies.end());

		for (auto& enemyWrapper : enemies) {
			if (!enemyWrapper.enemy->isAlive()) {
				delete& enemyWrapper;
			}
		}
	}
private:
	std::vector<EnemyWrapper> enemies;
	int windowX;
	int windowY;
	int maxEnemyQty = 5;
	Spaceship* playerSpacehip;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		for (const auto& enemyWrapper : enemies) {
			target.draw(*enemyWrapper.enemy);
		}
	}
};

