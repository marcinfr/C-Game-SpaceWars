#pragma once

#include "SpaceObjectController.h"
#include <SFML/Graphics.hpp>

class PlayerController : public SpaceObjectController
{
public:
    PlayerController(sf::RenderWindow* window);
    void control(SpaceObject* SpaceObject);
private:
    sf::RenderWindow* window;
};

