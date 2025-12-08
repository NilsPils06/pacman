#include "Camera.h"

#include "Game.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

void Camera::project(sf::Sprite sprite, Coords coords) {
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
void Camera::showScore(int score) {
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("../../assets/PAC-FONT.TTF")) {
        // error...
    }
    text.setFont(font);
    text.setString("SCORE: " + std::to_string(score));
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::Yellow);

    // kyan cook
    const sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width, textRect.top + textRect.height);
    text.setPosition(static_cast<float>(Game::window.getSize().x) / 2,
                     static_cast<float>(Game::window.getSize().y) - 10);

    Game::window.draw(text);
}
