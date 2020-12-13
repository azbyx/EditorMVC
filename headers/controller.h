#pragma once

#include "../interfaces/icontroller.h"
#include "../interfaces/imodel.h"
#include "../interfaces/iview.h"
#include <memory>

class Controller : public IController {


  public:
    Controller(std::shared_ptr<IModel>, std::shared_ptr<IView>);
    virtual ~Controller() = default;

    void commandClear() override;

    void commandNewPoint(const point&) override;

    void commandNewLine(const point&, const dot&) override;

    void commandNewCircle(const point&, const int&) override;

    void commandRemoveShape() override;

    void commandOpenSuite(const std::string&) override;

    void commandSaveSuite(const std::string&) override;

    void loop() override;

  private:
    bool readCommand() override;

  private:
    std::shared_ptr<IModel> controllerModel;
    std::shared_ptr<IView>  controllerView;
};
