#ifndef PACMAN_CAMERA_H
#define PACMAN_CAMERA_H
#include "EntityView/EntityView.h"
#include "World.h"

class Camera {
public:
    /**
     * @brief Projects an entity to the screen.
     * @param sprite the sprite to use for projection.
     * @param coords the in-game coordinates of where the entity is located.
     */
    static void project(sf::Sprite& sprite, const Coords& coords);

    /**
     * @brief Displays the score in the bottom left of the screen.
     * @param score
     */
    static void showScore(int score);

    /**
     * @brief Displays the lives in the bottom right of the screen.
     * @param lives
     */
    static void showLives(int lives);
};

#endif // PACMAN_CAMERA_H
