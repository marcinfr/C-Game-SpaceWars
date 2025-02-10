#pragma once

#include <SFML/Graphics.hpp>
#include <random>


class Star
{
public:
	Star(float maxX, float maxY);
	void randomStar(bool withX = true);
	float getX() const;
	float getY() const;
	sf::Color getColor() const;
	void move();
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
	void move();
private:
	std::vector<Star> stars;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
