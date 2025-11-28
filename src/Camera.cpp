#include "Camera.h"

#include "Game.h"

std::unique_ptr<Camera> Camera::instance = nullptr;

Camera& Camera::getInstance() {
    if (instance == nullptr) {
        instance.reset(new Camera());
    }
    return *instance;
}

void Camera::project(sf::Sprite sprite, EntityCoords coords) {
    auto screensize = Game::window.getSize();
    const float x = (coords.x / 2.f + 0.5f) * screensize.x;
    const float y = (coords.y / 2.f + 0.5f) * screensize.y;

    const sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    sprite.setPosition(x, y);
    sprite.scale(1, 1);
    Game::window.draw(sprite);
}
