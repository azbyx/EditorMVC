#include "../headers/primitives.h"


PrimitiveObject::PrimitiveObject(const point& point_) : location{point_.x_coord, point_.y_coord} {}

void PrimitiveObject::draw(std::shared_ptr<IPainter>) const {}

void PrimitiveObject::set_end(const dot&) {}

void PrimitiveObject::set_radius(const int&) {}

void PrimitiveObject::set_location(const point& point_) {
    location = point_;
}


PointPrimitive::PointPrimitive(const point& point_) : PrimitiveObject(point_) {}

void PointPrimitive::draw(std::shared_ptr<IPainter> painter) const {
    painter->drawPoint(location);
}


LinePrimitive::LinePrimitive(const point& point_, const dot& end_) : PrimitiveObject(point_), end_dot(end_) {}

void LinePrimitive::set_end(const dot& end_) {
    end_dot = end_;
}

void LinePrimitive::draw(std::shared_ptr<IPainter> painter) const {
    painter->drawLine(location, end_dot);
}


CirclePrimitive::CirclePrimitive(const point& point_, const int& radius_) : PrimitiveObject(point_), radius(radius_) {}

void CirclePrimitive::set_radius(const int& r_) {
    radius = r_;
}

void CirclePrimitive::draw(std::shared_ptr<IPainter> painter) const {
    painter->drawCircle(location, radius);
}
