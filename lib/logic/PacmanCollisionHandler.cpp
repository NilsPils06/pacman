#include "PacmanCollisionHandler.h"

#include "Event.h"
#include "subject/Coin.h"
#include "subject/Fruit.h"
#include "subject/Ghost.h"
std::shared_ptr<subjects::Pacman> PacmanCollisionHandler::getPacman() const { return pacman; }
bool PacmanCollisionHandler::isDead() const { return pacman->getLives() <= 0; }
void PacmanCollisionHandler::visit(const std::shared_ptr<subjects::Coin> e) {
    pacman->EntityModel::notify(std::make_shared<CollectEvent>(e->getPoints()));
    e->setExpired();
}
void PacmanCollisionHandler::visit(const std::shared_ptr<subjects::Fruit> e) {
    pacman->EntityModel::notify(std::make_shared<CollectEvent>(e->getPoints()));
    e->setExpired();
    ghostFearer();
}
void PacmanCollisionHandler::visit(const std::shared_ptr<subjects::Ghost> e) {
    if (e->isEaten()) {
        return;
    }

    if (e->inFear())
        pacman->EntityModel::notify(std::make_shared<CollectEvent>(e->collect()));
    else
        pacman->hurt();
}
void PacmanCollisionHandler::setWallValidator(const std::function<bool(const Coords&)>& function) const {
    pacman->setWallValidator(function);
}
void PacmanCollisionHandler::setGhostFearer(const std::function<void()>& ghost_fearer) { ghostFearer = ghost_fearer; }