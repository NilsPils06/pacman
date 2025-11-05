#include "EntityModel.h"
void subjects::EntityModel::setCoords(int x, int y) {
    coords.x = x;
    coords.y = y;
}
void subjects::EntityModel::setCoords(EntityCoords coords) {
    this->coords = coords;
}