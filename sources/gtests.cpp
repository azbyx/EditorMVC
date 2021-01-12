#define NDEBUG

#include "icontroller.h"
#include "controller.h"
#include "view.h"
#include "model.h"
#include "painter.h"
#include "gmock/gmock.h"
#include <memory>


class MockControllerI : public IController {
  public:

    MockControllerI(IModelSptr model, IViewSptr view)
        : controllerModel(model), controllerView(view) {
        controllerModel->subscribe(controllerView);
        controllerModel->notifyUpdate();
    }
    MOCK_METHOD(void, commandClear, (), (override));
    MOCK_METHOD(void, commandNewPoint, (const Point&), (override));
    MOCK_METHOD(void, commandNewLine, (const Point&, const Point&), (override));
    MOCK_METHOD(void, commandNewCircle, (const Point&, const int&), (override));
    MOCK_METHOD(void, commandRemoveShape, (), (override));
    MOCK_METHOD(void, commandOpenSuite, (const std::string&), (override));
    MOCK_METHOD(void, commandSaveSuite, (const std::string&), (override));
    MOCK_METHOD(void, loop, (), (override));
    MOCK_METHOD(bool, readCommand, (), (override));

  private:
    IModelSptr controllerModel;
    IViewSptr  controllerView;
};

/*
class MockPainterI : public IPainter {
  public:
    void drawDelimeter(const std::string&) const {};

    void drawText(const std::string&) const {};

    void drawPoint(const Point&) const  {};

    void drawLine(const Point&, const Point&) const {};

    void drawCircle(const Point&, const int&) const {};
};
*/

TEST(controller_test, interface_test) {

    using ::testing::AtLeast;

    IModelSptr           model = std::make_shared<Model>();
    IPainterSptr       painter = std::make_shared<PainterOfConsole>();
    IViewSptr             view = std::make_shared<View>(model, painter);

    MockControllerI controller(model, view);

    EXPECT_CALL(controller, commandClear()).Times(AtLeast(1));
    controller.commandClear();

}

int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}


