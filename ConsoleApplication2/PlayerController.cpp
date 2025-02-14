#include "PlayerController.h"
#include <iostream>

class SpaceObject {
public:
	int moveVector[2] = {0,0};
};

PlayerController::PlayerController(sf::RenderWindow* window)
{
	this->window = window;
}

void PlayerController::control(SpaceObject* SpaceObject)
{
	while (const std::optional event = window->pollEvent())
	{
		if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
			std::cout << "ok";
			//SpaceObject->moveVector[0] += 1;
		}
	}
}
