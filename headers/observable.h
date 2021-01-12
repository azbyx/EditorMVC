#pragma once

#include "iview.h"
#include <list>
#include <memory>

/**
 * @brief Here is doing monitoring
 */
class  Observable {
public:

    Observable() = default;
    virtual ~Observable() = default;

    void subscribe(IViewSptr in_observer) noexcept {
        observers.push_back(in_observer);
    }

    void unsubscribe(IViewSptr in_observer) noexcept {
        observers.remove_if([in_observer](std::weak_ptr<IView> &obs) {
            return obs.expired() || obs.lock() == in_observer;
        });
    }

    void notifyUpdate() noexcept {
        for (auto &obs : observers) {

            if (auto sptr = obs.lock())
                sptr->update();

        }
    }

private:
    std::list<std::weak_ptr<IView>> observers;
};
