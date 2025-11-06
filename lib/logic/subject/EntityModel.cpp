#include "EntityModel.h"
void subjects::EntityModel::setCoords(float x, float y) {
    coords.x = x;
    coords.y = y;
}
void subjects::EntityModel::setCoords(EntityCoords coords) {
    this->coords = coords;
}
void subjects::EntityModel::notify() {

}