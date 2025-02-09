#pragma once

#include <SFML/Graphics.hpp>
#include <random>


class Star
{
public:
	Star(float maxX, float maxY)
	{
		this->maxX = maxX;
		this->maxY = maxY;
		this->randomStar();
	}
	void randomStar(bool withX = true)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> randomY(0, this->maxY);
		y = randomY(gen);
		if (withX) {
			std::uniform_int_distribution<> randomX(0, this->maxX);
			x = randomX(gen);
		}
		else {
			x = this->maxX;
		}
		std::uniform_int_distribution<> randomType(0, 100);
		
		int type = randomType(gen);
		if (type < 30) {
			speed = 1;
			color = sf::Color(80, 80, 80);
		} else if (type < 60) {
			speed = 2;
			color = sf::Color(150, 150, 150);
		} else {
			speed = 3;
			color = sf::Color(230, 230, 230);
		}
	}

	float getX() const
	{
		return x;
	}

	float getY() const
	{
		return y;
	}

	sf::Color getColor() const
	{
		return color;
	}

	void move()
	{
		x -= speed;
		if (x <= 0) {
			this->randomStar(false);
		}
	}
private:
	float x;
	float y;
	float maxX;
	float maxY;
	float speed;
	sf::Color color;
};


class Background : public sf::Drawable
{
public:
	Background(int windowX, int windowY, int starsQty);
	Background() = delete;
	~Background() = default;
	void move()
	{
		for (auto& star : stars) {
			star.move();
		}
	}
private:
	std::vector<Star> stars;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		for (const auto& star : stars) {
			sf::CircleShape shape(1);
			shape.setPosition({ star.getX(), star.getY()});
			shape.setFillColor(star.getColor());
			target.draw(shape);
		}
	}
};
