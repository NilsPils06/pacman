#include "EntityModel.h"
#include "../Score.h"

void subjects::EntityModel::setCoords(const Coords c) { coords = c; }
Coords subjects::EntityModel::getCoords() const { return coords; }
void subjects::EntityModel::notify(const std::shared_ptr<Event> e) {
    for (const auto& observer : observers) {
        observer->update(e);
    }
}
bool subjects::EntityModel::isExpired() const { return expired; }
void subjects::EntityModel::setExpired() { expired = true; }

subjects::EntityModel::EntityModel(const Coords& coords) : coords(coords) {}
