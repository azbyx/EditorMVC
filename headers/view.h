#pragma once

#include "imodel.h"

class View : public IView {
public:
    View(IModelSptr, IPainterSptr);
    virtual ~View() = default;

    void update() const noexcept override;

private:
    IModelSptr   viewModel;
    IPainterSptr viewPainter;
};
