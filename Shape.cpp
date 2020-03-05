#include "Shape.h"

Shape::Shape()
{
	maxNodes_ = 0;
}

void Shape::setNode(sf::Vector2i point)
{
	if (nodes_.size() < maxNodes_)
	{
		nodes_.push_back(point);
	}
}

void Shape::moveCurrentNode(sf::Vector2i point)
{
	if (nodes_.size() >= 1)
	{
		nodes_[nodes_.size() - 1] = point;
	}
}

bool Shape::isFirstNode() const
{
	if (nodes_.size() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Shape::isLastNode() const
{
	if (nodes_.size() == maxNodes_)
	{
		return true;
	}
	else
	{
		return false;
	}
}
