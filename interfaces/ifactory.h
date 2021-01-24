#pragma once

#include "iprimitive.h"

/**
 * \interface IFactory
 * @brief Here is primitive objects factory.
 */
class IFactory {
  public:

    IFactory() = default;
    virtual ~IFactory() = default;

    /**
    * @brief Creates Point primitive
    */
    virtual std::unique_ptr<IPrimitiveObject> create(const Point&) const = 0;

    /**
    * @brief Creates line primitive
    */
    virtual std::unique_ptr<IPrimitiveObject> create(const Point&, const Point&) const = 0;

    /**
    * @brief Creates circle primitive
    */
    virtual std::unique_ptr<IPrimitiveObject> create(const Point&, const int&) const = 0;
};
