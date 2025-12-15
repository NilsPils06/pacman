#include "VictoryState.h"

#include "../Game.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
void VictoryState::onKeyPress(sf::Event::KeyEvent event) {
    if (const std::shared_ptr<StateManager> state_manager = manager.lock()) {
        state_manager->pop();
    }
}
void VictoryState::render() {
    sf::Text text;

    text.setFont(Game::font);

    text.setString("Victory!");
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(128);

    const sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    const sf::Vector2u size = Game::window.getSize();
    text.setPosition(static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 2.f);

    Game::window.draw(text);
}