#include "InfoBox.h"
#include "Player.h"
#include "Helpers.h"

InfoBox::InfoBox(Player* player, sf::RenderWindow* window)
{
	this->player = player;
	this->window = window;
};

void InfoBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	/* life */
	sf::Texture texture;
	texture.loadFromFile("assets/heart.png");
	sf::Sprite heart(texture);
	heart.setPosition({ 10, 10 });
	target.draw(heart);
	std::ostringstream lifeText;
	lifeText << player->spaceship->life;
	sf::Font font("assets/arial.ttf");
	sf::Text life(font);
	life.setString(lifeText.str());
	life.setCharacterSize(25);
	life.setFillColor(sf::Color::Red);
	life.setPosition({ 45, 6 });
	target.draw(life);

	/* guns */
	int gunsCounter = 0;
	int gunIconSize = 60;
	int gunsIconsPadding = 10;
	int xOffset = 10;
	int yOffset = window->getSize().y - 10 - gunIconSize;
	sf::Color color;
	for (const auto& key : player->spaceship->gunsOrder) {
		auto gun = player->spaceship->guns[key];
		color = sf::Color(100, 100, 100);
		if (key == player->spaceship->activeGun) {
			color = sf::Color::White;
		}
		target.draw(
			Graphic::getBorder(
				xOffset, 
				yOffset, 
				xOffset + gunIconSize, 
				yOffset + gunIconSize, 
				color
			)
		);
		xOffset += gunIconSize + gunsIconsPadding;
	}
}