#include "Line.h"

Line::Line()
{
	maxNodes_ = 2;
}

void Line::draw(sf::RenderWindow* window) const
{
	sf::VertexArray line(sf::LineStrip, maxNodes_);
	line[0].position = sf::Vector2f(nodes_[0].x, nodes_[0].y);
	line[1].position = sf::Vector2f(nodes_[1].x, nodes_[1].y);
	line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Red;

	window->draw(line);
}

Type Line::getType() const
{
	return LINE;
}
