#pragma once

class GameData
{
public:
	GameData();
	~GameData();

protected:
	int grid[9];
	int currentPlayer;
	int currentTurn;
	int winner;
	
public:
	int GetCell(int index);
	void SetCell(int index, int value);
	void SetCell(int x,int y, int value);
	void NextPlayer();
	int GetCurrentPlayer();
	int GetWinner();
	int GetCurrentTurn();
	void SetWinner();
	void Reset();
	void CheckDraw();
};

