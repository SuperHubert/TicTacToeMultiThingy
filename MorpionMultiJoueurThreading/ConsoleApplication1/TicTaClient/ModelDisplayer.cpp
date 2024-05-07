#include "ModelDisplayer.h"
#include <iostream>
#include <string>

ModelDisplayer::ModelDisplayer()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
	winnerText = new sf::Text();
	currentTurnText = new sf::Text();

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
		return;
	}

	auto setupText = [&](sf::Text* text, const char* str, int x, int y, int size)
		{
			text->setFont(font);
			text->setString(str);
			text->setCharacterSize(size);
			text->setPosition(x, y);
			text->setFillColor(sf::Color::White);
		};

	setupText(winnerText, "Player 1's turn", 0, 0, 24);
	setupText(currentTurnText, "Current Turn: 0", 0, 24, 24);
}

ModelDisplayer::~ModelDisplayer()
{
	delete window;
	delete winnerText;
}

void ModelDisplayer::DisplayGrid()
{
	int centerWidth = WIDTH / 2;
	int centerHeight = HEIGHT / 2;

	float cellSpacing = 10.0f;

	for (size_t i = 0; i < 9; i++)
	{
		auto x = (i % 3) * (CELL_SIZE + CELL_SPACING) + centerWidth - (1.5f * CELL_SIZE + CELL_SPACING);
		auto y = (i / 3) * (CELL_SIZE + CELL_SPACING) + centerHeight - (1.5f * CELL_SIZE + CELL_SPACING);

		sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE, CELL_SIZE));
		rectangle.setPosition(x, y);
		rectangle.setFillColor(sf::Color::Black);
		rectangle.setOutlineColor(sf::Color::White);
		rectangle.setOutlineThickness(CELL_THICKNESS);

		cellBounds[i] = rectangle.getGlobalBounds();

		window->draw(rectangle);
	}
}

void ModelDisplayer::DisplayCircle(int x, int y, int radius)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(CIRCLE_THICKNESS);
	circle.setPosition(x, y);

	window->draw(circle);
}

void ModelDisplayer::DisplayCross(int x, int y, int length)
{
	sf::RectangleShape line(sf::Vector2f(length, CROSS_THICKNESS));
	line.setFillColor(sf::Color::White);
	line.setPosition(x, y);

	window->draw(line);

	line.rotate(90);
	window->draw(line);
}

void ModelDisplayer::SetCurrentPlayerText(Model* model)
{
	std::string str = "Player ";
	str += std::to_string(model->GetCurrentPlayer() + 1);
	str += "'s turn";

	winnerText->setString(str);
	window->draw(*winnerText);
}

void ModelDisplayer::SetCurrentTurnText(Model* model)
{
	std::string str = "Current Turn: ";
	str += std::to_string(model->GetCurrentTurn());

	currentTurnText->setString(str);
	window->draw(*currentTurnText);
}

sf::RenderWindow* ModelDisplayer::GetWindow()
{
	return window;
}

void ModelDisplayer::UpdateScreen(Model* model)
{
	std::cout << "UpdateScreen" << std::endl;

	window->clear();

	window->draw(*winnerText);
	window->draw(*currentTurnText);

	DisplayGrid();

	for (size_t i = 0; i < 9; i++)
	{
		int x = (i % 3) * (CELL_SIZE + CELL_SPACING) + WIDTH / 2 - (1.5f * CELL_SIZE + CELL_SPACING) + CELL_SIZE / 2;
		int y = (i / 3) * (CELL_SIZE + CELL_SPACING) + HEIGHT / 2 - (1.5f * CELL_SIZE + CELL_SPACING) + CELL_SIZE / 2;

		if (model->GetCell(i) == 0)
		{
			DisplayCircle(x, y, CIRCLE_RADIUS);
		}
		else if (model->GetCell(i) == 1)
		{
			DisplayCross(x, y, CROSS_LENGTH);
		}
	}

	SetCurrentPlayerText(model);
	SetCurrentTurnText(model);

	window->display();
}

int ModelDisplayer::IsInCell(int x, int y)
{
	for (size_t i = 0; i < 9; i++)
	{
		if (cellBounds[i].contains(x, y))
		{
			return i;
		}
	}

	return -1;
}
