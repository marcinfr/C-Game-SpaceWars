#include "InfoBox.h"
#include "Spaceship.h"

InfoBox::InfoBox(Spaceship* spaceship)
{
	this->spaceship = spaceship;
};

void InfoBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::ostringstream lifeText;
	lifeText << spaceship->life;

	sf::Font font("assets/arial.ttf");
	sf::Text life(font);

	life.setString(lifeText.str());
	life.setCharacterSize(24);
	life.setFillColor(sf::Color::Red);
	life.setPosition({ 0, 0 });

	target.draw(life);
}