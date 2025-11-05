#include "LevelState.h"

#include "PausedState.h"
#include "StateManager.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
void LevelState::onKeyPress(sf::Event::KeyEvent event) {
    if (event.code == sf::Keyboard::Escape) {
        if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
            state_manager->push(std::make_unique<PausedState>(state_manager));
        }
    }
}
void LevelState::render(std::shared_ptr<sf::RenderWindow> window) {
    sf::Texture texture;
    if (!texture.loadFromFile("../../assets/sprite.png"))
        return;
    sf::Sprite sprite(texture);

    // Draw the sprite
    window->draw(sprite);
}