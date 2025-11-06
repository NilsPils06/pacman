#include "MenuState.h"
#include "LevelState.h"
#include "StateManager.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>

MenuState::~MenuState() = default;
void MenuState::onKeyPress(sf::Event::KeyEvent event) {
    if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
        state_manager->push(std::make_unique<LevelState>(state_manager));
    }
}
void MenuState::render(std::shared_ptr<sf::RenderWindow> window) {
    sf::Text text;

    sf::Font font;
    if (!font.loadFromFile("../../assets/PAC-FONT.TTF"))
    {
        // error...
    }

    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("Pac-man");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    sf::Vector2u size = window->getSize();
    text.setPosition(size.x/2,size.y/2);

    // Draw the sprite
    window->draw(text);
}