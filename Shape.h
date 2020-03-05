#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

enum Type
{
	LINE,
	CIRCLE,
	RECTANGLE
};

class Shape
{
public:
	Shape();
	virtual void draw(sf::RenderWindow* window) const = 0;
	void setNode(sf::Vector2i point);
	void moveCurrentNode(sf::Vector2i point);
	bool isFirstNode() const;
	bool isLastNode() const;
	virtual Type getType() const = 0;
protected:
	std::vector<sf::Vector2i> nodes_;
	int maxNodes_;
};
