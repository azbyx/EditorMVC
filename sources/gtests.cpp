#define NDEBUG


#include "../interfaces/icontroller.h"
#include "../headers/controller.h"
#include "../headers/view.h"
#include "../headers/model.h"
#include "../headers/painter.h"
#include "gmock/gmock.h"
#include <memory>


class MockControllerI : public IController {
  public:

    MockControllerI(std::shared_ptr<IModel> model, std::shared_ptr<IView> view)
        : controllerModel(model), controllerView(view) {
        controllerModel->subscribe(controllerView);
        controllerModel->notifyUpdate();
    }
    MOCK_METHOD(void, commandClear, (), (override));
    MOCK_METHOD(void, commandNewPoint, (const point&), (override));
    MOCK_METHOD(void, commandNewLine, (const point&, const dot&), (override));
    MOCK_METHOD(void, commandNewCircle, (const point&, const int&), (override));
    MOCK_METHOD(void, commandRemoveShape, (), (override));
    MOCK_METHOD(void, commandOpenSuite, (const std::string&), (override));
    MOCK_METHOD(void, commandSaveSuite, (const std::string&), (override));
    MOCK_METHOD(void, loop, (), (override));
  private:
    MOCK_METHOD(bool, readCommand, (), (override));

  private:
    std::shared_ptr<IModel> controllerModel;
    std::shared_ptr<IView>  controllerView;
};


class MockPainterI : public IPainter {
  public:
    void drawDelimeter(const std::string&) const {};

    void drawText(const std::string&) const {};

    void drawPoint(const point&) const  {};

    void drawLine(const point&, const dot&) const {};

    void drawCircle(const point&, const int&) const {};
};

TEST(controller_test, interface_test) {

    using ::testing::AtLeast;

    std::shared_ptr<IModel>           model = std::make_shared<Model>();
    std::shared_ptr<IPainter>       painter = std::make_shared<PainterOfConsole>();
    std::shared_ptr<IView>             view = std::make_shared<View>(model, painter);

    MockControllerI controller(model, view);

    EXPECT_CALL(controller, commandClear()).Times(AtLeast(1));
    controller.commandClear();

}

int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

