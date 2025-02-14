#include "InfoBox.h"
#include "Player.h"

InfoBox::InfoBox(Player* player)
{
	this->player = player;
};

void InfoBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::ostringstream lifeText;
	lifeText << player->spaceship->life;

	sf::Font font("assets/arial.ttf");
	sf::Text life(font);

	life.setString(lifeText.str());
	life.setCharacterSize(24);
	life.setFillColor(sf::Color::Red);
	life.setPosition({ 0, 0 });

	target.draw(life);
}