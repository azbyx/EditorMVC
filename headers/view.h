#pragma once

#include "../interfaces/imodel.h"

class View : public IView {
public:
    View(std::shared_ptr<IModel> model, std::shared_ptr<IPainter>);
    virtual ~View() = default;

    void update() const noexcept override;

private:
    std::shared_ptr<IModel>   viewModel;
    std::shared_ptr<IPainter> viewPainter;
};
