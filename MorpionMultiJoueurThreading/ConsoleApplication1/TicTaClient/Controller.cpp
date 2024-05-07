#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	model = new Model();
}

Controller::~Controller()
{
	delete model;
}

void Controller::SetModelDisplayer(ModelDisplayer* displayer)
{
	modelDisplayer = displayer;
}

void Controller::RequestCellClick(int index)
{
	std::cout << "Cell " << index << " click requested" << std::endl;

	modelDisplayer->UpdateScreen(model);
}

void Controller::RequestReset()
{
	std::cout << "Reset requested" << std::endl;
}

Model* Controller::GetModel()
{
	return model;
}
