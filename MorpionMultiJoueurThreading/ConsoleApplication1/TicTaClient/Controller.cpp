#include "Controller.h"
#include <iostream>

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::RequestCellClick(int cellIndex)
{
	std::cout << "Cell " << cellIndex << " clicked" << std::endl;
}

void Controller::RequestReset()
{
	std::cout << "Reset requested" << std::endl;
}