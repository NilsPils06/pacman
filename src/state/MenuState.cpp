#include "MenuState.h"
#include "../Game.h"
#include "LevelState.h"
#include "StateManager.h"

#include <SFML/Graphics/Text.hpp>

MenuState::~MenuState() = default;
void MenuState::onKeyPress(sf::Event::KeyEvent event) {
    if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
        state_manager->push(std::make_unique<LevelState>(state_manager));
    }
}
void MenuState::render() {
    sf::Text text;

    sf::Font font;
    if (!font.loadFromFile("../../assets/PAC-FONT.TTF"))
    {
        // error...
    }

    text.setFont(font);

    text.setString("pac-man\n\t1234");
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(128);

    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    sf::Vector2u size = Game::window.getSize();
    text.setPosition(static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 2.f);

    Game::window.draw(text);
}