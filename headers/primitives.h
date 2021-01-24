#pragma once

#include <iostream>
#include "iprimitive.h"


class PrimitiveObject : public IPrimitiveObject {
  public:
    void draw(std::shared_ptr<IPainter>) const override;
    void set_end(const Point&) override;
    void set_radius(const int&) override;

    PrimitiveObject(const Point&);

    virtual ~PrimitiveObject() = default;

    void set_location(const Point&);

  protected:
    Point location;
};

class PointPrimitive : public PrimitiveObject {
  public:
    PointPrimitive(const Point&);

    void draw(std::shared_ptr<IPainter>) const override;
};

class LinePrimitive : public PrimitiveObject {
  public:
    LinePrimitive(const Point&, const Point&);

    void set_end(const Point&) override;

    void draw(std::shared_ptr<IPainter>) const override;

  private:
    Point end_dot;
};

class CirclePrimitive : public PrimitiveObject {
  public:
    CirclePrimitive(const Point&, const int&);

    void set_radius(const int&) override;

    void draw(std::shared_ptr<IPainter>) const override;

  private:
    int radius = 0;
};
