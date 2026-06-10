#include "Player.h"

Player::Player(float size) : size(size) { addDot(size * 1.1f); }

void Player::addDot(float size)		{ body.emplace_back(size);}

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