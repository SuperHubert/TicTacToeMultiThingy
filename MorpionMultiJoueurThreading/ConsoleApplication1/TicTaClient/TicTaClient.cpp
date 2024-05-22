#include <iostream>
#include "View.h"
#include "Controller.h"
#include "processthreadsapi.h"


void RunView(View* view)
{
	view->Run();
}

int main()
{
    auto controller = new Controller();
    controller->InitConnection();
    controller->InitReceiveThread();

    auto view = new View();
    view->SetController(controller);

    RunView(view);

    // TODO - add indicator if its your turn
    // TODO - add indicator if you won
    // TODO - add indicator if you lost
    // TODO - add indicator if its a draw
    // TODO - add restart mechanic
}