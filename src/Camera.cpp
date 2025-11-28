#include "Camera.h"

#include "Game.h"

void Camera::project(sf::Sprite sprite, EntityCoords coords) {
    const auto screensize = Game::window.getSize();
    const auto screen_x = static_cast<float>(screensize.x);
    const auto screen_y = static_cast<float>(screensize.y);

    const float cell_width = (coords.width / 2.f) * screen_x;
    const float cell_height = (coords.height / 2.f) * screen_y;

    const float center_x = screen_x / 2.0f;
    const float center_y = screen_y / 2.0f;

    const float offset_x = (screen_x - cell_width) / 2.0f;
    const float offset_y = (screen_y - cell_height) / 2.0f;

    const float x = center_x + (coords.x * offset_x);
    const float y = center_y + (coords.y * offset_y);

    const sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    sprite.setPosition(x, y);
    sprite.setScale(cell_width / bounds.width, cell_height / bounds.height);

    Game::window.draw(sprite);
}
