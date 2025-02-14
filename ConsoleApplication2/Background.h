#pragma once

#include <SFML/Graphics.hpp>
#include <random>

class Star : public sf::Drawable
{
public:
	Star(int x, int y, int type);
	float x;
	float y;
	void move();
private:
	int type;
	float speed;
	sf::Color color;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class Background
{
public:
	Background(sf::RenderWindow* window);
	Background() = delete;
	~Background() = default;
	void move();
	void draw();
private:
	sf::RenderWindow* window;
	std::vector<Star> stars;
};
