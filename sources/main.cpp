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

#include "../headers/controller.h"
#include "../headers/view.h"
#include "../headers/model.h"
#include "../headers/painter.h"



int main(int, char**){

    std::shared_ptr<IModel>           model = std::make_shared<Model>();
    std::shared_ptr<IPainter>       painter = std::make_shared<PainterOfConsole>();
    std::shared_ptr<IView>             view = std::make_shared<View>(model, painter);
    std::shared_ptr<IController> controller = std::make_shared<Controller>(model, view);

    //controller->commandOpenSuite("anyName");
    controller->loop();

    return 0;
}
