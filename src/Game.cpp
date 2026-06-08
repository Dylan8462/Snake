#include "Game.h"

#include <iostream>

using namespace Constants;

Game::Game() : window(sf::VideoMode({ c_windowWidth, c_windowHeight}), "SFML works!", sf::Style::None)
{
}

void Game::run()
{
	std::cout << "Hello, World!" << std::endl;
	float size = std::min(c_windowHeight, c_windowWidth) / 2.f;
	std::cout << size << std::endl;
	sf::CircleShape shape(size);
	shape.setOrigin({ size, size });
	shape.setPosition({ c_windowWidth / 2.f, c_windowHeight / 2.f });
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}