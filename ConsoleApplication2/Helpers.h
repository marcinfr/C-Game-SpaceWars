#pragma once
#include <random>
#include <SFML/Graphics.hpp>

class RandomHelper
{
public:
	static int getInteger(int from, int to);
};

class Graphic
{
public:
	static sf::VertexArray getBorder(float x1, float y1, float x2, float y2, sf::Color color = sf::Color::White);
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
	Timer();
	auto getTimestamp();
	void setTime(double seconds);
	bool hasElapsed();
private:
	double time = 0;
	long long startTime = 0;
};