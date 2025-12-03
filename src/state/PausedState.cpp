#include "PausedState.h"

#include "../Game.h"
#include "StateManager.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
void PausedState::onKeyPress(sf::Event::KeyEvent event) {
    if (event.code == sf::Keyboard::Escape) {
        if (const std::shared_ptr<StateManager> state_manager = manager.lock()) {
            state_manager->pop();
        }
    }
}
void PausedState::render() {
    sf::Text text;

    sf::Font font;
    if (!font.loadFromFile("../../assets/PAC-FONT.TTF"))
    {
        // error...
    }

    text.setFont(font);

    text.setString("Paused\n\t1234569\npress ESC to continue.");
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(64);

    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    sf::Vector2u size = Game::window.getSize();
    text.setPosition(static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 2.f);

    Game::window.draw(text);
}