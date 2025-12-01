#include "EntityModel.h"
void subjects::EntityModel::setCoords(Coords coords) {
    this->coords = coords;
}
Coords subjects::EntityModel::getCoords() const {
    return coords;
}
void subjects::EntityModel::notify(std::shared_ptr<Event> e) {
    for (const auto& observer : observers) {
        observer->update(e);
    }
}

subjects::EntityModel::EntityModel(const Coords& coords) : coords(coords) {}
