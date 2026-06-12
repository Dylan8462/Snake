#include "Game.h"

#include <iostream>

using namespace Constants;
using namespace sf::Keyboard;
using std::cout;

Game::Game() : snake(30.f),
	window(sf::VideoMode({ c_windowWidth, c_windowHeight}),
		"Snake Demo", sf::Style::None)
{
	sf::Image icon;
	if (icon.loadFromFile("assets/icon.png"))
		window.setIcon(icon);
	else
		std::cerr << "Error loading from file icon.png!\n";

	window.setFramerateLimit(60);
}

void Game::run()
{
	while (window.isOpen())
	{
		events();
		update();
		render();
	}
}

void Game::events()
{
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>() || isKeyPressed(Scancode::Escape))
			window.close();
	}
}

void Game::update()
{
	snake.update(sf::Mouse::getPosition(window));
}

void Game::render()
{
	window.clear();
	window.draw(snake);
	window.display();
}