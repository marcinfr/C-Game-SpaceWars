#include "Menu.h"
#include "Helpers.h"

Menu::Menu(sf::RenderWindow* window)
{
	this->window = window;
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	float windowX = (float) window->getSize().x;
	float windowY = (float) window->getSize().y;
	float centerX = windowX / 2;
	float centerY = windowY / 2;
	float menuWidth = 400;
	float menuHeight = 600;

	sf::RectangleShape overlay({ windowX, windowY });
	overlay.setPosition({ 0, 0 });
	overlay.setFillColor(sf::Color(0, 0, 0, 200));
	target.draw(overlay);

	sf::RectangleShape bg({ menuWidth, menuHeight });
	bg.setPosition({ centerX - (menuWidth / 2), centerY - (menuHeight / 2) });
	bg.setFillColor(sf::Color(0, 0, 0));
	target.draw(bg);

	target.draw(
		Graphic::getBorder(
			centerX - (menuWidth / 2), 
			centerY - (menuHeight / 2), 
			centerX + (menuWidth / 2), 
			centerY + (menuHeight / 2)
		)
	);
}