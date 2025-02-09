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
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		std::ostringstream lifeText;
		lifeText << spaceship->life;

		sf::Font font("arial.ttf");
		sf::Text life(font);

		life.setString(lifeText.str());
		life.setCharacterSize(24);
		life.setFillColor(sf::Color::Red);
		life.setPosition({ 0, 0 });

		target.draw(life);
	}
};

