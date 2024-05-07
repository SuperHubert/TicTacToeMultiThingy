#include "View.h"
#include <iostream>

View::View()
{
	modelDisplayer = new ModelDisplayer();
	window = modelDisplayer->GetWindow();
	controller = nullptr;
}

View::~View()
{
	delete modelDisplayer;
	delete window;
	delete controller;
}

void View::SetController(Controller* controller)
{
	this->controller = controller;
}

void View::Run()
{
	if (controller == nullptr)
	{
		std::cout << "Controller not set" << std::endl;
		return;
	}

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				auto mousePos = sf::Mouse::getPosition(*window);
				auto cell = modelDisplayer->IsInCell(mousePos.x, mousePos.y);
				if (cell != -1)
				{
					controller->RequestCellClick(cell);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				controller->RequestReset();
			}
		}
	}

	std::cout << "Oof" << std::endl;
}
