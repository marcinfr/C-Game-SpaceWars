#pragma once
#include <random>

class RandomHelper
{
public:
	static int getInteger(int from, int to)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> randomInteger(from, to);
		return (int) randomInteger(gen);
	}
};

class Rectangle
{
public:
	Rectangle(float width, float height) {
		this->width = width;
		this->height = height;
	}
	bool hasCollision(Rectangle* rect2)
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
	void setPosition(float x, float y) {
		posX = x;
		posY = y;
	}
private:
	float posX = 0;
	float posY = 0;
	float width = 0;
	float height = 0;
	float getX1()
	{
		return posX;
	}
	float getX2()
	{
		return posX + width;
	}
	float getY1()
	{
		return posY;
	}
	float getY2()
	{
		return posY + height;
	}
};

