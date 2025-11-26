#include "Camera.h"

#include "Game.h"

Camera& Camera::getInstance() {
    static Camera instance;
    return instance;
}

void Camera::project(sf::Sprite sprite, EntityCoords coords) {
    auto screensize = Game::window.getSize();
    unsigned int x = (coords.x/2 + 0.5) + screensize.x;
    unsigned int y = (coords.y/2 + 0.5) + screensize.y;

    sprite.setPosition(x, y);
    sprite.scale(50,50);
    Game::window.draw(sprite);
}
