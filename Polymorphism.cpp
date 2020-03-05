#include "SFML\Graphics.hpp"
#include <vector>
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const int FRAME_RATE = 60;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Polymorphism");
	window.setFramerateLimit(FRAME_RATE);

	Shape* currentShape = nullptr;
	std::vector<Shape*> shapes;

	sf::Mouse mouse;

	sf::Clock clock;
	sf::Time timer;

	sf::Font font;
	font.loadFromFile("OpenSans-Bold.ttf");

	timer = clock.restart();
	while (window.isOpen())
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		// Update
		sf::Vector2i mouseCoordinate(mouse.getPosition(window).x, mouse.getPosition(window).y);

		timer = clock.getElapsedTime();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			currentShape = new Line();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			currentShape = new Circle();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			currentShape = new Rectangle();
		}

		if (currentShape != nullptr && !currentShape->isFirstNode())
		{
			currentShape->moveCurrentNode(mouseCoordinate);
		}

		if (currentShape != nullptr && sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer.asSeconds() > 0.5f)
		{
			currentShape->setNode(mouseCoordinate);

			timer = clock.restart();
		}

		if (currentShape != nullptr && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (currentShape->isLastNode())
			{
				shapes.push_back(currentShape);

				switch (currentShape->getType())
				{
				case LINE:
					currentShape = new Line();
					break;
				case CIRCLE:
					currentShape = new Circle();
					break;
				case RECTANGLE:
					currentShape = new Rectangle();
					break;
				}

				timer = clock.restart();
			}
		}

		// Clear Window
		window.clear();

		// Draw objects

		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->draw(&window);
		}

		if (currentShape != nullptr && currentShape->isLastNode())
		{
			currentShape->draw(&window);

			sf::Text helpText("Please press the space bar to set the shape", font);
			helpText.setPosition(WINDOW_WIDTH * 0.25, WINDOW_HEIGHT * 0.00);
			helpText.setCharacterSize(20);
			helpText.setStyle(sf::Text::Bold);
			helpText.setFillColor(sf::Color::Yellow);
			window.draw(helpText);
		}

		sf::Text shapeCountText("Total shapes: " + std::to_string(shapes.size()), font);
		shapeCountText.setCharacterSize(20);
		shapeCountText.setStyle(sf::Text::Bold);
		shapeCountText.setFillColor(sf::Color::Yellow);
		window.draw(shapeCountText);


		window.display();
	}

	delete currentShape;
	currentShape = nullptr;

	return 0;
}
