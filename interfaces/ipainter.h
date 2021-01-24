#pragma once

#include "base_types.h"
#include <string>
#include <memory>

/**
 * \interface IPainter
 * @brief Here is painter for drawing primitive objects.
 */
class IPainter {
  public:
    IPainter() = default;
    virtual ~IPainter() = default;

    /*!
        @brief Draw delimeter of screen
    */
    virtual void drawDelimeter(const std::string&) const = 0;

    /*!
        @brief Draw text information
    */
    virtual void drawText(const std::string&) const = 0;

    /*!
        @brief Draw points
    */
    virtual void drawPoint(const Point&) const = 0;

    /*!
        @brief Draw lines
    */
    virtual void drawLine(const Point&, const Point&) const = 0;

    /*!
        @brief Draw circles
    */
    virtual void drawCircle(const Point&, const int&) const = 0;
};

using IPainterSptr = std::shared_ptr<IPainter>;
