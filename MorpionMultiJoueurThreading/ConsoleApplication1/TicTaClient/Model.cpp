#include "Model.h"

Model::Model()
{
    for (int i = 0; i < 9; i++)
    {
		grid[i] = 0;
	}
	currentPlayer = '1';
	version = 0;
	canPlay = false;
}

Model::~Model()
{

}

char Model::GetVersion()
{
	return version;
}

bool Model::GetCanPlay()
{
	return canPlay;
}

void Model::SetCanPlay(bool value)
{
	canPlay = value;
}

void Model::SetValues(std::string state)
{
    for (int i = 0; i < 9; i++)
    {
		grid[i] = state[i];
	}
	currentPlayer = state[9];

	std::cout << "Model updated" << std::endl;
	
	version++;
	//reinterpret_cast<void(*)()> (callback) ();
}

char Model::GetCell(int index)
{
    if(index < 0 || index > 8) return -1;
    return grid[index] - '0';
}

bool Model::IsCellEmpty(int index)
{
    return GetCell(index) == 0;
}

int Model::GetCurrentPlayer()
{
    return currentPlayer;
}

int Model::GetWinner()
{
    return currentPlayer;
}

int Model::GetCurrentTurn()
{
	return version;
}
