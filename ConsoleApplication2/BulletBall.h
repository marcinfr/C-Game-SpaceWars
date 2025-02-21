#pragma once
#include "BulletDefault.h"

class BulletBall : public BulletDefault
{
public:
	BulletBall(std::string name = "");
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
