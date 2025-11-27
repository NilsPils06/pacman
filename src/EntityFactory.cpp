#include "EntityFactory.h"

#include "EntityView/Wall.h"
#include "Game.h"

subjects::Ghost EntityFactory::createGhost(float x, float y) { return subjects::Ghost(CHASING); }
std::shared_ptr<subjects::Wall> EntityFactory::createWall(float x, float y) {
    std::shared_ptr<subjects::Wall> model = std::make_shared<subjects::Wall>(x, y);
    std::shared_ptr<view::Wall> view = std::make_shared<view::Wall>(model);
    model->attach(view);
    view->setSprite(sprites::GHOST_RED_RIGHT_1);
    return model;
}
subjects::Wall EntityFactory::createWall() { return {0, 0}; }
subjects::Coin EntityFactory::createCoin() { return {}; }
subjects::Fruit EntityFactory::createFruit() { return {}; }
subjects::Pacman EntityFactory::createPacman() { return {}; }
subjects::Ghost EntityFactory::createGhost() { return subjects::Ghost(CHASING); }
