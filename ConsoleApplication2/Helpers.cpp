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

long Timer::getTimestamp()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	return duration.count();
}

void Timer::setTime(double seconds)
{
	startTime = getTimestamp();
	time = (int) seconds * 1000;
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