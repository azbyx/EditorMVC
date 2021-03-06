/**
    \file
    \mainpage Homework 4 of the course "C ++ Developer. Professional" LLC "Otus Online Education"
	\brief Homework 4 of the course "C ++ Developer. Professional" LLC "Otus Online Education"
	\author Bulanov Sergey
	\version 0.0.1
	\date December 2020
	\warning There was done for educational purposes.

*This project is an implementation of the graphic editor functionality using MVC.
*/

#define NDEBUG

#include "controller.h"
#include "view.h"
#include "model.h"
#include "painter.h"



int main(int, char**){

    IModelSptr           model = std::make_shared<Model>();
    IPainterSptr       painter = std::make_shared<PainterOfConsole>();
    IViewSptr             view = std::make_shared<View>(model, painter);
    IControllerSptr controller = std::make_shared<Controller>(model, view);

    controller->loop();

    return 0;
}
