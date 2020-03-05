#pragma once
#include "Shape.h"

class Line : public Shape
{
public:
	Line();
	void draw(sf::RenderWindow* window) const;
	Type getType() const;
};
