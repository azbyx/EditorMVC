#pragma once

#include "../headers/base_types.h"
#include "../interfaces/ipainter.h"

class PainterOfConsole : public IPainter {
  public:
    void drawDelimeter(const std::string&) const override;

    void drawText(const std::string&) const override;

    void drawPoint(const point&) const override;

    void drawLine(const point&, const dot&) const override;

    void drawCircle(const point&, const int&) const override;
};

