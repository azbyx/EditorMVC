#include "../headers/factory.h"
#include "../headers/primitives.h"

std::unique_ptr<IPrimitiveObject> BaseFactory::create(const point&) const { return nullptr; }

std::unique_ptr<IPrimitiveObject> BaseFactory::create(const point&, const dot&) const { return nullptr; }

std::unique_ptr<IPrimitiveObject> BaseFactory::create(const point&, const int&) const { return nullptr; }



std::unique_ptr<IPrimitiveObject> PointFactory::create(const point& location) const {
    return std::make_unique<PointPrimitive>(location);
}


std::unique_ptr<IPrimitiveObject> LineFactory::create(const point& location, const dot& end_dot) const {
    return std::make_unique<LinePrimitive>(location, end_dot);
}


std::unique_ptr<IPrimitiveObject> CircleFactory::create(const point& location, const int& radius) const {
    return std::make_unique<CirclePrimitive>(location, radius);
}
