#include "Model.h"

Model::Model()
{
    for (int i = 0; i < 9; i++)
    {
		grid[i] = 0;
	}
	currentPlayer = 0;
}

Model::~Model()
{

}

void Model::SetValues(std::string state)
{
    for (int i = 0; i < 9; i++)
    {
		grid[i] = state[i];
	}
	currentPlayer = state[9];

	std::cout << "Model updated" << std::endl;
	
	//reinterpret_cast<void(*)()> (callback) ();
}

int Model::GetCell(int index)
{
    if(index < 0 || index > 8) return -1;
    return grid[index];
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
	int count = 0;
	for (size_t i = 0; i < 9; i++)
	{
		if (grid[i] != 0)
		{
			count++;
		}
	}
	return count;
}
