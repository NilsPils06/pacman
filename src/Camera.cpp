#include "Camera.h"

void Camera::projectEntity(std::shared_ptr<view::EntityView> entity, EntityCoords coords) {
    auto screensize = window->getSize();
    unsigned int x = (coords.x/2 + 0.5) + screensize.x;
    unsigned int y = (coords.y/2 + 0.5) + screensize.y;

    entity->setPosition(x, y);
    window->draw(entity->getSprite());
}
