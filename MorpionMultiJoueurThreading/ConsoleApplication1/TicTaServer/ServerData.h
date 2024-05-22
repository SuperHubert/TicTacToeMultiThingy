#pragma once


class ServerData
{
public:
	ServerData();
	~ServerData();

protected:
	char board[9] = {0};
	char currentTurn;
	char winner;
public:
	void SetValues(char cells[9], char turn, char player);

	void SetCell(int index, char value);
	void SetCurrentTurn(char turn);
	void RefreshWinner();

	char GetCell(char index);
	bool IsCellEmpty(char index);
	char GetCurrentPlayer();
	char GetWinner();
	char GetCurrentTurn();
};

