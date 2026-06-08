#pragma once
#include <SFML/Graphics.hpp>

#include "Constants.h"

class Game
{
public:
	Game();

	void run();

private:
	sf::RenderWindow window;
};