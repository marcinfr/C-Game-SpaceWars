#pragma once

#include "Helpers.h"
#include <SFML/Graphics.hpp>

class Stage
{
public:
	Stage(sf::RenderWindow* window);
	int stage = 0;
	void process();
protected:
	Timer stageDisplayTimer;
	Timer stageTimer;
	sf::RenderWindow* window;
	int opacity = 0;
	int size = 0;
};

