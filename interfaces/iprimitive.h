#pragma once

#include "../interfaces/ipainter.h"
#include <memory>

/**
 * \interface IPrimitiveObject
 * @brief Here is interface is common for all primitive objects.
 */
class IPrimitiveObject {
  public:

    /*!
        @brief Drawing with a specific graphics painter
    */
    virtual void draw(std::shared_ptr<IPainter>) const = 0;

    /*!
        @brief sets end point of line primitive objects
    */
    virtual void set_end(const dot&) = 0;

     /*!
        @brief sets radius of circle primitive objects
    */
    virtual void set_radius(const int&) = 0;
};
