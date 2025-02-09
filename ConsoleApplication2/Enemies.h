#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "MeteorEnemy.h"
#include "GunShipEnemy.h"
#include <random>

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
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> randomY(0, this->windowY);

		std::uniform_int_distribution<> randomEnemy(0, 100);
		int enemyType = randomEnemy(gen);

		Enemy* enemy = new Enemy(this->windowX, randomY(gen));

		if (enemyType < 30) {
			enemy = new GunShipEnemy(this->windowX, randomY(gen));
		} else if (enemyType < 60) {
			enemy = new MeteorEnemy(this->windowX, randomY(gen));
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
		if (enemies.size() < maxEnemyQty) {
			generateEnemy();
		}

		for (auto& enemyWrapper : enemies) {
			enemyWrapper.enemy->move();
			if (enemyWrapper.enemy->hasCollision(playerSpacehip)) {
				enemyWrapper.enemy->onCollision(playerSpacehip);
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

