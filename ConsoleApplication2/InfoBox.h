#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include "Spaceship.h"

class InfoBox : public sf::Drawable
{
public:
	InfoBox(Spaceship* spaceship);
	InfoBox() = delete;
	~InfoBox() = default;
private:
	Spaceship* spaceship;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

