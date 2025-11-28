#ifndef PACMAN_CAMERA_H
#define PACMAN_CAMERA_H
#include "EntityView/EntityView.h"
#include "World.h"

class Camera {
public:
    static void project(sf::Sprite sprite, EntityCoords coords);
};

#endif // PACMAN_CAMERA_H
