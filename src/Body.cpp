#include "Player.h"

Body::Body(float size) : size(size), dot(size)
{
	dot.setOrigin({ size, size });
}

float Body::getSize() const			{ return size; }
sf::CircleShape& Body::getDot()		{ return dot; }

void Body::setColor(const sf::Color& color)		{ dot.setFillColor(color); }

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(dot);
}

std::ostream& operator<<(std::ostream& out, const Body& body)
{
	out << "Position: (" << body.dot.getPosition().x << ", " << body.dot.getPosition().y << ")\t"
		<< "Size: " << body.size << "\t"
		<< "Radius: " << body.dot.getRadius() << "\t"
		<< "Origin: (" << body.dot.getOrigin().x << ", " << body.dot.getOrigin().y << ")\n";

	return out;
}