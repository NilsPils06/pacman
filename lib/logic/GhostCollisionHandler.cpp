#include "GhostCollisionHandler.h"

#include "Util.h"
#include "subject/Ghost.h"
#include "subject/Wall.h"
Coords GhostCollisionHandler::getGhostCoords() const {return ghost->getCoords();}
void GhostCollisionHandler::visit(const std::shared_ptr<const subjects::Wall>& e) {
    ghost->block();

    const Coords wall = e->getCoords();

    ghost->snapPosition(wall);
}