#pragma once
class Controller
{
public:
	Controller();
	~Controller();

public:
	void RequestCellClick(int cellIndex);
	void RequestReset();
};

