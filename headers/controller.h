#pragma once

#include "icontroller.h"
#include "imodel.h"
#include "iview.h"
#include <memory>

class Controller : public IController {


  public:
    Controller(IModelSptr, IViewSptr);
    virtual ~Controller() = default;

    void commandClear() override;

    void commandNewPoint(const Point&) override;

    void commandNewLine(const Point&, const Point&) override;

    void commandNewCircle(const Point&, const int&) override;

    void commandRemoveShape() override;

    void commandOpenSuite(const std::string&) override;

    void commandSaveSuite(const std::string&) override;

    void loop() override;

  private:
    bool readCommand() override;

  private:
    IModelSptr controllerModel;
    IViewSptr  controllerView;
};
