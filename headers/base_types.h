#pragma once

#include <cstdint>


struct Point {
    int x_coord = 0;
    int y_coord = 0;
};

 enum class typePrimitive : uint8_t {
    POINT,
    LINE,
    CIRCLE
 };
