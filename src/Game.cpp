#include "Game.h"

#include <iostream>

using namespace Constants;
using namespace sf::Keyboard;
using std::cout;

Game::Game() : snake(30.f),
	window(sf::VideoMode({ c_windowWidth, c_windowHeight}),
		"Snake Demo")//, sf::Style::None)
{
	sf::Image icon;
	if (icon.loadFromFile("assets/icon.png"))
		window.setIcon(icon);
	else
		std::cerr << "Error loading from file icon.png!\n";

	float size = 25.f;
	snake.addDot(size);
	snake.addDot(size);

	snake.position();

	snake.getBody()[0].setColor(sf::Color(sf::Color::Red));
	snake.getBody()[1].setColor(sf::Color(sf::Color::Green));
	snake.getBody()[2].setColor(sf::Color(sf::Color::Blue));

	cout << snake;
}

void Game::run()
{
	while (window.isOpen() && window.hasFocus())
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

		if (auto* mouse = event->getIf<sf::Event::MouseMoved>())
			snake.getBody()[0].getDot().setPosition(sf::Vector2f(mouse->position.x, mouse->position.y));
	}
}

void Game::update()
{

}

void Game::render()
{
	window.clear();
	window.draw(snake);
	window.display();
}