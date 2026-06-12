#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Body.h"

class Player : public sf::Drawable
{
public:
	Player(float);

	void update(const sf::Vector2i&);

	void addDot(float);

	std::vector<Body>& getBody();

	void position();

	void draw(sf::RenderTarget&, sf::RenderStates) const override;

	friend std::ostream& operator<<(std::ostream&, const Player&);

private:
	float size;
	std::vector<Body> body;

	sf::Vector2f vel;

	int tick = 0;
	int fps = 60;
};