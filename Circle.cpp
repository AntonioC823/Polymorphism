#include "Circle.h"

Circle::Circle()
{
	maxNodes_ = 2;
}

void Circle::draw(sf::RenderWindow* window) const
{
	int distance = sqrt(((nodes_[0].x - nodes_[1].x) * (nodes_[0].x - nodes_[1].x)) + 
					  ((nodes_[0].y - nodes_[1].y) * (nodes_[0].y - nodes_[1].y)));

	sf::CircleShape circle;
	circle.setPosition(nodes_[0].x, nodes_[0].y);
	circle.setOrigin(circle.getOrigin().x + distance, circle.getOrigin().y + distance);
	circle.setRadius(distance);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2);

	window->draw(circle);
}

Type Circle::getType() const
{
	return CIRCLE;
}
