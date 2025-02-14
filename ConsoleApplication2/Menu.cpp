#include "Menu.h"

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

	sf::VertexArray border(sf::PrimitiveType::Lines, 8);
	border[0].position = sf::Vector2f(centerX - (menuWidth / 2), centerY - (menuHeight / 2));
	border[1].position = sf::Vector2f(centerX + (menuWidth / 2), centerY - (menuHeight / 2));
	border[2].position = sf::Vector2f(centerX + (menuWidth / 2), centerY - (menuHeight / 2));
	border[3].position = sf::Vector2f(centerX + (menuWidth / 2), centerY + (menuHeight / 2));
	border[4].position = sf::Vector2f(centerX + (menuWidth / 2), centerY + (menuHeight / 2));
	border[5].position = sf::Vector2f(centerX - (menuWidth / 2), centerY + (menuHeight / 2));
	border[6].position = sf::Vector2f(centerX - (menuWidth / 2), centerY + (menuHeight / 2));
	border[7].position = sf::Vector2f(centerX - (menuWidth / 2), centerY - (menuHeight / 2));

	target.draw(border);
}