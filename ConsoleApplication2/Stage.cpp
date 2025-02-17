#include "Stage.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

Stage::Stage(sf::RenderWindow* window)
{
	this->window = window;
}

void Stage::process()
{
	if (stageTimer.hasElapsed()) {
		stage++;
		stageTimer.setTime(15);
		opacity = 255;
		size = 52;
		stageDisplayTimer.setTime(0.5);
	}

	std::ostringstream stageText;
	stageText << "Stage " << stage;
	sf::Font font("assets/arial.ttf");
	sf::Text stageSfText(font);
	stageSfText.setString(stageText.str());
	stageSfText.setCharacterSize(size);
	stageSfText.setFillColor(sf::Color(255, 255,255, opacity));

	stageSfText.setOrigin({ stageSfText.getLocalBounds().size.x / 2.0f, stageSfText.getLocalBounds().size.y / 2.0f});
	stageSfText.setPosition(window->getView().getCenter());
	window->draw(stageSfText);

	if (stageDisplayTimer.hasElapsed() && opacity > 0) {
		stageDisplayTimer.setTime(0.04);
		opacity -= 30;
		size -= 2;
		if (size < 1) {
			size = 1;
		}
		if (opacity < 0) {
			opacity = 0;
		}
	}
}