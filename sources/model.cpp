#include "model.h"

void Model::newModel() {
    keeperObjects.clear();
}

void Model::saveModel() {
    //TODO serialize and save to file
}

void Model::openModel(std::string&) {
    keeperObjects.clear();
    //TODO load and deserialize from file
}

void Model::addPoint(const Point& location) {
    keeperObjects.push_back(factoryObjects.makeObjects[typePrimitive::POINT]->create(location));
}

void Model::addLine(const Point& location, const Point& end_dot) {
    keeperObjects.push_back(factoryObjects.makeObjects[typePrimitive::LINE]->create(location, end_dot));
}

void Model::addCircle(const Point& location, const int& radius) {
    keeperObjects.push_back(factoryObjects.makeObjects[typePrimitive::CIRCLE]->create(location, radius));
}

void Model::removeLast() {
    if(!keeperObjects.empty())
        keeperObjects.pop_back();
}

void Model::draw(IPainterSptr painter) const {
    painter->drawDelimeter("top_of_screen");
    if(keeperObjects.empty())
        painter->drawText("Nothing to draw");
    else
        for(auto& object : keeperObjects) {
            object->draw(painter);
        }
    painter->drawDelimeter("bottom_of__screen");
}
