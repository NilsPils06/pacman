#include "EntityModel.h"
void subjects::EntityModel::setCoords(float x, float y) {
    coords.x = x;
    coords.y = y;
}
void subjects::EntityModel::setCoords(EntityCoords coords) {
    this->coords = coords;
}
EntityCoords subjects::EntityModel::getCoords() const {
    return coords;
}
void subjects::EntityModel::notify(std::shared_ptr<Event> e) {
    for (const auto& o : observers) {
        if (const std::shared_ptr<Observer> observer = o.lock()) {
            observer->update(e);
        }
    }
}

subjects::EntityModel::EntityModel(const EntityCoords& coords) : coords(coords) {}
