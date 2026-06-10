#pragma once
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable
{
public:
	Body(float);

	float getSize() const;
	sf::CircleShape& getDot();

	void setColor(const sf::Color&);

	void draw(sf::RenderTarget&, sf::RenderStates) const override;

	friend std::ostream& operator<<(std::ostream&, const Body&);

private:
	float size;
	sf::CircleShape dot;
};