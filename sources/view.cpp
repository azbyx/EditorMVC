#include "view.h"
#include <stdexcept>

View::View(IModelSptr model, IPainterSptr painter) {
    if(model)
        viewModel = model;
    else
        throw std::runtime_error("Model mustn't nullptr");

    if(painter)
        viewPainter = painter;
    else
        throw std::runtime_error("Painter mustn't nullptr");
}

void View::update() const noexcept {
    viewModel->draw(viewPainter);
}
