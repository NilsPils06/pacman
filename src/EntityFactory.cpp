#include "EntityFactory.h"

#include "EntityView/Coin.h"
#include "EntityView/Fruit.h"
#include "EntityView/Pacman.h"
#include "EntityView/Wall.h"
#include "Game.h"

std::shared_ptr<subjects::Wall> EntityFactory::createWall(EntityCoords coords) {
    std::shared_ptr<subjects::Wall> model = std::make_shared<subjects::Wall>(coords);
    std::shared_ptr<view::Wall> view = std::make_shared<view::Wall>(model);
    model->attach(view);
    view->setSprite(sprites::WALL);
    return model;
}
std::shared_ptr<subjects::Pacman> EntityFactory::createPacman(EntityCoords coords) {
    std::shared_ptr<subjects::Pacman> model = std::make_shared<subjects::Pacman>(coords);
    std::shared_ptr<view::Pacman> view = std::make_shared<view::Pacman>(model);
    model->attach(view);
    view->setSprite(sprites::PACMAN_RIGHT_2);
    return model;
}
std::shared_ptr<subjects::Coin> EntityFactory::createCoin(EntityCoords coords) {
    std::shared_ptr<subjects::Coin> model = std::make_shared<subjects::Coin>(coords);
    std::shared_ptr<view::Coin> view = std::make_shared<view::Coin>(model);
    model->attach(view);
    view->setSprite(sprites::COIN);
    return model;
}
std::shared_ptr<subjects::Fruit> EntityFactory::createFruit(EntityCoords coords) {
    std::shared_ptr<subjects::Fruit> model = std::make_shared<subjects::Fruit>(coords);
    std::shared_ptr<view::Fruit> view = std::make_shared<view::Fruit>(model);
    model->attach(view);
    view->setSprite(sprites::FRUIT);
    return model;
}
