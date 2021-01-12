#include "primitives.h"


PrimitiveObject::PrimitiveObject(const Point& point_) : location{point_.x_coord, point_.y_coord} {}

void PrimitiveObject::draw(IPainterSptr) const {}

void PrimitiveObject::set_end(const Point&) {}

void PrimitiveObject::set_radius(const int&) {}

void PrimitiveObject::set_location(const Point& point_) {
    location = point_;
}


PointPrimitive::PointPrimitive(const Point& point_) : PrimitiveObject(point_) {}

void PointPrimitive::draw(IPainterSptr painter) const {
    painter->drawPoint(location);
}


LinePrimitive::LinePrimitive(const Point& point_, const Point& end_) : PrimitiveObject(point_), end_dot(end_) {}

void LinePrimitive::set_end(const Point& end_) {
    end_dot = end_;
}

void LinePrimitive::draw(IPainterSptr painter) const {
    painter->drawLine(location, end_dot);
}


CirclePrimitive::CirclePrimitive(const Point& point_, const int& radius_) : PrimitiveObject(point_), radius(radius_) {}

void CirclePrimitive::set_radius(const int& r_) {
    radius = r_;
}

void CirclePrimitive::draw(IPainterSptr painter) const {
    painter->drawCircle(location, radius);
}
