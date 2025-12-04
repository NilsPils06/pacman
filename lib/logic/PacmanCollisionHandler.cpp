#include "PacmanCollisionHandler.h"

#include "subject/Wall.h"
void PacmanCollisionHandler::visit(const std::shared_ptr<const subjects::Wall>& e) {
    pacman->block();

    const Coords wall = e->getCoords();

    pacman->snapPosition(wall);
}
Coords PacmanCollisionHandler::getPacmanCoords() const {
    return pacman->getCoords();
}