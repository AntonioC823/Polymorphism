#include "Rectangle.h"

Rectangle::Rectangle()
{
	maxNodes_ = 2;
}

void Rectangle::draw(sf::RenderWindow* window) const
{
	int distanceX = nodes_[1].x - nodes_[0].x;
	int distanceY = nodes_[1].y - nodes_[0].y;

	sf::RectangleShape rectangle;
	rectangle.setPosition(nodes_[0].x, nodes_[0].y);
	rectangle.setSize(sf::Vector2f(distanceX, distanceY));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(2);
	
	window->draw(rectangle);
}

Type Rectangle::getType() const
{
	return RECTANGLE;
}
