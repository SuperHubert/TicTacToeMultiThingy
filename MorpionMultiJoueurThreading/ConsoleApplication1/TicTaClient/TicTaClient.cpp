#include <iostream>
#include "View.h"
#include "Controller.h"

int main()
{
    auto view = new View();
    auto controller = new Controller();
    view->SetController(controller);

    view->Run();
}