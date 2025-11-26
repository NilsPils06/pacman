#ifndef PACMAN_CAMERA_H
#define PACMAN_CAMERA_H
#include "EntityView/EntityView.h"
#include "World.h"

class Camera {
    Camera() = default;
public:
    static Camera& getInstance();

    void project(sf::Sprite sprite, EntityCoords coords);

    Camera(const Camera&) = delete;
    void operator=(const Camera&) = delete;
};

#endif // PACMAN_CAMERA_H
