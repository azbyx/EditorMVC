#pragma once

#include "../interfaces/ifactory.h"

struct RegistryObjects;

class BaseFactory : public IFactory {

  public:

    BaseFactory() = default;
    virtual ~BaseFactory() = default;

    std::unique_ptr<IPrimitiveObject> create(const point&) const override;

    std::unique_ptr<IPrimitiveObject> create(const point&, const dot&) const override;

    std::unique_ptr<IPrimitiveObject> create(const point&, const int&) const override;
};

class PointFactory : public BaseFactory {
  public:
    PointFactory() = default;

    std::unique_ptr<IPrimitiveObject> create(const point&) const override;
};

class LineFactory : public BaseFactory {
  public:
    LineFactory() = default;

    std::unique_ptr<IPrimitiveObject> create(const point&, const dot&) const override;
};

class CircleFactory : public BaseFactory {
  public:
    CircleFactory() = default;

    std::unique_ptr<IPrimitiveObject> create(const point&, const int&) const override;
};
