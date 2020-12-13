#pragma once

#include <cstdint>

class dot {
  public:
    int x_coord = 0;
    int y_coord = 0;
};

class point : public dot {
  public:
    point(int x, int y) :dot{x, y} {}

    uint32_t color = 0xffffff;
};

 enum class typePrimitive : uint8_t {
    POINT,
    LINE,
    CIRCLE
 };
