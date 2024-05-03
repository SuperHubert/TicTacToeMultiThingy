#include <iostream>
#include <vector>
#include "Display.h"
#include "GameData.h"
#include "Controller.h"
#include "Core.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	Core core;
	core.Init();
	core.Run();

    return 0;
}

/*
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <complex>
#include <iostream>
#include "GoLGrid.h"

using namespace std;

#define Random(min,max) ((rand()%(((max-(min))+1)))+(min))

sf::Color getRandomColor()
{
	return sf::Color(Random(0, 1) * 255, Random(0, 1) * 255, Random(0, 1) * 255);
}

double diverge(complex<double> c, unsigned int depth)
{
	complex<double> z0(0, 0);
	for (size_t i = 0; i < depth; i++)
	{
		z0 = (z0 * z0) + c;
		if (abs(z0) > 2) return (double)i / (double)depth;
	}
	return -1;
}

void draw(sf::Image& image, sf::Window& window, unsigned int maxDepth, double multiplier, double posX, double posY)
{
	double sizeX = window.getSize().x;
	double sizeY = window.getSize().y;

	for (unsigned int screenY = 0; screenY < sizeY; screenY++)
	{
		for (unsigned int screenX = 0; screenX < sizeX; screenX++)
		{
			double x = screenX - ((sizeX - 1) * 0.5f);
			double y = screenY - ((sizeY - 1) * 0.5f);
			complex<double> e(x * multiplier + posX, y * multiplier + posY);
			auto vvvv = diverge(e, maxDepth);
			auto col = sf::Color(255 * vvvv, 255 * vvvv, 255 * vvvv);
			image.setPixel(screenX, screenY, !(vvvv > 0) ? sf::Color::White : col);
		}
	}
}

void Fractal()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::CircleShape shape(100.f);

	sf::Image image;

	unsigned int maxDepth = 50;
	double multiplier = 0.0035;
	double posX = 0;
	double posY = 0;

	image.create(window.getSize().x, window.getSize().y, sf::Color::White);

	draw(image, window, maxDepth, multiplier, 0, 0);

	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				multiplier += 0.0001;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				multiplier -= 0.0001;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				posX += -2 * multiplier;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				posX += 2 * multiplier;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				posY += -2 * multiplier;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				posY += 2 * multiplier;
			}

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseWheelScrolled:
				maxDepth += event.mouseWheelScroll.delta > 0 ? 5 : -5;
				if (maxDepth < 6) maxDepth = 6;
				cout << maxDepth << endl;
				break;
			default:
				break;
			}
		}

		window.clear();
		sf::Texture texture;

		draw(image, window, maxDepth, multiplier, posX, posY);

		texture.loadFromImage(image);
		sf::Sprite sprite;
		sprite.setTexture(texture, true);
		window.draw(sprite);
		window.display();
	}
}

void LeJeuDeLaVieLa()
{
	unsigned int size = 100;
	unsigned int resolution = 10;
	GolGrid grid(size, resolution);
	long double deltaTime = 0.01;

	sf::RenderWindow window(sf::VideoMode(size * resolution, size * resolution), "SFML works!");

	grid.display(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				unsigned int x;
				unsigned int y;
				grid.convertWindowCoordinatesCell(pos, window, x, y);
				grid.setCell(x, y, false);
				grid.display(window);
			}

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.scancode)
				{
				case sf::Keyboard::Scan::Space:
					grid.togglePause();
					break;
				case sf::Keyboard::Scan::A:
					deltaTime -= 0.01;
					if (deltaTime < 0) deltaTime = 0;
					cout << "deltaTime : " << deltaTime << endl;
					break;
				case sf::Keyboard::Scan::E:
					deltaTime += 0.01;
					cout << "deltaTime : " << deltaTime << endl;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			unsigned int x;
			unsigned int y;
			grid.convertWindowCoordinatesCell(pos, window, x, y);
			grid.setCell(x, y, true);
			grid.display(window);
		}

		window.clear();
		grid.update(deltaTime);
		grid.display(window);
		window.display();
	}
}
*/