#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle();
	void draw(sf::RenderWindow* window) const;
	Type getType() const;
};
