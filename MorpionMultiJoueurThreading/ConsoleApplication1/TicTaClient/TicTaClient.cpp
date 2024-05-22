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
    //HANDLE ViewThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)RunView, view, 0, NULL);
}