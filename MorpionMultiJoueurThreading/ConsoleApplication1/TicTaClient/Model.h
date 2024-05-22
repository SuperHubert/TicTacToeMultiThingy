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
	char currentPlayer = '1';
	char version = 0;

public:
	char GetVersion();

	void SetValues(std::string state);
	char GetCell(int index);
	bool IsCellEmpty(int index);
	int GetCurrentPlayer();
	int GetWinner();
	int GetCurrentTurn();
};

