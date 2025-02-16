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
	float getX1();
	float getX2();
	float getY1();
	float getY2();

private:
	float posX = 0;
	float posY = 0;
	float width = 0;
	float height = 0;
};


class Timer
{
public:
	long getTimestamp();
	void setTime(double seconds);
	bool hasElapsed();
private:
	int time = 0;
	long startTime = 0;
};