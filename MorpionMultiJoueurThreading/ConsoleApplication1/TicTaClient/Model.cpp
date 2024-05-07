#include "Model.h"

Model::Model()
{
    for (int i = 0; i < 9; i++)
    {
		grid[i] = -1;
	}
	currentTurn = 0;
	winner = -1;
}

Model::~Model()
{

}

void Model::SetValue(int cells[9], int turn, int player)
{
    for (int i = 0; i < 9; i++)
    {
		grid[i] = cells[i];
	}
	currentTurn = turn;
	winner = player;
}

int Model::GetCell(int index)
{
    if(index < 0 || index > 8)return -1;
    return grid[index];
}

bool Model::IsCellEmpty(int index)
{
    return GetCell(index) == -1;
}

int Model::GetCurrentPlayer()
{
    return currentTurn % 2;
}

int Model::GetWinner()
{
    return winner;
}

int Model::GetCurrentTurn()
{
    return currentTurn;
}
