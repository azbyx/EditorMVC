#pragma once

/**
 * \interface IView
 * @brief Here is doing notifications
 */
class IView {
public:

    IView() = default;
    virtual ~IView() = default;

    /**
    * @brief Updates dependent objects
    */
    virtual void update() const noexcept = 0;

};

using IViewSptr = std::shared_ptr<IView>;
