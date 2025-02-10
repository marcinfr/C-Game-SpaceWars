#pragma once
#include <random>

class RandomHelper
{
public:
	static int getInteger(int from, int to);
};

class Rectangle
{
public:
	Rectangle(float width, float height);
	bool hasCollision(Rectangle* rect2);
	void setPosition(float x, float y);
private:
	float posX = 0;
	float posY = 0;
	float width = 0;
	float height = 0;
	float getX1();
	float getX2();
	float getY1();
	float getY2();
};

