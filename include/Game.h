#pragma once
#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Player.h"

class Game
{
public:
	Game();

	void run();

private:
	void events();
	void update();
	void render();

private:
	Player snake;
	sf::RenderWindow window;
};