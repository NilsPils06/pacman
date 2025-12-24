#include "PacmanCollisionHandler.h"

#include "Event.h"
#include "subject/Coin.h"
#include "subject/Fruit.h"
#include "subject/Wall.h"
std::shared_ptr<subjects::Pacman> PacmanCollisionHandler::getPacman() const { return pacman; }
bool PacmanCollisionHandler::isDead() const { return pacman->getLives() <= 0; }
void PacmanCollisionHandler::visit(std::shared_ptr<subjects::Coin> e) {
    pacman->notify(std::make_shared<CollectEvent>(e));
    e->setExpired();
}
void PacmanCollisionHandler::visit(std::shared_ptr<subjects::Fruit> e) {
    pacman->notify(std::make_shared<CollectEvent>(e));
    e->setExpired();
}
void PacmanCollisionHandler::visit(std::shared_ptr<subjects::Ghost> e) { pacman->hurt(); }
void PacmanCollisionHandler::setWallValidator(const std::function<bool(const Coords&)>& function) const {
    pacman->setWallValidator(function);
}