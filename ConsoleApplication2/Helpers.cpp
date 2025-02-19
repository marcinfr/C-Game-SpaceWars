#include "Helpers.h"
#include <chrono>
#include <iostream>

int RandomHelper::getInteger(int from, int to)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> randomInteger(from, to);
	return (int)randomInteger(gen);
}

Rectangle::Rectangle(float width, float height) {
	this->width = width;
	this->height = height;
}

bool Rectangle::hasCollision(Rectangle* rect2)
{
	if (rect2->getX2() < getX1()) {
		return false;
	}
	if (rect2->getX1() > getX2()) {
		return false;
	}
	if (rect2->getY2() < getY1()) {
		return false;
	}
	if (rect2->getY1() > getY2()) {
		return false;
	}
	return true;
}

void Rectangle::setPosition(float x, float y) {
	posX = x;
	posY = y;
}

float Rectangle::getX1()
{
	return posX;
}
float Rectangle::getX2()
{
	return posX + width;
}
float Rectangle::getY1()
{
	return posY;
}
float Rectangle::getY2()
{
	return posY + height;
}

Timer::Timer()
{
	startTime = 0;
}

long Timer::getTimestamp()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	return duration.count();
}

void Timer::setTime(double seconds)
{
	startTime = getTimestamp();
	time = (int) (seconds * 1000);
}

bool Timer::hasElapsed()
{
	if (startTime > 0) {
		long timestamp = getTimestamp();
		if (startTime < timestamp - time) {
			return true;
		}
		return false;
	}
	return true;
}

sf::VertexArray Graphic::getBorder(float x1, float y1, float x2, float y2, sf::Color color)
{
	sf::VertexArray border(sf::PrimitiveType::Lines, 8);
	border[0].position = sf::Vector2f(x1, y1);
	border[0].color = color;
	border[1].position = sf::Vector2f(x2, y1);
	border[1].color = color;
	border[2].position = sf::Vector2f(x2, y1);
	border[2].color = color;
	border[3].position = sf::Vector2f(x2, y2);
	border[3].color = color;
	border[4].position = sf::Vector2f(x2, y2);
	border[4].color = color;
	border[5].position = sf::Vector2f(x1, y2);
	border[5].color = color;
	border[6].position = sf::Vector2f(x1, y2);
	border[6].color = color;
	border[7].position = sf::Vector2f(x1, y1);
	border[7].color = color;
	return border;
}