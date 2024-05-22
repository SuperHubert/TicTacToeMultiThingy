#pragma once
#include <iostream>
#include <string>

class ModelDisplayer;

class Model
{
public:
	Model();
	~Model();

protected:
	char grid[9];
	char currentPlayer = 0;

public:
	void SetValues(std::string state);

	int GetCell(int index);
	bool IsCellEmpty(int index);
	int GetCurrentPlayer();
	int GetWinner();
	int GetCurrentTurn();
};

