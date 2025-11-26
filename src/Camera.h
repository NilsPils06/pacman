#ifndef PACMAN_CAMERA_H
#define PACMAN_CAMERA_H
#include "EntityView/EntityView.h"
#include "World.h"

class Camera {
    std::shared_ptr<sf::RenderWindow> window;
public:
    void projectEntity(std::shared_ptr<view::EntityView> entity, EntityCoords coords);
};

#endif // PACMAN_CAMERA_H
