#pragma once

#include <SFML/Graphics.hpp>

class Menu : public sf::Drawable
{
public:
	Menu(sf::RenderWindow* window);
	bool display = false;
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RenderWindow* window;
};

