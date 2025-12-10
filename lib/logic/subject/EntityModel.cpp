#include "EntityModel.h"
#include "../Score.h"

void subjects::EntityModel::setCoords(Coords coords) { this->coords = coords; }
Coords subjects::EntityModel::getCoords() const { return coords; }
void subjects::EntityModel::notify(std::shared_ptr<Event> e) {
    for (const auto& observer : observers) {
        observer->update(e);
    }
}
bool subjects::EntityModel::isExpired() const { return expired; }
void subjects::EntityModel::setExpired() { expired = true; }

subjects::EntityModel::EntityModel(const Coords& coords) : coords(coords) {}
