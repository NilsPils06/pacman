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

    float cell_width = (coords.width / 2.f) * screensize.x;
    float cell_height = (coords.height / 2.f) * screensize.y;

    float center_x = screensize.x / 2.0f;
    float center_y = screensize.y / 2.0f;

    float offset_x = (screensize.x - cell_width) / 2.0f;
    float offset_y = (screensize.y - cell_height) / 2.0f;

    float x = center_x + (coords.x * offset_x);
    float y = center_y + (coords.y * offset_y);

    const sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    sprite.setPosition(x, y);
    sprite.setScale(cell_width / bounds.width, cell_height / bounds.height);

    Game::window.draw(sprite);
}
