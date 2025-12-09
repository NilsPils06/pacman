#ifndef PACMAN_CAMERA_H
#define PACMAN_CAMERA_H
#include "EntityView/EntityView.h"
#include "World.h"

#include <SFML/Graphics/Font.hpp>

class Camera {
public:
    static void init();

    static void project(sf::Sprite sprite, Coords coords);

    static void showScore(int score);
};

#endif // PACMAN_CAMERA_H
