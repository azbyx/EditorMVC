#pragma once

#include "base_types.h"
#include "ipainter.h"

class PainterOfConsole : public IPainter {
  public:
    void drawDelimeter(const std::string&) const override;

    void drawText(const std::string&) const override;

    void drawPoint(const Point&) const override;

    void drawLine(const Point&, const Point&) const override;

    void drawCircle(const Point&, const int&) const override;
};

