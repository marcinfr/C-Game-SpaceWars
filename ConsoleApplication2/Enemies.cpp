#include "Enemies.h"

Enemies::Enemies(int windowX, int windowY)
{
	this->windowX = windowX;
	this->windowY = windowY;
	this->timer = new Timer();
}
