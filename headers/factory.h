#pragma once

#include "ifactory.h"

struct RegistryObjects;

class BaseFactory : public IFactory {

  public:

    BaseFactory() = default;
    virtual ~BaseFactory() = default;

    std::unique_ptr<IPrimitiveObject> create(const Point&) const override;

    std::unique_ptr<IPrimitiveObject> create(const Point&, const Point&) const override;

    std::unique_ptr<IPrimitiveObject> create(const Point&, const int&) const override;
};

class PointFactory : public BaseFactory {
  public:
    PointFactory() = default;

    std::unique_ptr<IPrimitiveObject> create(const Point&) const override;
};

class LineFactory : public BaseFactory {
  public:
    LineFactory() = default;

    std::unique_ptr<IPrimitiveObject> create(const Point&, const Point&) const override;
};

class CircleFactory : public BaseFactory {
  public:
    CircleFactory() = default;

    std::unique_ptr<IPrimitiveObject> create(const Point&, const int&) const override;
};
