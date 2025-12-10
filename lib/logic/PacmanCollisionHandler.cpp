#include "PacmanCollisionHandler.h"

#include "Event.h"
#include "subject/Coin.h"
#include "subject/Fruit.h"
#include "subject/Wall.h"

#include <iostream>
void PacmanCollisionHandler::visit(const std::shared_ptr<const subjects::Wall>& e) {
    pacman->block();

    const Coords wall = e->getCoords();

    pacman->snapPosition(wall);
}
Coords PacmanCollisionHandler::getPacmanCoords() const { return pacman->getCoords(); }
void PacmanCollisionHandler::visit(std::shared_ptr<subjects::Coin> e) {
    pacman->notify(std::make_shared<CollectEvent>(e));
    e->setExpired();
}
void PacmanCollisionHandler::visit(std::shared_ptr<subjects::Fruit> e) {
    pacman->notify(std::make_shared<CollectEvent>(e));
    e->setExpired();
}