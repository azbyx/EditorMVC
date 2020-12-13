#pragma once

#include "../interfaces/iprimitive.h"

/**
 * \interface IFactory
 * @brief Here is primitive objects factory.
 */
class IFactory {
  public:

    IFactory() = default;
    virtual ~IFactory() = default;

    /**
    * @brief Creates point primitive
    */
    virtual std::unique_ptr<IPrimitiveObject> create(const point&) const = 0;

    /**
    * @brief Creates line primitive
    */
    virtual std::unique_ptr<IPrimitiveObject> create(const point&, const dot&) const = 0;

    /**
    * @brief Creates circle primitive
    */
    virtual std::unique_ptr<IPrimitiveObject> create(const point&, const int&) const = 0;
};
