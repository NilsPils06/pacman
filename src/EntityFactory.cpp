#include "EntityFactory.h"

#include "EntityView/Wall.h"
#include "Game.h"

subjects::Ghost EntityFactory::createGhost(float x, float y) { return subjects::Ghost(CHASING); }
subjects::Wall EntityFactory::createWall(float x, float y) {
    subjects::Wall model{x, y};
    view::Wall view{std::make_shared<subjects::Wall>(model)};
    model.attach(std::make_shared<view::Wall>(view));
    view.setSprite(sprites::GHOST_RED_RIGHT_1);
    return model;
}
subjects::Wall EntityFactory::createWall() { return {0, 0}; }
subjects::Coin EntityFactory::createCoin() { return {}; }
subjects::Fruit EntityFactory::createFruit() { return {}; }
subjects::Pacman EntityFactory::createPacman() { return {}; }
subjects::Ghost EntityFactory::createGhost() { return subjects::Ghost(CHASING); }
