#include "LevelState.h"

#include "../Camera.h"
#include "../EntityFactory.h"
#include "../Game.h"
#include "PausedState.h"
#include "StateManager.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <fstream>
LevelState::LevelState(const std::shared_ptr<StateManager>& manager) : State(manager) {
    factory = std::make_shared<EntityFactory>();
    world = std::make_shared<World>(factory);
}

void LevelState::onKeyPress(sf::Event::KeyEvent event) {
    if (event.code == sf::Keyboard::Escape) {
        if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
            state_manager->push(std::make_unique<PausedState>(state_manager));
        }
    }
}
void LevelState::render() {
    world->render();

    sf::Text text;

    sf::Font font;
    if (!font.loadFromFile("../../assets/PAC-FONT.TTF"))
    {
        // error...
    }

    // TODO center text correctly

    text.setFont(font);

    text.setString("Level");
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(64);

    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    sf::Vector2u size = Game::window.getSize();
    text.setPosition(static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 2.f);

    Game::window.draw(text);

    sf::Sprite sprite;

    sf::Texture texture;
    if (!texture.loadFromFile("../../assets/sprite.png")) {
        text.setString("nah");
        Game::window.draw(text);
        return;
    }
    sprite.setTexture(texture);

    sprite.setTextureRect(sprites::GHOST_RED_RIGHT_1);

    Camera::getInstance().project(sprite, {-1,-1});
}
