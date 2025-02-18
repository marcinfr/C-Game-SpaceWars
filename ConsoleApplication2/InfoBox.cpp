#include "InfoBox.h"
#include "Player.h"

InfoBox::InfoBox(Player* player)
{
	this->player = player;
};

void InfoBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
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
}