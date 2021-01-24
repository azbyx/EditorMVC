#include "factory.h"
#include "primitives.h"

std::unique_ptr<IPrimitiveObject> BaseFactory::create(const Point&) const { return nullptr; }

std::unique_ptr<IPrimitiveObject> BaseFactory::create(const Point&, const Point&) const { return nullptr; }

std::unique_ptr<IPrimitiveObject> BaseFactory::create(const Point&, const int&) const { return nullptr; }



std::unique_ptr<IPrimitiveObject> PointFactory::create(const Point& location) const {
    return std::make_unique<PointPrimitive>(location);
}


std::unique_ptr<IPrimitiveObject> LineFactory::create(const Point& location, const Point& end_dot) const {
    return std::make_unique<LinePrimitive>(location, end_dot);
}


std::unique_ptr<IPrimitiveObject> CircleFactory::create(const Point& location, const int& radius) const {
    return std::make_unique<CirclePrimitive>(location, radius);
}
