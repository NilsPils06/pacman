#include "EntityFactory.h"
#include "EntityView/Ghost.h"
#include "EntityView/Pacman.h"
#include "Game.h"
#include "Random.h"

std::shared_ptr<subjects::Wall> EntityFactory::createWall(Coords coords) {
    auto model = std::make_shared<subjects::Wall>(coords);
    const auto view = std::make_shared<view::EntityView>(model);
    model->attach(view);
    view->setSprite(sprites::WALL);
    return model;
}
std::shared_ptr<subjects::Pacman> EntityFactory::createPacman(Coords coords) {
    auto model = std::make_shared<subjects::Pacman>(coords);
    const auto view = std::make_shared<view::Pacman>(model);
    model->attach(view);
    model->attach(score);
    score->setSubject(model);
    view->setSprite(sprites::PACMAN_RIGHT_2);
    return model;
}
std::shared_ptr<subjects::Coin> EntityFactory::createCoin(Coords coords) {
    auto model = std::make_shared<subjects::Coin>(coords);
    const auto view = std::make_shared<view::EntityView>(model);
    model->attach(view);
    view->setSprite(sprites::COIN);
    return model;
}
std::shared_ptr<subjects::Fruit> EntityFactory::createFruit(Coords coords) {
    auto model = std::make_shared<subjects::Fruit>(coords);
    const auto view = std::make_shared<view::EntityView>(model);
    model->attach(view);
    static std::vector fruitSprites = {sprites::FRUIT_1, sprites::FRUIT_2, sprites::FRUIT_3, sprites::FRUIT_4,
                                       sprites::FRUIT_5, sprites::FRUIT_6, sprites::FRUIT_7};
    view->setSprite(fruitSprites[Random::getInstance().getInt(static_cast<int>(fruitSprites.size() - 1))]);
    return model;
}
std::shared_ptr<subjects::Ghost> EntityFactory::createGhost(Coords coords) {
    auto model = std::make_shared<subjects::Ghost>(coords, ghostTypes.size());
    model->setMovementType(ghostTypes.top().second);
    const auto view = std::make_shared<view::Ghost>(model, ghostTypes.top().first);
    ghostTypes.pop();
    model->attach(view);
    view->setSprite(sprites::GHOST_RED_RIGHT_1);
    return model;
}
