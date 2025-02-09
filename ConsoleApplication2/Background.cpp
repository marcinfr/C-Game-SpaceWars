#include "Background.h"

Background::Background(int windowX, int windowY, int starsQty)
{
	for (int i = 0; i < starsQty; i++) {
		stars.push_back(Star(windowX, windowY));
	}
}
