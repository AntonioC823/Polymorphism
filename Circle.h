#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle();
	void draw(sf::RenderWindow* window) const;
	Type getType() const;
};
