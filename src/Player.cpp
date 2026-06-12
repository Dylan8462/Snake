#include "Player.h"

#include <iostream>
#include <cmath>

#include "Functions.h"

using std::cout;

Player::Player(float size) : size(size), tick(0), fps(60)
{
	std::cout << "CTOR tick: " << tick
		<< "\tfps: " << fps
		<< "\tthis: " << this << "\t";

	std::cout << "\tbody addr: " << body.data() << "\n";

	addDot(size * 1.1f);
}

void Player::update(const sf::Vector2i& mouse)
{

	tick++;
	auto pos = sf::Vector2i(body[0].getDot().getPosition()) - mouse;

	//if (tick % fps == 0)
	cout //<< "pos diff: " << pos << "\t"
		//<< "length: " << std::hypot(pos.x, pos.y) << "\t"
		<< "tick: " << tick << "\t" << "fps: " << fps << "\t"
		<< "this: " << this << "\t";
	std::cout << "body addr: " << body.data() << "\n";
}

void Player::addDot(float size) { body.emplace_back(size); }

std::vector<Body>& Player::getBody()
{
	return body;
}

void Player::position()
{
	for (size_t i = 0; i < body.size(); i++)
		body[i].getDot().setPosition({ i * body[i].getSize() * 1.5f + 100, 100 });

	/*for (size_t i = 0; i < body.size(); i++)
		body[i].getDot().setPosition({ 100, 100 });*/
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& dot : body)
		target.draw(dot);
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	for (size_t i = 0; i < player.body.size(); i++)
		out << "Dot: " << i + 1 << "\n" << player.body[i];

	return out;
}