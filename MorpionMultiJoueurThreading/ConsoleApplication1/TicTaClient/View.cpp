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

void UpdateScreen(ModelDisplayer* modelDisplayer, Model* model)
{
	modelDisplayer->UpdateScreen(model);
	std::cout << "UpdateScreen" << std::endl;
	return;
}

void View::SetController(Controller* controller)
{
	this->controller = controller;

	controller->SetModelDisplayer(modelDisplayer);
}

void updateScreen(ModelDisplayer* modelDisplayer, Model* model)
{
	std::cout << "Model update callback" << std::endl;
	
}

void View::Run()
{
	if (controller == nullptr)
	{
		std::cout << "Controller not set" << std::endl;
		return;
	}
	/*
	ModelDisplayer* displayer = modelDisplayer;
	Model* model = controller->GetModel();

	auto f1 = [displayer, model]()
	{
		displayer->UpdateScreen(model);
	};

	//model->callback = &f1;

	f1();
	*/

	Model* model = controller->GetModel();

	char version = model->GetVersion();
	modelDisplayer->UpdateScreen(model);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				return;
			}

			if (event.type == sf::Event::MouseButtonReleased)
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

		if (model->GetVersion() != version)
		{
			modelDisplayer->UpdateScreen(model);
			version = model->GetVersion();
		}
	}

	std::cout << "Oof" << std::endl;
}