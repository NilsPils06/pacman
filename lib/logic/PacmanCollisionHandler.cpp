#include "PacmanCollisionHandler.h"

#include "subject/Coin.h"
#include "subject/Wall.h"

#include <iostream>
void PacmanCollisionHandler::visit(const std::shared_ptr<const subjects::Wall>& e) {
    pacman->block();

    const Coords wall = e->getCoords();

    pacman->snapPosition(wall);
}
Coords PacmanCollisionHandler::getPacmanCoords() const {
    return pacman->getCoords();
}
void PacmanCollisionHandler::visit(std::shared_ptr<subjects::Coin> e) {
    e->setExpired();
}