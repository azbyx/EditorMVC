#include "controller.h"
#include <iostream>
#include <stdexcept>

Controller::Controller(IModelSptr model, IViewSptr view)
        : controllerModel(model), controllerView(view) {
    if(model)
        controllerModel = model;
    else
        throw std::runtime_error("Model mustn't nullptr");

    if(view)
        controllerView = view;
    else
        throw std::runtime_error("View mustn't nullptr");

    controllerModel->subscribe(controllerView);
    controllerModel->notifyUpdate();
}

void Controller::commandClear() {

    controllerModel->newModel();
    controllerModel->notifyUpdate();
}

void Controller::commandNewPoint(const Point& location) {

    controllerModel->addPoint(location);
    controllerModel->notifyUpdate();
}

void Controller::commandNewLine(const Point& location, const Point& end_dot) {

    controllerModel->addLine(location, end_dot);
    controllerModel->notifyUpdate();
}

void Controller::commandNewCircle(const Point& location, const int& radius) {

    controllerModel->addCircle(location, radius);
    controllerModel->notifyUpdate();
}

void Controller::commandRemoveShape() {

    controllerModel->removeLast();
    controllerModel->notifyUpdate();
}

void Controller::commandOpenSuite(const std::string& fileName) {

    controllerModel->newModel();
    controllerModel->addPoint(Point{100, 258});
    controllerModel->addLine(Point{11, 21}, Point{33, 44});
    controllerModel->addCircle(Point{110, 212}, 99);
    controllerModel->notifyUpdate();
    std::cout << "Current project have been updated from: " << fileName << std::endl;
}

void Controller::commandSaveSuite(const std::string& fileName) {
    //TODO saving
    std::cout << "Current project have been saved to: " << fileName << std::endl;
}

bool Controller::readCommand(){

    std::string str_command;
    int x = 0, y = 0, xe = 0, ye = 0;

    std::cout << "input command: (ap: add Point; al: add line; ac: add circle; rm: remove last object;\nclr: clear model; opn: open doc; sav: save doc; exit: exited from this)\n>";
    std::cin >> str_command;

    if("exit" == str_command){

        return false;
    }
    else if("ap" == str_command){

        std::cout << "input locatoin - x and y: ";
        std::cin >> x >> y;
        //TODO validate
        commandNewPoint(Point{x, y});

        return true;
    }
    else if("ac" == str_command){

        std::cout << "input locatoin - x and y and radius: ";
        std::cin >> x >> y >> xe;
        //TODO validate
        commandNewCircle(Point{x, y}, xe);

        return true;
    }
    else if("al" == str_command){

        std::cout << "input begin locatoin - x and y and end locatoin - x1 and y1: ";

        std::cin >> x >> y >> xe >> ye;
        //TODO validate
        commandNewLine(Point{x, y}, Point{xe, ye});

        return true;
    }
    else if("rm" == str_command){

        commandRemoveShape();

        return true;
    }
    else if("clr" == str_command){

        commandClear();

        return true;
    }
    else if("opn" == str_command){

        commandOpenSuite("exampleModel");

        return true;
    }
    else if("sav" == str_command){

        commandSaveSuite("newModel");

        return true;
    }
    else{

        std::cout << "bad command, try again" << std::endl;

        return true;
    }

}

void Controller::loop(){

     while(readCommand());

}

