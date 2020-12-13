#pragma once

#include "../headers/base_types.h"
#include <string>

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
    virtual void drawPoint(const point&) const = 0;

    /*!
        @brief Draw lines
    */
    virtual void drawLine(const point&, const dot&) const = 0;

    /*!
        @brief Draw circles
    */
    virtual void drawCircle(const point&, const int&) const = 0;
};
