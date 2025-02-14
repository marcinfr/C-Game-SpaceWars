#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include "Player.h"

class InfoBox : public sf::Drawable
{
public:
	InfoBox(Player* player);
	InfoBox() = delete;
	~InfoBox() = default;
private:
	Player* player;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

