#pragma once

#include "../headers/factory.h"
#include <map>

struct RegistryObjects {
    using FactoryPrimitive = std::map<typePrimitive, std::unique_ptr<IFactory>>;

    RegistryObjects() {
        makeObjects[typePrimitive::POINT]  = std::make_unique<PointFactory>();
        makeObjects[typePrimitive::LINE]   = std::make_unique<LineFactory>();
        makeObjects[typePrimitive::CIRCLE] = std::make_unique<CircleFactory>();
    }

    void addRegistry(typePrimitive){}

    void removeRegistry(typePrimitive){}

    FactoryPrimitive makeObjects;
};

