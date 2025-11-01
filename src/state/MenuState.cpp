#include "MenuState.h"
#include "LevelState.h"
#include "StateManager.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

MenuState::~MenuState() = default;
void MenuState::onKeyPress(sf::Event::KeyEvent event) {
    if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
        state_manager->push(std::make_unique<LevelState>(state_manager));
    }
}
void MenuState::render(sf::RenderWindow& window) {
    sf::Texture texture;
    if (!texture.loadFromFile("../../assets/menu.png"))
        return;
    sf::Sprite sprite(texture);

    // Draw the sprite
    window.draw(sprite);
}