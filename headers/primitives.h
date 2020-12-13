#pragma once

#include <iostream>
#include "../interfaces/iprimitive.h"


class PrimitiveObject : public IPrimitiveObject {
  public:
    void draw(std::shared_ptr<IPainter>) const override;
    void set_end(const dot&) override;
    void set_radius(const int&) override;

    PrimitiveObject(const point&);

    virtual ~PrimitiveObject() = default;

    void set_location(const point&);

  protected:
    point location;
};

class PointPrimitive : public PrimitiveObject {
  public:
    PointPrimitive(const point&);

    void draw(std::shared_ptr<IPainter>) const override;
};

class LinePrimitive : public PrimitiveObject {
  public:
    LinePrimitive(const point&, const dot&);

    void set_end(const dot&) override;

    void draw(std::shared_ptr<IPainter>) const override;

  private:
    dot end_dot;
};

class CirclePrimitive : public PrimitiveObject {
  public:
    CirclePrimitive(const point&, const int&);

    void set_radius(const int&) override;

    void draw(std::shared_ptr<IPainter>) const override;

  private:
    int radius = 0;
};
