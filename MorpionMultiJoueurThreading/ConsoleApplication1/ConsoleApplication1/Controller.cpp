#include "Controller.h"
#include "GameData.h"
#include "Display.h"

#include <iostream>

int Controller::totalPlayers = 0;

Controller::Controller()
{
	totalPlayers++;
	id = totalPlayers;
	std::cout << "Player " << id << " created" << std::endl;
}

Controller::~Controller()
{
}

void Controller::HandleInput(int x, int y,GameData* data,Display* display)
{
	int cell = display->IsInCell(x, y);

	std::cout << "Player " << id << " clicked cell " << cell << std::endl;

	if (cell != -1 && data->GetCell(cell) == -1)
	{
		data->SetCell(cell, id);
		data->NextPlayer();
	}
}
