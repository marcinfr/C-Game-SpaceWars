#include "Background.h"

Star::Star(float maxX, float maxY)
{
	this->maxX = maxX;
	this->maxY = maxY;
	this->randomStar();
}
void Star::randomStar(bool withX)
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
	}
	else if (type < 60) {
		speed = 2;
		color = sf::Color(150, 150, 150);
	}
	else {
		speed = 3;
		color = sf::Color(230, 230, 230);
	}
}
float Star::getX() const
{
	return x;
}
float Star::getY() const
{
	return y;
}
sf::Color Star::getColor() const
{
	return color;
}
void Star::move()
{
	x -= speed;
	if (x <= 0) {
		this->randomStar(false);
	}
}
Background::Background(int windowX, int windowY, int starsQty)
{
	for (int i = 0; i < starsQty; i++) {
		stars.push_back(Star(windowX, windowY));
	}
}
void Background::move()
{
	for (auto& star : stars) {
		star.move();
	}
}
void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& star : stars) {
		sf::CircleShape shape(1);
		shape.setPosition({ star.getX(), star.getY() });
		shape.setFillColor(star.getColor());
		target.draw(shape);
	}
}