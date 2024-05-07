#pragma once
class Model
{
public:
	Model();
	~Model();

protected:
	int grid[9];
	int currentTurn;
	int winner;

public:
	void SetValue(int cells[9],int turn,int player);

	int GetCell(int index);
	bool IsCellEmpty(int index);
	int GetCurrentPlayer();
	int GetWinner();
	int GetCurrentTurn();
};

