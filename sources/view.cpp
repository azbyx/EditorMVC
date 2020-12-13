#include "../headers/view.h"


View::View(std::shared_ptr<IModel> model, std::shared_ptr<IPainter> painter)
           : viewModel(model), viewPainter(painter) {}

void View::update() const noexcept {
    viewModel->draw(viewPainter);
}
