#pragma once
#include "Model.h"
#include "ModelDisplayer.h"

class Controller
{
public:
	Controller();
	~Controller();

protected:
	Model* model;
	ModelDisplayer* modelDisplayer;

public:
	void SetModelDisplayer(ModelDisplayer*);
	void RequestCellClick(int);
	void RequestReset();
	Model* GetModel();
};

