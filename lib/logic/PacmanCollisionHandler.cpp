#include "PacmanCollisionHandler.h"

#include "Event.h"
#include "subject/Coin.h"
#include "subject/Fruit.h"
#include "subject/Wall.h"
void PacmanCollisionHandler::visit(const std::shared_ptr<const subjects::Wall>& e) {
    pacman->block();

    const Coords wall = e->getCoords();

    pacman->snapPosition(wall);
}
Coords PacmanCollisionHandler::getPacmanCoords() const { return pacman->getCoords(); }
bool PacmanCollisionHandler::isDead() const { return pacman->getLives() <= 0; }
int PacmanCollisionHandler::getAmountOfCollections() {
    const int out = amountOfCollections;
    amountOfCollections = 0;
    return out;
}
int PacmanCollisionHandler::getLives() const { return pacman->getLives();}
bool PacmanCollisionHandler::isDying() const {return pacman->isDying(); }
void PacmanCollisionHandler::tick() const {
    pacman->tick();
}
void PacmanCollisionHandler::visit(std::shared_ptr<subjects::Coin> e) {
    ++amountOfCollections;
    pacman->notify(std::make_shared<CollectEvent>(e));
    e->setExpired();
}
void PacmanCollisionHandler::visit(std::shared_ptr<subjects::Fruit> e) {
    ++amountOfCollections;
    pacman->notify(std::make_shared<CollectEvent>(e));
    e->setExpired();
}
void PacmanCollisionHandler::visit(std::shared_ptr<subjects::Ghost> e) { pacman->hurt(); }