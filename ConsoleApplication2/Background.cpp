#include "Background.h"
#include "Helpers.h"

Star::Star(int x, int y, int type)
{
	this->x = x;
	this->y = y;
	switch (type) {
		case 1:
			speed = 1;
			color = sf::Color(230, 230, 230);
			break;
		case 2:
			speed = 0.6;
			color = sf::Color(150, 150, 150);
			break;
		default:
			speed = 0.3;
			color = sf::Color(80, 80, 80);
	}
	this->color = color;
}

void Star::move()
{
	x -= speed;
}

void Star::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape shape(1);
	shape.setPosition({ x,y });
	shape.setFillColor(color);
	target.draw(shape);
}

Background::Background(sf::RenderWindow* window)
{
	this->window = window;
	for (int i = 0; i < 150; i++) {
		int x = RandomHelper::getInteger(0, window->getSize().x);
		int y = RandomHelper::getInteger(0, window->getSize().y);

		int type = 0;

		if (i > 120) {
			type = 2;
		} else if (i > 80) {
			type = 1;
		}

		stars.push_back(Star(x, y, type));
	}
}
void Background::move()
{
	for (auto& star : stars) {
		star.move();
		if (star.x < 0) {
			star.x = window->getSize().x;
			star.y = RandomHelper::getInteger(0, window->getSize().y);
		}
	}
}

void Background::draw()
{
	for (const auto& star : stars) {
		this->window->draw(star);
	}
}