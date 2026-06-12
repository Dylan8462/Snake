#pragma once
#include <SFML/System/Vector2.hpp>
#include <ostream>

template <typename T>
std::ostream& operator<<(std::ostream& out, const sf::Vector2<T>& vec)
{
	return out << "(" << vec.x << ", " << vec.y << ")";
}