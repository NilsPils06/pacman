#include "EntityFactory.h"

#include "EntityView/Wall.h"
#include "Game.h"

std::shared_ptr<subjects::Wall> EntityFactory::createWall(EntityCoords coords) {
    std::shared_ptr<subjects::Wall> model = std::make_shared<subjects::Wall>(coords);
    std::shared_ptr<view::Wall> view = std::make_shared<view::Wall>(model);
    model->attach(view);
    view->setSprite(sprites::WALL);
    return model;
}
